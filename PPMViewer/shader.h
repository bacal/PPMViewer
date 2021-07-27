#ifndef INDIGO_SHADER_H
#define INDIGO_SHADER_H

#include <cglm/cglm.h>
#include <stdbool.h>
typedef struct SHADER_STRUCT
{
    unsigned int shader_program_id;
    bool in_use;
}shader;

shader* shader_init(const char* vertex_source_path, const char* fragment_source_path);

void shader_use(shader* shader_name);

void shader_detatch(shader* shader_name);

void set_vec2(const char* uniform_name, vec2 vector);

void set_vec3(const char* uniform_name, vec3 vector);

void set_vec4(const char* uniform_name, vec4 vector);

void set_mat4(const char* uniform_name, mat4 matrix);

void set_mat3(const char* uniform_name, mat3 matrix);

void set_float(const char* uniform_name, float number);

void set_int(const char* uniform_name, int number);

void set_texture(const char* uniform_name, int slot);


#endif //INDIGO_SHADER_H
