#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

typedef struct {
    char* vertex_shader;
    char* fragment_shader;
} UtilityShaderFiles;

char* utility_read_file_to_text(const char* filename);

UtilityShaderFiles utility_read_shader(const char* filename);
void utility_free_shader_files(UtilityShaderFiles* files);

#endif