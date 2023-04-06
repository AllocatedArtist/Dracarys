#include "../header/utility.h"

char* utility_read_file_to_text(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* text = malloc(size);
    if (text == NULL) {
        printf("Error allocating string. Can't open %s\n", filename);
        return NULL;
    }

    const size_t num_elements = 1;
    if (fread(text, size, num_elements, file) != num_elements) {
        printf("Error reading %s\n", filename);
        return NULL;
    }

    fclose(file);

    return text;
}

UtilityShaderFiles utility_read_shader(const char* filename) {
    char* file = utility_read_file_to_text(filename);

    char* vertex_shader_text = strdup(strtok(file, "$"));
    char* fragment_shader_text = NULL;
    
    if (vertex_shader_text != NULL) {
        fragment_shader_text = strdup(strtok(NULL, "$"));
    }

    if (vertex_shader_text == NULL || fragment_shader_text == NULL) {
        printf("SHADER UNABLE TO BE READ [%s]\n", filename);
        free(file);
        return (UtilityShaderFiles) { NULL, NULL };
    }

    free(file);

   return (UtilityShaderFiles) { .vertex_shader = vertex_shader_text, .fragment_shader = fragment_shader_text };
}

void utility_free_shader_files(UtilityShaderFiles* files) {
    if (files->vertex_shader != NULL) 
        free(files->vertex_shader);
    if (files->fragment_shader != NULL) 
        free(files->fragment_shader);
}