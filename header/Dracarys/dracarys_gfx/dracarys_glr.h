#ifndef DRACARYS_GL_RENDER_H
#define DRACARYS_GL_RENDER_H

#define DRACARYS_YES_NORMALIZE_ATTRIBUTE 1
#define DRACARYS_NO_NORMALIZE_ATTRIBUTE 0

#define DRACARYS_INDEX_BUFFER_DRAW 1
#define DRACARYS_ARRAY_BUFFER_DRAW 0

#define DRACARYS_YES_SHADER 1
#define DRACARYS_NO_SHADER 0

enum dracarys_glr_clear_flags {
    DRACARYS_GLR_CLEAR_COLOR = 16384,
    DRACARYS_GLR_CLEAR_STENCIL = 1024,
    DRACARYS_GLR_CLEAR_DEPTH = 256,
};

enum dracarys_glr_buffer_type {
    DRACARYS_GLR_BUFFER_ARRAY = 34962,
    DRACARYS_GLR_BUFFER_INDEX,
};

enum dracarys_glr_usage_type {
    DRACARYS_GLR_USAGE_STREAM_DRAW = 35040,
    DRACARYS_GLR_USAGE_STREAM_READ,
    DRACARYS_GLR_USAGE_STREAM_COPY,
    DRACARYS_GLR_USAGE_STATIC_DRAW = 35044,
    DRACARYS_GLR_USAGE_STATIC_READ,
    DRACARYS_GLR_USAGE_STATIC_COPY,
    DRACARYS_GLR_USAGE_DYNAMIC_DRAW = 35048,
    DRACARYS_GLR_USAGE_DYNAMIC_READ,
    DRACARYS_GLR_USAGE_DYNAMIC_COPY,
};

enum dracarys_glr_attribute_type {
    DRACARYS_GLR_ATTRIBUTE_TYPE_BYTE = 5120,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_BYTE,
    DRACARYS_GLR_ATTRIBUTE_TYPE_SHORT,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_SHORT,
    DRACARYS_GLR_ATTRIBUTE_TYPE_INT,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_INT,
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT,
};

enum dracarys_glr_draw_type {
    DRACARYS_GLR_DRAW_TYPE_POINTS = 0,
    DRACARYS_GLR_DRAW_TYPE_LINES,
    DRACARYS_GLR_DRAW_TYPE_LINE_LOOP,
    DRACARYS_GLR_DRAW_TYPE_LINE_STRIP,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLES,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLE_STRIP,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLE_FAN,
    DRACARYS_GLR_DRAW_TYPE_QUADS,
};

typedef struct {
    unsigned int buffer;
    enum dracarys_glr_buffer_type type;
} dracarys_glr_buffer_t;

typedef struct {
    unsigned int index;
    int size;
    enum dracarys_glr_attribute_type type;
    int normalized;
    unsigned int stride;
    const void* pointer;
} dracarys_glr_vertex_attribute_t;

typedef struct {
    unsigned int vertex_shader;
    unsigned int fragment_shader;
    unsigned int shader_program;
    int compilation_success;
} dracarys_glr_shader_t;


void dracarys_glr_clear(enum dracarys_glr_clear_flags flags);
void dracarys_glr_clear_color_rgba_f(float r, float g, float b, float a);
void dracarys_glr_clear_color_rgb_f(float r, float g, float b);
void dracarys_glr_clear_color_rgba_u(unsigned char r, unsigned char g, unsigned char b, float a);
void dracarys_glr_clear_color_rgb_u(unsigned char r, unsigned char g, unsigned char b);

dracarys_glr_buffer_t dracarys_glr_buffer_create(enum dracarys_glr_buffer_type type);
void dracarys_glr_buffer_bind(dracarys_glr_buffer_t buffer);
void dracarys_glr_buffer_data(dracarys_glr_buffer_t buffer, signed long long size, const void* data, enum dracarys_glr_usage_type type);
void dracarys_glr_buffer_unbind(dracarys_glr_buffer_t buffer);
void dracarys_glr_buffer_delete(dracarys_glr_buffer_t* buffer);

unsigned int dracarys_glr_vertex_array_create(void);
void dracarys_glr_vertex_array_bind(unsigned int vao);
void dracarys_glr_vertex_array_unbind(void);
void dracarys_glr_vertex_array_delete(unsigned int* vao);

dracarys_glr_vertex_attribute_t dracarys_glr_vertex_attribute_create(unsigned int index, int size, int normalized, enum dracarys_glr_attribute_type type, unsigned int stride, const void* data);
void dracarys_glr_vertex_attribute_set(dracarys_glr_vertex_attribute_t attribute);
void dracarys_glr_vertex_attribute_enable(dracarys_glr_vertex_attribute_t attribute);
void dracarys_glr_vertex_attribute_disable(dracarys_glr_vertex_attribute_t attribute);

dracarys_glr_shader_t dracarys_glr_shader_create_empty(void);
int dracarys_glr_vertex_shader_create(dracarys_glr_shader_t shader, const char* data);
int dracarys_glr_fragment_shader_create(dracarys_glr_shader_t shader, const char* data);
int dracarys_glr_shader_complete(dracarys_glr_shader_t shader);
void dracarys_glr_shader_enable(dracarys_glr_shader_t shader);
void dracarys_glr_shader_disable(void);

void dracarys_glr_vertex_shader_delete(dracarys_glr_shader_t shader);
void dracarys_glr_fragment_shader_delete(dracarys_glr_shader_t shader);
void dracarys_glr_program_delete(dracarys_glr_shader_t shader);

dracarys_glr_shader_t dracarys_glr_shader_create_full(const char* shader_path);

void dracarys_glr_draw_arrays(enum dracarys_glr_draw_type type, unsigned int count);
void dracarys_glr_draw_elements(enum dracarys_glr_draw_type mode, unsigned int count, enum dracarys_glr_attribute_type type, const void* indices);
void dracarys_glr_viewport(int x, int y, int width, int height);

#endif