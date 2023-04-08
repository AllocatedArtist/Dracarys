#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"


void dracarys_glr_clear(enum dracarys_glr_clear_flags flags) {
    glClear((GLbitfield)flags);
}

void dracarys_glr_clear_color_rgba_f(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void dracarys_glr_clear_color_rgb_f(float r, float g, float b) {
     glClearColor(r, g, b, 1.0);
}

void dracarys_glr_clear_color_rgba_u(unsigned char r, unsigned char g, unsigned char b, float a) {
    float red = (float)r/255.0;
    float green = (float)g/255.0;
    float blue = (float)b/255.0;
    glClearColor(red, green, blue, a);
}

void dracarys_glr_clear_color_rgb_u(unsigned char r, unsigned char g, unsigned char b) {
     float red = (float)r/255.0;
    float green = (float)g/255.0;
    float blue = (float)b/255.0;
    glClearColor(red, green, blue, 1.0);
}