#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

#include <assert.h>

void dracarys_glr_draw_arrays(enum dracarys_glr_draw_type type, unsigned int count) {
    assert(count > 0);
    glDrawArrays(type, 0, count);
}

void dracarys_glr_draw_elements(enum dracarys_glr_draw_type mode, unsigned int count, enum dracarys_glr_attribute_type type, const void* indices) {
    assert(count > 0);
    glDrawElements(mode, count, type, indices);
}