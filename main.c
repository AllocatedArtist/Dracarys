#include "header/Dracarys/dracarys.h"

#include <math.h>

typedef struct {
    unsigned int vao;
    dracarys_glr_buffer_t vbo;
    dracarys_glr_buffer_t ebo;

    dracarys_glr_shader_t shader;

    dracarys_glr_vertex_attribute_t attribute_0;
    dracarys_glr_vertex_attribute_t attribute_1;
    dracarys_glr_vertex_attribute_t attribute_2;

    int offset_pos_loc;
    int texture0_loc;
    int texture1_loc;

    float x, y;

    dracarys_glr_texture_t texture;
    dracarys_glr_texture_t texture2;

    float last_time;
} hello_triangle_t;

void init(hello_triangle_t* example);
void update(hello_triangle_t* example);
void end(hello_triangle_t* example);

void init(hello_triangle_t* example) {

    example->shader = dracarys_glr_shader_create_full("shaders/QuadWeb.txt");

    example->offset_pos_loc = dracarys_glr_uniform_location(example->shader, "offset_pos");
    example->texture0_loc = dracarys_glr_uniform_location(example->shader, "texture0");
    example->texture1_loc = dracarys_glr_uniform_location(example->shader, "texture1");

    dracarys_glr_texture_param_t params[] = DRACARYS_TEXTURE_DEFAULT_PARAMETERS(DRACARYS_GLR_TEXTURE_TYPE_2D);
    example->texture = dracarys_glr_texture_create_full("res/scales_texture.jpg", DRACARYS_GLR_TEXTURE_TYPE_2D, params, 0, DRACARYS_YES_MIPMAP, 0);

    example->texture2 = dracarys_glr_texture_create_full("res/dragon.png", DRACARYS_GLR_TEXTURE_TYPE_2D, params, 0, DRACARYS_YES_MIPMAP, 0);

    if (example->texture.success == DRACARYS_TEXTURE_UNSUCCESSFUL || example->texture2.success == DRACARYS_TEXTURE_UNSUCCESSFUL) {
        dracarys_platform_end_update();
    }

    example->attribute_0 = dracarys_glr_vertex_attribute_create(0, 3, DRACARYS_NO_NORMALIZE_ATTRIBUTE, 
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT, 8, 
    (void*)0);
    example->attribute_1 = dracarys_glr_vertex_attribute_create(1, 3, DRACARYS_NO_NORMALIZE_ATTRIBUTE, 
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT, 8, 
    (void*)(sizeof(float) * 3));
    example->attribute_2 = dracarys_glr_vertex_attribute_create(2, 2, DRACARYS_NO_NORMALIZE_ATTRIBUTE, 
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT, 8, 
    (void*)(sizeof(float) * 6));

    float triangle[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

   unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    example->vao = dracarys_glr_vertex_array_create();
    example->vbo = dracarys_glr_buffer_create(DRACARYS_GLR_BUFFER_ARRAY);
    example->ebo = dracarys_glr_buffer_create(DRACARYS_GLR_BUFFER_INDEX);
   
    dracarys_glr_buffer_data(example->vbo, sizeof(triangle), triangle, DRACARYS_GLR_USAGE_STATIC_DRAW);
    dracarys_glr_buffer_data(example->ebo, sizeof(indices), indices, DRACARYS_GLR_USAGE_STATIC_DRAW);

    dracarys_glr_vertex_attribute_set(example->attribute_0);
    dracarys_glr_vertex_attribute_enable(example->attribute_0);
    dracarys_glr_vertex_attribute_set(example->attribute_1);
    dracarys_glr_vertex_attribute_enable(example->attribute_1);
    dracarys_glr_vertex_attribute_set(example->attribute_2);
    dracarys_glr_vertex_attribute_enable(example->attribute_2);
    
    dracarys_glr_vertex_array_unbind();
    dracarys_glr_buffer_unbind(example->vbo);
    dracarys_glr_buffer_unbind(example->ebo);
    
    example->x = 0;
    example->y = 0;
   
   example->last_time = 0.0;
}

void update(hello_triangle_t* example) {
    dracarys_glr_clear(DRACARYS_GLR_CLEAR_COLOR);
    dracarys_glr_clear_color_rgb_u(0, 145, 255);

    float current_time = dracarys_platform_time_since_initialize();
    float delta = current_time - example->last_time;
    example->last_time = current_time;

    if (dracarys_platform_is_key_pressed(DRACARYS_KEY_ESCAPE)) {
        dracarys_platform_end_update();
    }
    if (dracarys_platform_is_key_down(DRACARYS_KEY_A) > 0) {
        example->x -= 1.0 * delta;
    }
    if (dracarys_platform_is_key_down(DRACARYS_KEY_D)) {
        example->x += 1.0 * delta;
    }
    if (dracarys_platform_is_key_down(DRACARYS_KEY_W)) {
        example->y += 1.0 * delta;
    }
     if (dracarys_platform_is_key_down(DRACARYS_KEY_S)) {
        example->y -= 1.0 * delta;
    }

     //DRACARYS_UTILITY_LOG_TRACE("Delta time: %f, x: %.2f, y: %.2f", delta, example->x, example->y);

    dracarys_glr_texture_active_sampler(DRACARYS_GLR_TEXTURE0);
    dracarys_glr_texture_bind(example->texture);
    dracarys_glr_texture_active_sampler(DRACARYS_GLR_TEXTURE1);
    dracarys_glr_texture_bind(example->texture2);

    dracarys_glr_vertex_array_bind(example->vao);
    dracarys_glr_shader_enable(example->shader); 

    dracarys_glr_uniform_i(example->texture0_loc, 0);
    dracarys_glr_uniform_i(example->texture1_loc, 1);

    dracarys_glr_uniform_f2(example->offset_pos_loc, example->x, example->y);
    dracarys_glr_draw_elements(DRACARYS_GLR_DRAW_TYPE_TRIANGLES, 6, DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_INT, 0);
    dracarys_glr_shader_disable();
    dracarys_glr_vertex_array_unbind();
}

void end(hello_triangle_t* example) {
    dracarys_glr_texture_delete(&example->texture);
    dracarys_glr_texture_delete(&example->texture2);

    dracarys_glr_vertex_array_delete(&example->vao);
    dracarys_glr_buffer_delete(&example->vbo);
    dracarys_glr_buffer_delete(&example->ebo);
   
    dracarys_glr_vertex_shader_delete(example->shader);
    dracarys_glr_fragment_shader_delete(example->shader);
    dracarys_glr_program_delete(example->shader);
}


DRACARYS_GAME(init, update, end, hello_triangle_t, "Dracarys Triangle Example", 600, 600)