#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

unsigned int dracarys_glr_vertex_array_create(void) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    return vao;
}

void dracarys_glr_vertex_array_bind(unsigned int vao) {
    glBindVertexArray(vao);
}

void dracarys_glr_vertex_array_unbind(void) {
    glBindVertexArray(0);
}

void dracarys_glr_vertex_array_delete(unsigned int* vao) {
    glDeleteVertexArrays(1, vao);
}

dracarys_glr_vertex_attribute_t dracarys_glr_vertex_attribute_create(unsigned int index, int size, int normalized, enum dracarys_glr_attribute_type type, unsigned int stride, const void* data) {

    unsigned int datatype = sizeof(float);

    switch(type) {
        case DRACARYS_GLR_ATTRIBUTE_TYPE_BYTE:
            datatype = sizeof(char);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_FLOAT:
            datatype = sizeof(float);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_INT:
            datatype = sizeof(int);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_SHORT:
            datatype = sizeof(short);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_BYTE:
            datatype = sizeof(unsigned char);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_INT:
            datatype = sizeof(unsigned int);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_SHORT:
            datatype = sizeof(unsigned short);
            break;
        case DRACARYS_GLR_ATTRIBUTE_TYPE_DOUBLE:
            datatype = sizeof(double);
            break;
    };
    
    return (dracarys_glr_vertex_attribute_t) {
        index,
        size,
        type,
        normalized, 
        datatype * stride,
        data
    };
}

void dracarys_glr_vertex_attribute_set(dracarys_glr_vertex_attribute_t attribute) {
    glVertexAttribPointer(
    attribute.index, 
    attribute.size, 
    attribute.type, 
    attribute.normalized, 
    attribute.stride, 
    attribute.pointer);
}

void dracarys_glr_vertex_attribute_enable(dracarys_glr_vertex_attribute_t attribute) {
    glEnableVertexAttribArray(attribute.index);
}

void dracarys_glr_vertex_attribute_disable(dracarys_glr_vertex_attribute_t attribute) {
    glDisableVertexAttribArray(attribute.index);
}