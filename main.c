#include "header/Dracarys/dracarys.h"

typedef struct {
    dracarys_glr_buffer_t vbo;
    unsigned int vao;
    dracarys_glr_shader_t shader;
    dracarys_glr_vertex_attribute_t attribute_0;
} hello_triangle_t;

void init(hello_triangle_t* example);
void update(hello_triangle_t* example);
void end(hello_triangle_t* example);

void init(hello_triangle_t* example) {
    example->attribute_0 = dracarys_glr_vertex_attribute_create(0, 3, DRACARYS_NO_NORMALIZE_ATTRIBUTE, 
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT, 3, 
    (void*)0);

    example->shader = dracarys_glr_shader_create_full("shaders/QuadWeb.txt");

    float triangle[] = {
        0.0, 0.5, 0.0,
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
    };

    example->vao = dracarys_glr_vertex_array_create();
    example->vbo = dracarys_glr_buffer_create(DRACARYS_GLR_BUFFER_ARRAY);
    dracarys_glr_buffer_data(example->vbo, sizeof(triangle), triangle, DRACARYS_GLR_USAGE_STATIC_DRAW);
    dracarys_glr_vertex_attribute_set(example->attribute_0);
    dracarys_glr_vertex_attribute_enable(example->attribute_0);
    
    dracarys_glr_vertex_array_unbind();
    dracarys_glr_buffer_unbind(example->vbo);
}

void update(hello_triangle_t* example) {
    dracarys_glr_clear(DRACARYS_GLR_CLEAR_COLOR);
    dracarys_glr_clear_color_rgb_u(0, 145, 255);

    if (dracarys_platform_is_key_pressed(DRACARYS_KEY_ESCAPE)) {
        dracarys_platform_end_update();
    }

    dracarys_glr_vertex_array_bind(example->vao);
    dracarys_glr_shader_enable(example->shader);
    dracarys_glr_draw_arrays(DRACARYS_GLR_DRAW_TYPE_TRIANGLES, 3);
    dracarys_glr_shader_disable();
    dracarys_glr_vertex_array_unbind();
}

void end(hello_triangle_t* example) {
    printf("App terminated.\n");
    dracarys_glr_vertex_array_delete(&example->vao);
    dracarys_glr_buffer_delete(&example->vbo);
    dracarys_glr_vertex_shader_delete(example->shader);
    dracarys_glr_fragment_shader_delete(example->shader);
    dracarys_glr_program_delete(example->shader);
}


DRACARYS_GAME(init, update, end, hello_triangle_t, "Dracarys Triangle Example", 900, 600)