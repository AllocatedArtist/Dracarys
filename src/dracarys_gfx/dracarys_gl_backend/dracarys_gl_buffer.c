#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

dracarys_glr_buffer_t dracarys_glr_buffer_create(enum dracarys_glr_buffer_type type) {
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer((GLenum)type, buffer);

    return (dracarys_glr_buffer_t) { buffer, type };
}

void dracarys_glr_buffer_bind(dracarys_glr_buffer_t buffer) {
    glBindBuffer(buffer.type, buffer.buffer);
}

void dracarys_glr_buffer_data(dracarys_glr_buffer_t buffer, signed long long size, const void* data, enum dracarys_glr_usage_type type) {
    glBufferData(buffer.type, size, data, type);
}

void dracarys_glr_buffer_unbind(dracarys_glr_buffer_t buffer) {
    glBindBuffer(buffer.type, 0);
}

void dracarys_glr_buffer_delete(dracarys_glr_buffer_t* buffer) {
    glDeleteBuffers(1, &buffer->buffer);
}
