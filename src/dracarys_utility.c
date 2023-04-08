#include "../header/Dracarys/dracarys_utility.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>


char* dracarys_utility_read_file_to_text(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        DRACARYS_UTILITY_LOG_ERROR("ERROR OPENING FILE [%s]\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* text = malloc(size + 1);
    if (text == NULL) {
        DRACARYS_UTILITY_LOG_ERROR("ERROR ALLOCATING STRING [%s]\n", filename);
        return NULL;
    }

    const size_t num_elements = 1;
    if (fread(text, size, num_elements, file) != num_elements) {
        DRACARYS_UTILITY_LOG_ERROR("ERROR READING FILE [%s]\n", filename);
        return NULL;
    }

    fclose(file);

    text[size] = '\0';

    return text;
}

dracarys_utility_shader_files_t dracarys_utility_shader_files_create(const char* filename) {
    char* file = dracarys_utility_read_file_to_text(filename);

    char* vertex_shader_text = strdup(strtok(file, "$"));
    char* fragment_shader_text = NULL;
    
    if (vertex_shader_text != NULL) {
        fragment_shader_text = strdup(strtok(NULL, "$"));
    }

    if (vertex_shader_text == NULL || fragment_shader_text == NULL) {
        DRACARYS_UTILITY_LOG_ERROR("SHADER UNABLE TO BE READ [%s]\n", filename);
        free(file);
        return (dracarys_utility_shader_files_t) { NULL, NULL };
    }

    free(file);
    
   return (dracarys_utility_shader_files_t) { .vertex_shader = vertex_shader_text, .fragment_shader = fragment_shader_text };
}

void dracarys_utility_shader_files_delete(dracarys_utility_shader_files_t* files) {
    if (files->vertex_shader != NULL) 
        free(files->vertex_shader);
    if (files->fragment_shader != NULL) 
        free(files->fragment_shader);
}
