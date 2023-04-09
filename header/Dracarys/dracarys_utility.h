#ifndef DRACARYS_UTILITY_H
#define DRACARYS_UTILITY_H

#include "extern/log.h"
#include <stdarg.h>

#define DRACARYS_UTILITY_LOG_TRACE(...) log_trace(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_DEBUG(...) log_debug(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_INFO(...) log_info(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_WARN(...) log_warn(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_ERROR(...) log_error(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_FATAL(...) log_fatal(__VA_ARGS__) 

#define DRACARYS_UTILITY_LOG_SET_QUIET(enable) log_set_quiet(enable)
#define DRACARYS_UTILITY_LOG_SET_LEVEL(level) log_set_level(level)
#define DRACARYS_UTILITY_LOG_SET_FILE(file_pointer, level) (log_add_fp(file_pointer, level))

#define DRACARYS_YES_FLIP_IMAGE 1
#define DRACARYS_NO_FLIP_IMAGE 0

enum dracarys_utility_log_level {
    DRACARYS_UTILITY_LOG_TRACE_LEVEL,
    DRACARYS_UTILITY_LOG_DEBUG_LEVEL,
    DRACARYS_UTILITY_LOG_INFO_LEVEL,
    DRACARYS_UTILITY_LOG_WARN_LEVEL,
    DRACARYS_UTILITY_LOG_ERROR_LEVEL,
    DRACARYS_UTILITY_LOG_FATAL_LEVEL,
};

enum dracarys_utility_pixel_format {
    DRACARYS_UTILITY_PIXEL_RED = 0x1903,
    DRACARYS_UTILITY_PIXEL_RGB = 0x1907,
    DRACARYS_UTILITY_PIXEL_RGBA = 0x1908,
};

typedef struct {
    char* vertex_shader;
    char* fragment_shader;
} dracarys_utility_shader_files_t;

typedef struct {
    void* data;
    int width, height;
    enum dracarys_utility_pixel_format format;
} dracarys_utility_image_t;


char* dracarys_utility_read_file_to_text(const char* filename);

dracarys_utility_shader_files_t dracarys_utility_shader_files_create(const char* filename);
void dracarys_utility_shader_files_delete(dracarys_utility_shader_files_t* files);

void dracarys_utility_image_set_flip_on_load(int flip);

dracarys_utility_image_t dracarys_utility_image_load(const char* filename);
dracarys_utility_image_t dracarys_utility_image_load_from_memory(const unsigned char** buffer, int data_size);
void dracarys_utility_image_delete(dracarys_utility_image_t* image);



#endif