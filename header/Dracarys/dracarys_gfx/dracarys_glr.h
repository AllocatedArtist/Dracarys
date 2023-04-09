#ifndef DRACARYS_GL_RENDER_H
#define DRACARYS_GL_RENDER_H

#define DRACARYS_YES_NORMALIZE_ATTRIBUTE 1
#define DRACARYS_NO_NORMALIZE_ATTRIBUTE 0

#define DRACARYS_INDEX_BUFFER_DRAW 1
#define DRACARYS_ARRAY_BUFFER_DRAW 0

#define DRACARYS_YES_SHADER 1
#define DRACARYS_NO_SHADER 0

#define DRACARYS_UNIFORM_NO_LOCATION -1

#define DRACARYS_TEXTURE_PARAMETER_I 1
#define DRACARYS_TEXTURE_PARAMETER_FV 0

#define DRACARYS_TEXTURE_SUCCESSFUL 1
#define DRACARYS_TEXTURE_UNSUCCESSFUL 0

#define DRACARYS_YES_MIPMAP 1
#define DRACARYS_NO_MIPMAP 0


enum dracarys_glr_clear_flags {
    DRACARYS_GLR_CLEAR_DEPTH = 0x00000100,
    DRACARYS_GLR_CLEAR_STENCIL = 0x00000400,
    DRACARYS_GLR_CLEAR_COLOR = 0x00004000,
};

enum dracarys_glr_buffer_type {
    DRACARYS_GLR_BUFFER_ARRAY = 0x8892,
    DRACARYS_GLR_BUFFER_INDEX = 0x8893,
};

enum dracarys_glr_usage_type {
    DRACARYS_GLR_USAGE_STREAM_DRAW = 0x88E0,
    DRACARYS_GLR_USAGE_STREAM_READ = 0x88E1,
    DRACARYS_GLR_USAGE_STREAM_COPY = 0x88E2,
    DRACARYS_GLR_USAGE_STATIC_DRAW = 0x88E4,
    DRACARYS_GLR_USAGE_STATIC_READ = 0x88E5,
    DRACARYS_GLR_USAGE_STATIC_COPY = 0x88E6,
    DRACARYS_GLR_USAGE_DYNAMIC_DRAW = 0x88E8,
    DRACARYS_GLR_USAGE_DYNAMIC_READ = 0x88E9,
    DRACARYS_GLR_USAGE_DYNAMIC_COPY = 0x88EA,
};

enum dracarys_glr_attribute_type {
    DRACARYS_GLR_ATTRIBUTE_TYPE_BYTE = 0x1400,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_BYTE = 0x1401,
    DRACARYS_GLR_ATTRIBUTE_TYPE_SHORT = 0x1402,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_SHORT = 0x1403,
    DRACARYS_GLR_ATTRIBUTE_TYPE_INT = 0x1404,
    DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_INT = 0x1405,
    DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT = 0x1406,
    DRACARYS_GLR_ATTRIBUTE_TYPE_DOUBLE = 0x140A,
};

enum dracarys_glr_draw_type {
    DRACARYS_GLR_DRAW_TYPE_POINTS = 0x0000,
    DRACARYS_GLR_DRAW_TYPE_LINES = 0x0001,
    DRACARYS_GLR_DRAW_TYPE_LINE_LOOP = 0x0002,
    DRACARYS_GLR_DRAW_TYPE_LINE_STRIP = 0x0003,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLES = 0x0004,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLE_STRIP = 0x0005,
    DRACARYS_GLR_DRAW_TYPE_TRIANGLE_FAN = 0x0006,
    DRACARYS_GLR_DRAW_TYPE_QUADS = 0x0007,
};

enum dracarys_glr_texture_pname {
    DRACARYS_GLR_TEXTURE_BORDER_COLOR = 0x1004,
    DRACARYS_GLR_MAG_FILTER = 0x2800,
    DRACARYS_GLR_MIN_FILTER = 0x2801,
    DRACARYS_GLR_WRAP_S = 0x2802,
    DRACARYS_GLR_WRAP_T = 0x2803,
    DRACARYS_GLR_WRAP_R = 0x8072,
};


enum dracarys_glr_texture_param {
    DRACARYS_GLR_FILTER_NEAREST = 0x2600,
    DRACARYS_GLR_FILTER_LINEAR = 0x2601,
    DRACARYS_GLR_NEAREST_MIPMAP_NEAREST = 0x2700,
    DRACARYS_GLR_LINEAR_MIPMAP_NEAREST = 0x2701,
    DRACARYS_GLR_NEAREST_MIPMAP_LINEAR = 0x2702,
    DRACARYS_GLR_LINEAR_MIPMAP_LINEAR = 0x2703,
    DRACARYS_GLR_WRAP_REPEAT = 0x2901,
    DRACARYS_GLR_WRAP_CLAMP_TO_BORDER = 0x812D,
    DRACARYS_GLR_WRAP_CLAMP_TO_EDGE = 0x812F,
    DRACARYS_GLR_WRAP_MIRRORED_REPEAT = 0x8370,
};

enum dracarys_glr_texture_target {
    DRACARYS_GLR_TEXTURE_TYPE_1D = 0x0DE0,
    DRACARYS_GLR_TEXTURE_TYPE_2D = 0x0DE1,
    DRACARYS_GLR_TEXTURE_TYPE_3D = 0x806F,
};

enum dracarys_glr_texture_sampler {
    DRACARYS_GLR_TEXTURE0  = 0x84C0,
    DRACARYS_GLR_TEXTURE1  = 0x84C1,
    DRACARYS_GLR_TEXTURE2  = 0x84C2,
    DRACARYS_GLR_TEXTURE3  = 0x84C3,
    DRACARYS_GLR_TEXTURE4  = 0x84C4,
    DRACARYS_GLR_TEXTURE5  = 0x84C5,
    DRACARYS_GLR_TEXTURE6  = 0x84C6,
    DRACARYS_GLR_TEXTURE7  = 0x84C7,
    DRACARYS_GLR_TEXTURE8  = 0x84C8,
    DRACARYS_GLR_TEXTURE9  = 0x84C9,
    DRACARYS_GLR_TEXTURE10 = 0x84CA,
    DRACARYS_GLR_TEXTURE11 = 0x84CB,
    DRACARYS_GLR_TEXTURE12 = 0x84CC,
    DRACARYS_GLR_TEXTURE13 = 0x84CD,
    DRACARYS_GLR_TEXTURE14 = 0x84CE,
    DRACARYS_GLR_TEXTURE15 = 0x84CF,
    DRACARYS_GLR_TEXTURE16 = 0x84D0,
    DRACARYS_GLR_TEXTURE17 = 0x84D1,
    DRACARYS_GLR_TEXTURE18 = 0x84D2,
    DRACARYS_GLR_TEXTURE19 = 0x84D3,
    DRACARYS_GLR_TEXTURE20 = 0x84D4,
    DRACARYS_GLR_TEXTURE21 = 0x84D5,
    DRACARYS_GLR_TEXTURE22 = 0x84D6,
    DRACARYS_GLR_TEXTURE23 = 0x84D7,
    DRACARYS_GLR_TEXTURE24 = 0x84D8,
    DRACARYS_GLR_TEXTURE25 = 0x84D9,
    DRACARYS_GLR_TEXTURE26 = 0x84DA,
    DRACARYS_GLR_TEXTURE27 = 0x84DB,
    DRACARYS_GLR_TEXTURE28 = 0x84DC,
    DRACARYS_GLR_TEXTURE29 = 0x84DD,
    DRACARYS_GLR_TEXTURE30 = 0x84DE,
    DRACARYS_GLR_TEXTURE31 = 0x84DF,
};

enum dracarys_utility_pixel_format;

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

typedef struct {
    unsigned int texture;
    enum dracarys_glr_texture_target target;
    int success;
} dracarys_glr_texture_t;

typedef struct {
    enum dracarys_glr_texture_target target;
    enum dracarys_glr_texture_pname pname;
    enum dracarys_glr_texture_param param;
    int parameter_type;
    float* fv_values;
} dracarys_glr_texture_param_t;

#define DRACARYS_TEXTURE_DEFAULT_PARAMETERS(t) { \
    (dracarys_glr_texture_param_t) { .target = t, .pname = DRACARYS_GLR_WRAP_S, .param = DRACARYS_GLR_WRAP_REPEAT, .parameter_type = DRACARYS_TEXTURE_PARAMETER_I }, \
    (dracarys_glr_texture_param_t) { .target = t, .pname = DRACARYS_GLR_WRAP_T, .param = DRACARYS_GLR_WRAP_REPEAT, .parameter_type = DRACARYS_TEXTURE_PARAMETER_I }, \
    (dracarys_glr_texture_param_t) { .target = t, .pname = DRACARYS_GLR_MIN_FILTER, .param = DRACARYS_GLR_FILTER_NEAREST, .parameter_type = DRACARYS_TEXTURE_PARAMETER_I }, \
    (dracarys_glr_texture_param_t) { .target = t, .pname = DRACARYS_GLR_MAG_FILTER, .param = DRACARYS_GLR_FILTER_LINEAR, .parameter_type = DRACARYS_TEXTURE_PARAMETER_I }, \
} \

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

/* 
    No need to call this in a loop. Just retrieve the location once.
    Returns DRACARYS_UNIFORM_NO_LOCATION if failed.
*/
int dracarys_glr_uniform_location(dracarys_glr_shader_t shader, const char* name);

void dracarys_glr_uniform_i(int uniform_location,  int value);

void dracarys_glr_uniform_f(int uniform_location,  float value);
void dracarys_glr_uniform_f2(int uniform_location, float x, float y);
void dracarys_glr_uniform_f3(int uniform_location, float x, float y, float z);
void dracarys_glr_uniform_f4(int uniform_location, float x, float y, float z, float w);

//TODO: Implement matrix uniform
void dracarys_glr_uniform_mat4();

void dracarys_glr_texture_parameter_i(enum dracarys_glr_texture_target target, enum dracarys_glr_texture_pname pname, enum dracarys_glr_texture_param param);
void dracarys_glr_texture_parameter_fv(enum dracarys_glr_texture_target target, enum dracarys_glr_texture_pname pname, const float* params);
void dracarys_glr_texture_image2d(enum dracarys_glr_texture_target target, int level, enum dracarys_utility_pixel_format internal_format, int width, int height, int border, enum dracarys_utility_pixel_format format, enum dracarys_glr_attribute_type type, const void* pixels);
void dracarys_glr_texture_generate_mipmap(enum dracarys_glr_texture_target target);
void dracarys_glr_texture_active_sampler(enum dracarys_glr_texture_sampler active_texture);


dracarys_glr_texture_t dracarys_glr_texture_create_empty(enum dracarys_glr_texture_target target);
dracarys_glr_texture_t dracarys_glr_texture_create_full(const char* filename, enum dracarys_glr_texture_target target, dracarys_glr_texture_param_t* parameters, int border, int use_mipmap, int mipmap_level);
void dracarys_glr_texture_bind(dracarys_glr_texture_t texture);
void dracarys_glr_texture_unbind(dracarys_glr_texture_t texture);
void dracarys_glr_texture_delete(dracarys_glr_texture_t* texture);

#endif