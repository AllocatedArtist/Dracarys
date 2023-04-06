#include <glad/glad.h>
#include "../header/core.h"

#include <GLFW/glfw3.h>
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
    glViewport(0, 0, Core.width, Core.height);
}
// -----------------------------------------------------

int core_initialize_all(const char* title, int width, int height) {

    Core.title = title;
    Core.width = width;
    Core.height = height;

    if (glfwInit() == GLFW_FALSE) {
        printf("GLFW UNABLE TO BE INITIALIZED.");
        return CORE_INIT_FAILURE;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    Core.window = glfwCreateWindow(Core.width, Core.height, Core.title, NULL, NULL);
    if (Core.window == NULL) {
        glfwTerminate();
        printf("Unable to create window.");
        return CORE_INIT_FAILURE;
    }

    glfwMakeContextCurrent(Core.window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Unable to load OpenGL.");
        return CORE_INIT_FAILURE;
    }

    glfwSetWindowSizeCallback(Core.window, window_resize_callback);
    glfwSetKeyCallback(Core.window, key_callback);

    glViewport(0, 0, Core.width, Core.height);

    printf("Core initialized successfully.\n");

    return CORE_INIT_SUCCESSFUL;
}

int core_update_loop(void) {
    core_poll_events();
    return !glfwWindowShouldClose(Core.window);   
}

void core_end_loop(void) {
    glfwSetWindowShouldClose(Core.window, GLFW_TRUE);
}

void core_poll_events(void) {
    glfwPollEvents();
}

void core_swap_buffers(void) {
    glfwSwapBuffers(Core.window);
}

void core_terminate(void) {
    glfwDestroyWindow(Core.window);
    glfwTerminate();
}

int core_is_key_pressed(enum Keys key) {
    int result = Core.keys_list[(unsigned int)key] == GLFW_PRESS;
    Core.keys_list[(unsigned int)key] = GLFW_RELEASE;
    return result;
}

int core_is_key_down(enum Keys key) {
    return Core.keys_list[(unsigned int)key] == GLFW_PRESS;
}

int core_is_key_up(enum Keys key) {
    return Core.keys_list[(unsigned int)key] == GLFW_RELEASE;
}

int core_get_window_width(void) {
    return Core.width;
}

int core_get_window_height(void) {
    return Core.height;
}