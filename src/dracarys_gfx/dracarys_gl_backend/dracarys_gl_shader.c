#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

#include "../../header/Dracarys/dracarys_utility.h"

dracarys_glr_shader_t dracarys_glr_shader_create_empty(void) {
    return (dracarys_glr_shader_t) { 
        .shader_program = glCreateProgram(), 
        .vertex_shader = glCreateShader(GL_VERTEX_SHADER), 
        .fragment_shader = glCreateShader(GL_FRAGMENT_SHADER),
        .compilation_success = DRACARYS_NO_SHADER
    };
}

int dracarys_glr_shader_check(dracarys_glr_shader_t shader, GLboolean check_vertex) {
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

int dracarys_glr_program_check(dracarys_glr_shader_t shader) {
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

int dracarys_glr_vertex_shader_create(dracarys_glr_shader_t shader, const char* data) {
    glShaderSource(shader.vertex_shader, 1, &data, NULL);
    glCompileShader(shader.vertex_shader);

    return dracarys_glr_shader_check(shader, GL_TRUE);
}

int dracarys_glr_fragment_shader_create(dracarys_glr_shader_t shader, const char* data) {
    glShaderSource(shader.fragment_shader, 1, &data, NULL);
    glCompileShader(shader.fragment_shader);

    return dracarys_glr_shader_check(shader, GL_FALSE);
}

int dracarys_glr_shader_complete(dracarys_glr_shader_t shader) {
    glAttachShader(shader.shader_program, shader.vertex_shader);
    glAttachShader(shader.shader_program, shader.fragment_shader);
    glLinkProgram(shader.shader_program);

    return dracarys_glr_program_check(shader);
}

void dracarys_glr_shader_enable(dracarys_glr_shader_t shader) {
    glUseProgram(shader.shader_program);
}

void dracarys_glr_shader_disable(void) {
    glUseProgram(0);
}

void dracarys_glr_vertex_shader_delete(dracarys_glr_shader_t shader) {
    glDeleteShader(shader.vertex_shader);
}

void dracarys_glr_fragment_shader_delete(dracarys_glr_shader_t shader) {
    glDeleteShader(shader.fragment_shader);
}

void dracarys_glr_program_delete(dracarys_glr_shader_t shader) {
    glDeleteProgram(shader.shader_program);
}

dracarys_glr_shader_t dracarys_glr_shader_create_full(const char* shader_path) {
    dracarys_glr_shader_t shader = dracarys_glr_shader_create_empty();

    dracarys_utility_shader_files_t shader_file = dracarys_utility_shader_files_create(shader_path);

    if (dracarys_glr_vertex_shader_create(shader, shader_file.vertex_shader) == GL_FALSE) {
        printf("ERROR MAKING VERTEX SHADER [%s]\n", shader_path);
        return (dracarys_glr_shader_t) { 0, 0, 0, .compilation_success = DRACARYS_NO_SHADER };
    }

    if (dracarys_glr_fragment_shader_create(shader, shader_file.fragment_shader) == GL_FALSE) {
        printf("ERROR MAKING FRAGMENT SHADER [%s]\n", shader_path);
        return (dracarys_glr_shader_t) { 0, 0, 0, .compilation_success = DRACARYS_NO_SHADER };
    }

    if (dracarys_glr_shader_complete(shader) == GL_FALSE) {
        printf("ERROR COMPLETING SHADER PROGRAM [%s]\n", shader_path);
        return (dracarys_glr_shader_t) { 0, 0, 0, .compilation_success = DRACARYS_NO_SHADER };
    }

    dracarys_utility_shader_files_delete(&shader_file);

    shader.compilation_success = DRACARYS_YES_SHADER;

    return shader;
}