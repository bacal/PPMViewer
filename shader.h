#ifndef _SHADER_H
#define _SHADER_H

#include <stdbool.h>
typedef struct SHADER_STRUCT
{
    unsigned int shader_program_id;
    bool in_use;
}shader;

shader* shader_init(const char* vertex_source_path, const char* fragment_source_path);
shader* shader_init_str(const char* vertex_source_str, const char* fragment_source_str);
void shader_use(shader* shader_name);

void shader_detatch(shader* shader_name);

#endif //_SHADER_H
