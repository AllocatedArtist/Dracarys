#include "../header/Dracarys/dracarys.h"

#if defined(DRACARYS_PLATFORM_WEB) && defined(DRACARYS_USE_OPENGL)
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#define GL_GLEXT_PROTOTYPES
#define GL_EGLEXT_PROTOTYPES
#elif defined(DRACARYS_PLATFORM_WEB) && !defined(DRACARYS_USE_OPENGL)
#error CANNOT BUILD FOR WEB WITHOUT OPENGL
#endif

#if defined(DRACARYS_USE_OPENGL)
#include "../header/Dracarys/extern/glad/glad.h"
#else
#error CHOOSE GRAPHICS API: DRACARYS_USE_OPENGL
#endif

#include "../header/Dracarys/extern/GLFW/glfw3.h"

static struct {
    GLFWwindow* window;
    int width, height;
    const char* title;
    int keys_list[GLFW_KEY_LAST];
    FILE* log_file;
} Core;

//  ----------------CALLBACKS FOR GLFW--------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        Core.keys_list[key] = action;
    } else if (action == GLFW_RELEASE) {
        Core.keys_list[key] = action;
    }
}

void window_resize_callback(GLFWwindow* window, int new_width, int new_height) {
    if (Core.window == window) Core.width = new_width, Core.height = new_height;

    #ifdef DRACARYS_USE_OPENGL
    dracarys_glr_viewport(0, 0, Core.width, Core.height);
    #endif

    #if defined(PLATFORM_WEB) && defined(DRACARYS_USE_OPENGL)
        emscripten_set_canvas_element_size("#canvas", Core.width, Core.height);
    #endif
    
}
// -----------------------------------------------------

int dracarys_platform_initialize(const char* title, int width, int height) {

    Core.title = title;
    Core.width = width;
    Core.height = height;

    #if defined(DRACARYS_LOG_WRITE) && defined(DRACARYS_PLATFORM_WINDOWS)
    Core.log_file = fopen("dracarys_log.txt", "w");
    if (Core.log_file == NULL) {
        DRACARYS_UTILITY_LOG_ERROR("UNABLE TO CREATE/OPEN LOG FILE\n");
    } else {
        if (DRACARYS_UTILITY_LOG_SET_FILE(Core.log_file, DRACARYS_UTILITY_LOG_TRACE_LEVEL) < 0) {
            DRACARYS_UTILITY_LOG_ERROR("UNABLE TO SET LOG FILE CALLBACK\n");
            fclose(Core.log_file);
            Core.log_file = NULL;
        } else {
            DRACARYS_UTILITY_LOG_INFO("Dracarys log file set\n");
        }
    }
    #elif defined(DRACARYS_PLATFORM_WEB)
    Core.log_file = NULL;
    #endif

    if (glfwInit() == GLFW_FALSE) {
        DRACARYS_UTILITY_LOG_ERROR("GLFW UNABLE TO INITIALIZE\n");
        return DRACARYS_INIT_FAILURE;
    }

    #ifdef DRACARYS_USE_OPENGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    #endif 

    Core.window = glfwCreateWindow(Core.width, Core.height, Core.title, NULL, NULL);
    if (Core.window == NULL) {
        glfwTerminate();
        DRACARYS_UTILITY_LOG_ERROR("WINDOW NOT ABLE TO BE CREATED\n");
        return DRACARYS_INIT_FAILURE;
    }

    glfwMakeContextCurrent(Core.window);

    #if defined(DRACARYS_USE_OPENGL)
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        DRACARYS_UTILITY_LOG_ERROR("GLAD NOT LOADED\n");
        return DRACARYS_INIT_FAILURE;
    }
    
    dracarys_glr_viewport(0, 0, Core.width, Core.height);

    dracarys_utility_image_set_flip_on_load(DRACARYS_YES_FLIP_IMAGE);
    #endif

    glfwSetWindowSizeCallback(Core.window, window_resize_callback);
    glfwSetKeyCallback(Core.window, key_callback);


    DRACARYS_UTILITY_LOG_INFO("Dracarys initialized successfully\n");

    return DRACARYS_INIT_SUCCESSFUL;
}

int dracarys_platform_update(void) {
    dracarys_platform_poll_events();
    return !glfwWindowShouldClose(Core.window);   
}

void dracarys_platform_end_update(void) {
    glfwSetWindowShouldClose(Core.window, GLFW_TRUE);
}

int dracarys_platform_get_window_status(void) {
    return glfwWindowShouldClose(Core.window) ? DRACARYS_WINDOW_CLOSED : DRACARYS_WINDOW_RUNNING;
}

void dracarys_platform_poll_events(void) {
    glfwPollEvents();
}

void dracarys_platform_swap_buffers(void) {
    glfwSwapBuffers(Core.window);
}

void dracarys_platform_terminate(void) {
    glfwDestroyWindow(Core.window);
    glfwTerminate();

    if (Core.log_file != NULL) fclose(Core.log_file);
}

int dracarys_platform_is_key_pressed(enum dracarys_keys key) {
    int result = Core.keys_list[(unsigned int)key] == GLFW_PRESS;
    Core.keys_list[(unsigned int)key] = GLFW_RELEASE;
    return result;
}

int dracarys_platform_is_key_down(enum dracarys_keys key) {
    return Core.keys_list[(unsigned int)key] == GLFW_PRESS;
}

int dracarys_platform_is_key_up(enum dracarys_keys key) {
    return Core.keys_list[(unsigned int)key] == GLFW_RELEASE;
}

int dracarys_platform_get_window_width(void) {
    return Core.width;
}

int dracarys_platform_get_window_height(void) {
    return Core.height;
}

double dracarys_platform_time_since_initialize(void) {
    return glfwGetTime();
}