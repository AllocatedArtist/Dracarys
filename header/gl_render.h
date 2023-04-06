#ifndef GL_RENDER_H
#define GL_RENDER_H

#define YES_NORMALIZE_ATTRIBUTE 1
#define NO_NORMALIZE_ATTRIBUTE 0

#define INDEX_BUFFER_DRAW 1
#define ARRAY_BUFFER_DRAW 0

#define YES_SHADER 1
#define NO_SHADER 0

enum ClearFlags {
    CLEAR_COLOR = 16384,
    CLEAR_STENCIL = 1024,
    CLEAR_DEPTH = 256,
};

enum BufferType {
    BUFFER_ARRAY = 34962,
    BUFFER_INDEX,
};

enum UsageType {
    USAGE_STREAM_DRAW = 35040,
    USAGE_STREAM_READ,
    USAGE_STREAM_COPY,
    USAGE_STATIC_DRAW = 35044,
    USAGE_STATIC_READ,
    USAGE_STATIC_COPY,
    USAGE_DYNAMIC_DRAW = 35048,
    USAGE_DYNAMIC_READ,
    USAGE_DYNAMIC_COPY,
};

enum AttributeType {
    ATTRIBUTE_TYPE_BYTE = 5120,
    ATTRIBUTE_TYPE_UNSIGNED_BYTE,
    ATTRIBUTE_TYPE_SHORT,
    ATTRIBUTE_TYPE_UNSIGNED_SHORT,
    ATTRIBUTE_TYPE_INT,
    ATTRIBUTE_TYPE_UNSIGNED_INT,
    ATTRIBUTE_TYPE_FLOAT,
};

enum DrawType {
    DRAW_TYPE_POINTS = 0,
    DRAW_TYPE_LINES,
    DRAW_TYPE_LINE_LOOP,
    DRAW_TYPE_LINE_STRIP,
    DRAW_TYPE_TRIANGLES,
    DRAW_TYPE_TRIANGLE_STRIP,
    DRAW_TYPE_TRIANGLE_FAN,
    DRAW_TYPE_QUADS,
};

typedef struct {
    unsigned int buffer;
    enum BufferType type;
} GLR_Buffer;

typedef struct {
    unsigned int index;
    int size;
    enum AttributeType type;
    int normalized;
    unsigned int stride;
    const void* pointer;
} GLR_VertexAttribute;

typedef struct {
    unsigned int vertex_shader;
    unsigned int fragment_shader;
    unsigned int shader_program;
    int compilation_success;
} GLR_Shader;


void glr_clear(enum ClearFlags flags);
void glr_clear_color_rgba_f(float r, float g, float b, float a);
void glr_clear_color_rgb_f(float r, float g, float b);
void glr_clear_color_rgba_u(unsigned char r, unsigned char g, unsigned char b, float a);
void glr_clear_color_rgb_u(unsigned char r, unsigned char g, unsigned char b);

GLR_Buffer glr_create_buffer(enum BufferType type);
void glr_bind_buffer(GLR_Buffer buffer);
void glr_buffer_data(GLR_Buffer buffer, signed long long size, const void* data, enum UsageType type);
void glr_unbind_buffer(GLR_Buffer buffer);
void glr_delete_buffer(GLR_Buffer* buffer);

unsigned int glr_create_vertex_array(void);
void glr_bind_vertex_array(unsigned int vao);
void glr_unbind_vertex_array(void);
void glr_delete_vertex_array(unsigned int* vao);

GLR_VertexAttribute glr_create_vertex_attribute(unsigned int index, int size, int normalized, enum AttributeType type, unsigned int stride, const void* data);
void glr_set_vertex_attribute(GLR_VertexAttribute attribute);
void glr_enable_vertex_attribute(GLR_VertexAttribute attribute);
void glr_disable_vertex_attribute(GLR_VertexAttribute attribute);

GLR_Shader glr_create_empty_shader(void);
int glr_vertex_shader(GLR_Shader shader, const char* data);
int glr_fragment_shader(GLR_Shader shader, const char* data);
int glr_complete_shader(GLR_Shader shader);
void glr_use_program(GLR_Shader shader);
void glr_disable_program(void);

void glr_delete_vertex_shader(GLR_Shader shader);
void glr_delete_fragment_shader(GLR_Shader shader);
void glr_delete_program(GLR_Shader shader);

GLR_Shader glr_create_shader(const char* shader_path);

void glr_draw_arrays(enum DrawType type, unsigned int count);
void glr_draw_elements(enum DrawType mode, unsigned int count, enum AttributeType type, const void* indices);

#endif