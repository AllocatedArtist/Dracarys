#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

#include "../../header/Dracarys/dracarys_utility.h"

int dracarys_glr_uniform_location(dracarys_glr_shader_t shader, const char* name) {
    int location = glGetUniformLocation(shader.shader_program, name);
    if (location == DRACARYS_UNIFORM_NO_LOCATION) {
        DRACARYS_UTILITY_LOG_ERROR("INVALID UNIFORM LOCATION [%s]\n", name);
        return DRACARYS_UNIFORM_NO_LOCATION;
    }

    DRACARYS_UTILITY_LOG_INFO("Uniform location successfully retrieved [%s]\n", name);

    return location;
}

void dracarys_glr_uniform_i(int uniform_location, int value) {
    if (uniform_location != DRACARYS_UNIFORM_NO_LOCATION) glUniform1i(uniform_location, value);    
}

void dracarys_glr_uniform_f(int uniform_location, float value) {
     if (uniform_location != DRACARYS_UNIFORM_NO_LOCATION) glUniform1f(uniform_location, value);
}

void dracarys_glr_uniform_f2(int uniform_location, float x, float y) {
     if (uniform_location != DRACARYS_UNIFORM_NO_LOCATION) glUniform2f(uniform_location, x, y);
}

void dracarys_glr_uniform_f3(int uniform_location, float x, float y, float z) {
     if (uniform_location != DRACARYS_UNIFORM_NO_LOCATION) glUniform3f(uniform_location, x, y, z);
}

void dracarys_glr_uniform_f4(int uniform_location, float x, float y, float z, float w) {
     if (uniform_location != DRACARYS_UNIFORM_NO_LOCATION) glUniform4f(uniform_location, x, y, z, w);
}