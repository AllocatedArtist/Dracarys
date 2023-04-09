#include "../../header/Dracarys/extern/glad/glad.h"
#include "../../header/Dracarys/dracarys_gfx/dracarys_glr.h"

#include "../../header/Dracarys/dracarys_utility.h"

void dracarys_glr_texture_parameter_i(enum dracarys_glr_texture_target target, enum dracarys_glr_texture_pname pname, enum dracarys_glr_texture_param param) {
    glTexParameteri(target, pname, param);
}

void dracarys_glr_texture_parameter_fv(enum dracarys_glr_texture_target target, enum dracarys_glr_texture_pname pname, const float* params) {
    glTexParameterfv(target, pname, params);
}

dracarys_glr_texture_t dracarys_glr_texture_create_empty(enum dracarys_glr_texture_target target) {
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(target, texture);

    return (dracarys_glr_texture_t) { .target = target, .texture = texture };
}


void dracarys_glr_texture_image2d(enum dracarys_glr_texture_target target, int level, enum dracarys_utility_pixel_format internal_format, int width, int height, int border, enum dracarys_utility_pixel_format format, enum dracarys_glr_attribute_type type, const void* pixels) {
    glTexImage2D(target, level, internal_format, width, height, border, format, type, pixels);
}

void dracarys_glr_texture_generate_mipmap(enum dracarys_glr_texture_target target) {
    glGenerateMipmap(target);
}

void dracarys_glr_texture_active_sampler(enum dracarys_glr_texture_sampler active_texture) {
    glActiveTexture(active_texture);
}

dracarys_glr_texture_t dracarys_glr_texture_create_full(const char* filename, enum dracarys_glr_texture_target target, dracarys_glr_texture_param_t* parameters, int border, int use_mipmap, int mipmap_level) {
    dracarys_glr_texture_t texture = dracarys_glr_texture_create_empty(target);
    
    size_t length = sizeof(parameters) / sizeof(parameters[0]);
    
    for (int i = 0; i < length; ++i) {
        dracarys_glr_texture_param_t parameter = parameters[i];

        if (parameter.parameter_type == DRACARYS_TEXTURE_PARAMETER_I) {
            dracarys_glr_texture_parameter_i(parameter.target, parameter.pname, parameter.param);
        } else if (parameter.parameter_type == DRACARYS_TEXTURE_PARAMETER_FV) {
            dracarys_glr_texture_parameter_fv(parameter.target, parameter.pname, parameter.fv_values);
        }
    }

    dracarys_utility_image_t image = dracarys_utility_image_load(filename);
    if (image.data == NULL) {
        return (dracarys_glr_texture_t) { .texture = 0, .target = DRACARYS_GLR_TEXTURE_TYPE_1D, .success = DRACARYS_TEXTURE_UNSUCCESSFUL };
    } else {
        dracarys_glr_texture_image2d(target, mipmap_level, image.format, image.width, image.height, border, image.format, DRACARYS_GLR_ATTRIBUTE_TYPE_UNSIGNED_BYTE, image.data);
        if (use_mipmap == DRACARYS_YES_MIPMAP) {
            dracarys_glr_texture_generate_mipmap(target);
        }
    }

    dracarys_utility_image_delete(&image);

    texture.success = DRACARYS_TEXTURE_SUCCESSFUL;

    glBindTexture(target, 0);

    return texture;
}

void dracarys_glr_texture_bind(dracarys_glr_texture_t texture) {
    glBindTexture(texture.target, texture.texture);
}

void dracarys_glr_texture_unbind(dracarys_glr_texture_t texture) {
    glBindTexture(texture.target, 0);
}

void dracarys_glr_texture_delete(dracarys_glr_texture_t* texture) {
    if (texture->success == DRACARYS_TEXTURE_SUCCESSFUL) glDeleteTextures(1, &texture->texture);
}