#include "header/utility.h"


#ifdef PLATFORM_WEB
#include <emscripten/emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define GL_EGLEXT_PROTOTYPES
#endif

#include "gl_render.h"
#include "core.h"

#include <assert.h>

unsigned int vao;
GLR_Shader shader;

void loop(void);
void main_loop(unsigned int vao, GLR_Shader shader);

int main(void) {

    assert(core_initialize_all("My Little Rendering Library!", 1600, 1480) == CORE_INIT_SUCCESSFUL);

    shader = glr_create_shader("shaders/QuadWeb.txt");

    if (shader.compilation_success == NO_SHADER) {
        return -1;
    }

    float vertices[] = {
        0.5, 0.5, 0.0, 1.0, 0.0, 1.0, // TOP RIGHT
        0.5, -0.5, 0.0, 0.0, 1.0, 0.0, // BOTTOM RIGHT
        -0.5, -0.5, 0.0, 1.0, 1.0, 0.0, // BOTTOM LEFT
        -0.5, 0.5, 0.0, 0.0, 0.0, 1.0, //TOP LEFT
    };
    unsigned short indices[] = {
        0, 1, 2,
        3, 0, 2,
    };

    vao = glr_create_vertex_array();

    GLR_Buffer vbo = glr_create_buffer(BUFFER_ARRAY);
    glr_buffer_data(vbo, sizeof(vertices), vertices, USAGE_STATIC_DRAW);

    GLR_Buffer ebo = glr_create_buffer(BUFFER_INDEX);
    glr_buffer_data(ebo, sizeof(indices), indices, USAGE_STATIC_DRAW);
    
    GLR_VertexAttribute attribute = glr_create_vertex_attribute(0, 3, NO_NORMALIZE_ATTRIBUTE, ATTRIBUTE_TYPE_FLOAT, 6, (void*)0);
    GLR_VertexAttribute attribute2 = glr_create_vertex_attribute(1, 3, NO_NORMALIZE_ATTRIBUTE, ATTRIBUTE_TYPE_FLOAT, 6, (void*)(sizeof(float) * 3));

    glr_set_vertex_attribute(attribute);
    glr_enable_vertex_attribute(attribute);
    glr_set_vertex_attribute(attribute2);
    glr_enable_vertex_attribute(attribute2);

    glr_unbind_vertex_array();
    glr_unbind_buffer(vbo);
    glr_unbind_buffer(ebo);

    #ifdef PLATFORM_WEB
        emscripten_set_main_loop(loop, 0, 1);
    #elif PLATFORM_WINDOWS

    while (core_update_loop()) {
        if (core_is_key_pressed(KEY_ESCAPE)) core_end_loop();

        glr_clear(CLEAR_COLOR | CLEAR_DEPTH);
        glr_clear_color_rgb_u(DEFAULT_RGB_U_COLOR);

        glr_bind_vertex_array(vao);
        glr_use_program(shader);
        glr_draw_elements(DRAW_TYPE_TRIANGLES, 6, ATTRIBUTE_TYPE_UNSIGNED_SHORT, 0);
        glr_unbind_vertex_array();

        core_swap_buffers();
    }
    
    #endif

    glr_delete_vertex_shader(shader);
    glr_delete_fragment_shader(shader);
    glr_delete_program(shader);

    glr_delete_buffer(&vbo);
    glr_delete_buffer(&ebo);
    glr_delete_vertex_array(&vao);

    core_terminate();
    

    return 0;
}

void main_loop(unsigned int vao, GLR_Shader shader) {
    core_poll_events();

    if (core_is_key_pressed(KEY_ESCAPE)) core_end_loop();

    glr_clear(CLEAR_COLOR | CLEAR_DEPTH);
    glr_clear_color_rgb_u(DEFAULT_RGB_U_COLOR);
    glr_bind_vertex_array(vao);
    glr_use_program(shader);
    glr_draw_elements(DRAW_TYPE_TRIANGLES, 6, ATTRIBUTE_TYPE_UNSIGNED_SHORT, 0);
    glr_unbind_vertex_array();
    core_swap_buffers();
}

void loop(void) {
    main_loop(vao, shader);
}