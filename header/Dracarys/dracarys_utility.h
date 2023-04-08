#ifndef DRACARYS_UTILITY_H
#define DRACARYS_UTILITY_H

#include "extern/log.h"
#include <stdarg.h>

enum dracarys_utility_log_level {
    DRACARYS_UTILITY_LOG_TRACE_LEVEL,
    DRACARYS_UTILITY_LOG_DEBUG_LEVEL,
    DRACARYS_UTILITY_LOG_INFO_LEVEL,
    DRACARYS_UTILITY_LOG_WARN_LEVEL,
    DRACARYS_UTILITY_LOG_ERROR_LEVEL,
    DRACARYS_UTILITY_LOG_FATAL_LEVEL,
};

typedef struct {
    char* vertex_shader;
    char* fragment_shader;
} dracarys_utility_shader_files_t;


char* dracarys_utility_read_file_to_text(const char* filename);

dracarys_utility_shader_files_t dracarys_utility_shader_files_create(const char* filename);
void dracarys_utility_shader_files_delete(dracarys_utility_shader_files_t* files);

#define DRACARYS_UTILITY_LOG_TRACE(...) log_trace(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_DEBUG(...) log_debug(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_INFO(...) log_info(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_WARN(...) log_warn(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_ERROR(...) log_error(__VA_ARGS__) 
#define DRACARYS_UTILITY_LOG_FATAL(...) log_fatal(__VA_ARGS__) 

#define DRACARYS_UTILITY_LOG_SET_QUIET(enable) log_set_quiet(enable)
#define DRACARYS_UTILITY_LOG_SET_LEVEL(level) log_set_level(level)
#define DRACARYS_UTILITY_LOG_SET_FILE(file_pointer, level) (log_add_fp(file_pointer, level))

#endif