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
#include <stdio.h>

static struct {
    GLFWwindow* window;
    int width, height;
    const char* title;
    int keys_list[GLFW_KEY_LAST];
} Core;

//  ----------------CALLBACKS FOR GLFW--------------------------
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Core.keys_list[key] = action;
}

void window_resize_callback(GLFWwindow* window, int new_width, int new_height) {
    if (Core.window == window) Core.width = new_width, Core.height = new_height;

    #ifdef DRACARYS_USE_OPENGL
    glViewport(0, 0, Core.width, Core.height);
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

    if (glfwInit() == GLFW_FALSE) {
        printf("GLFW UNABLE TO BE INITIALIZED.");
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
        printf("Unable to create window.");
        return DRACARYS_INIT_FAILURE;
    }

    glfwMakeContextCurrent(Core.window);

    #ifdef DRACARYS_USE_OPENGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Unable to load OpenGL.");
        return DRACARYS_INIT_FAILURE;
    }

    glViewport(0, 0, Core.width, Core.height);
    #endif

    glfwSetWindowSizeCallback(Core.window, window_resize_callback);
    glfwSetKeyCallback(Core.window, key_callback);


    printf("Core initialized successfully.\n");

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