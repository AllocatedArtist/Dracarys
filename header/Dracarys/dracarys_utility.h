#ifndef DRACARYS_UTILITY_H
#define DRACARYS_UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

typedef struct {
    char* vertex_shader;
    char* fragment_shader;
} dracarys_utility_shader_files_t;

char* dracarys_utility_read_file_to_text(const char* filename);

dracarys_utility_shader_files_t dracarys_utility_shader_files_create(const char* filename);
void dracarys_utility_shader_files_delete(dracarys_utility_shader_files_t* files);

#endif