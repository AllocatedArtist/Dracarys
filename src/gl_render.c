#include "glad/glad.h"

#include "../header/gl_render.h"
#include "../header/utility.h"


void glr_clear(enum ClearFlags flags) {
    glClear((GLbitfield)flags);
}

void glr_clear_color_rgba_f(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void glr_clear_color_rgb_f(float r, float g, float b) {
     glClearColor(r, g, b, 1.0);
}

void glr_clear_color_rgba_u(unsigned char r, unsigned char g, unsigned char b, float a) {
    float red = (float)r/255.0;
    float green = (float)g/255.0;
    float blue = (float)b/255.0;
    glClearColor(red, green, blue, a);
}

void glr_clear_color_rgb_u(unsigned char r, unsigned char g, unsigned char b) {
     float red = (float)r/255.0;
    float green = (float)g/255.0;
    float blue = (float)b/255.0;
    glClearColor(red, green, blue, 1.0);
}

GLR_Buffer glr_create_buffer(enum BufferType type) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer((GLenum)type, buffer);

    return (GLR_Buffer) { buffer, type };
}

void glr_bind_buffer(GLR_Buffer buffer) {
    glBindBuffer(buffer.type, buffer.buffer);
}

void glr_buffer_data(GLR_Buffer buffer, signed long long size, const void* data, enum UsageType type) {
    glBufferData(buffer.type, size, data, type);
}

void glr_unbind_buffer(GLR_Buffer buffer) {
    glBindBuffer(buffer.type, 0);
}

void glr_delete_buffer(GLR_Buffer* buffer) {
    glDeleteBuffers(1, &buffer->buffer);
}

unsigned int glr_create_vertex_array(void) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

void glr_bind_vertex_array(unsigned int vao) {
    glBindVertexArray(vao);
}

void glr_unbind_vertex_array(void) {
    glBindVertexArray(0);
}

void glr_delete_vertex_array(unsigned int* vao) {
    glDeleteVertexArrays(1, vao);
}

GLR_VertexAttribute glr_create_vertex_attribute(unsigned int index, int size, int normalized, enum AttributeType type, unsigned int stride, const void* data) {

    unsigned int datatype = sizeof(float);

    switch(type) {
        case ATTRIBUTE_TYPE_BYTE:
            datatype = sizeof(char);
            break;
        case ATTRIBUTE_TYPE_FLOAT:
            datatype = sizeof(float);
            break;
        case ATTRIBUTE_TYPE_INT:
            datatype = sizeof(int);
            break;
        case ATTRIBUTE_TYPE_SHORT:
            datatype = sizeof(short);
            break;
        case ATTRIBUTE_TYPE_UNSIGNED_BYTE:
            datatype = sizeof(unsigned char);
            break;
        case ATTRIBUTE_TYPE_UNSIGNED_INT:
            datatype = sizeof(unsigned int);
            break;
        case ATTRIBUTE_TYPE_UNSIGNED_SHORT:
            datatype = sizeof(unsigned short);
            break;
    };
    
    return (GLR_VertexAttribute) {
        index,
        size,
        type,
        normalized, 
        datatype * stride,
        data
    };
}

void glr_set_vertex_attribute(GLR_VertexAttribute attribute) {
    glVertexAttribPointer(
    attribute.index, 
    attribute.size, 
    attribute.type, 
    attribute.normalized, 
    attribute.stride, 
    attribute.pointer);
}

void glr_enable_vertex_attribute(GLR_VertexAttribute attribute) {
    glEnableVertexAttribArray(attribute.index);
}

void glr_disable_vertex_attribute(GLR_VertexAttribute attribute) {
    glDisableVertexAttribArray(attribute.index);
}

GLR_Shader glr_create_empty_shader(void) {
    return (GLR_Shader) { 
        .shader_program = glCreateProgram(), 
        .vertex_shader = glCreateShader(GL_VERTEX_SHADER), 
        .fragment_shader = glCreateShader(GL_FRAGMENT_SHADER),
        .compilation_success = NO_SHADER
    };
}

int glr_check_shader(GLR_Shader shader, GLboolean check_vertex) {
    int success = GL_FALSE;

    glGetShaderiv(check_vertex == GL_TRUE ? shader.vertex_shader : shader.fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        char log[512];
        glGetShaderInfoLog(check_vertex == GL_TRUE ? shader.vertex_shader : shader.fragment_shader, 512, NULL, log);
        const char* type = check_vertex ? "VERTEX" : "FRAGMENT";
        printf("%s SHADER UNABLE TO COMPILE:\n %s \n", type, log);
        return GL_FALSE;
    }

    return GL_TRUE;
}

int glr_check_program(GLR_Shader shader) {
    int success = GL_FALSE;

    glGetProgramiv(shader.shader_program, GL_LINK_STATUS, &success);

    if (!success) {
        char log[512];
        glGetProgramInfoLog(shader.shader_program, 512, NULL, log);
        printf("PROGRAM NOT LINKED:\n %s \n", log);
        return GL_FALSE;
    }

    return GL_TRUE;
}

int glr_vertex_shader(GLR_Shader shader, const char* data) {
    glShaderSource(shader.vertex_shader, 1, &data, NULL);
    glCompileShader(shader.vertex_shader);

    return glr_check_shader(shader, GL_TRUE);
}

int glr_fragment_shader(GLR_Shader shader, const char* data) {
    glShaderSource(shader.fragment_shader, 1, &data, NULL);
    glCompileShader(shader.fragment_shader);

    return glr_check_shader(shader, GL_FALSE);
}

int glr_complete_shader(GLR_Shader shader) {
    glAttachShader(shader.shader_program, shader.vertex_shader);
    glAttachShader(shader.shader_program, shader.fragment_shader);
    glLinkProgram(shader.shader_program);

    return glr_check_program(shader);
}

void glr_use_program(GLR_Shader shader) {
    glUseProgram(shader.shader_program);
}

void glr_disable_program(void) {
    glUseProgram(0);
}

void glr_delete_vertex_shader(GLR_Shader shader) {
    glDeleteShader(shader.vertex_shader);
}

void glr_delete_fragment_shader(GLR_Shader shader) {
    glDeleteShader(shader.fragment_shader);
}

void glr_delete_program(GLR_Shader shader) {
    glDeleteProgram(shader.shader_program);
}

GLR_Shader glr_create_shader(const char* shader_path) {
    GLR_Shader shader = glr_create_empty_shader();

    UtilityShaderFiles shader_file = utility_read_shader(shader_path);

    if (glr_vertex_shader(shader, shader_file.vertex_shader) == GL_FALSE) {
        printf("ERROR MAKING VERTEX SHADER [%s]\n", shader_path);
        return (GLR_Shader) { 0, 0, 0, .compilation_success = NO_SHADER };
    }

    if (glr_fragment_shader(shader, shader_file.fragment_shader) == GL_FALSE) {
        printf("ERROR MAKING FRAGMENT SHADER [%s]\n", shader_path);
        return (GLR_Shader) { 0, 0, 0, .compilation_success = NO_SHADER };
    }

    if (glr_complete_shader(shader) == GL_FALSE) {
        printf("ERROR COMPLETING SHADER PROGRAM [%s]\n", shader_path);
        return (GLR_Shader) { 0, 0, 0, .compilation_success = NO_SHADER };
    }

    utility_free_shader_files(&shader_file);

    shader.compilation_success = YES_SHADER;

    return shader;
}

void glr_draw_arrays(enum DrawType type, unsigned int count) {
    assert(count > 0);
    glDrawArrays(type, 0, count);
}

void glr_draw_elements(enum DrawType mode, unsigned int count, enum AttributeType type, const void* indices) {
    assert(count > 0);
    glDrawElements(mode, count, type, indices);
}