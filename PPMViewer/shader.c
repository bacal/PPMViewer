//
// Created by bacal on 7/22/21.
//
#include "open_gl.h"
#include "shader.h"

shader* shader_init(const char* vertex_source_path, const char* fragment_source_path)
{
    unsigned int program_id;
    char* vertex_data;
    char* fragment_data;
    FILE* vertex_file;
    FILE* fragment_file;
    vertex_file = fopen(vertex_source_path, "r");
    fragment_file = fopen(fragment_source_path, "r");

    if(!vertex_file)
    {
        fprintf(stderr, "Error: Failed to open file %s\n",vertex_source_path);
        return NULL;
    }
    if(!fragment_file)
    {
        fprintf(stderr, "Error: Failed to open file %s\n",fragment_source_path);
        return NULL;
    }

    fseek(vertex_file, 0, SEEK_END);
    long length = ftell(vertex_file);
    fseek(vertex_file,0,SEEK_SET);
    vertex_data = malloc(length+1);
    if(vertex_data)
    {
        fread(vertex_data, 1, length, vertex_file);
        *(vertex_data+length) = '\0';
    }
    fclose(vertex_file);

    fseek(fragment_file, 0, SEEK_END);
    length = ftell(fragment_file);
    fseek(fragment_file,0, SEEK_SET);
    fragment_data = malloc(length+1);
    if(fragment_data)
    {
        fread(fragment_data,1,length,fragment_file);
        *(fragment_data+length) = '\0';
    }
    fclose(fragment_file);

    int success;
    unsigned int vertex_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_id,1,(const GLchar* const*)&vertex_data,NULL);
    glCompileShader(vertex_id);

    glGetShaderiv(vertex_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char* error_log = malloc(512);
        glGetShaderInfoLog(vertex_id, 512, NULL, error_log);
        printf("Error: failed to compile vertex shader\n%s",error_log);
        free(error_log);
        return NULL;
    }
    free(vertex_data);

    unsigned int fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_id,1,(const GLchar* const*)&fragment_data,NULL);
    glCompileShader(fragment_id);

    glGetShaderiv(fragment_id, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char* error_log = malloc(512);
        glGetShaderInfoLog(fragment_id, 512, NULL, error_log);
        printf("Error: failed to compile fragment shader\n%s",error_log);
        free(error_log);
        return NULL;
    }
    free(fragment_data);
    shader* shader_object = malloc(sizeof(struct SHADER_STRUCT));
    shader_object->shader_program_id = glCreateProgram();
    glAttachShader(shader_object->shader_program_id, vertex_id);
    glAttachShader(shader_object->shader_program_id, fragment_id);
    glLinkProgram(shader_object->shader_program_id);

    glGetProgramiv(shader_object->shader_program_id, GL_LINK_STATUS, &success);

    if(!success)
    {
        char* error_log = malloc(512);
        glGetShaderInfoLog(shader_object->shader_program_id, 512, NULL, error_log);
        printf("Error: failed to compile fragment shader\n%s",error_log);
        free(error_log);
        return NULL;
    }
    printf("Shaders successfully compiled!\n");
    shader_object->in_use = false;
    return shader_object;
}

void shader_use(shader* shader_name)
{
    if(!shader_name->in_use)
    {
        glUseProgram(shader_name->shader_program_id);
        shader_name->in_use = true;
    }
}

void shader_detatch(shader* shader_name)
{
    if(shader_name->in_use)
    {
        glUseProgram(0);
        shader_name->in_use = false;
    }
}

void set_vec2(const char* uniform_name, vec2 vector)
{

}

void set_vec3(const char* uniform_name, vec3 vector)
{

}

void set_vec4(const char* uniform_name, vec4 vector)
{

}

void set_mat4(const char* uniform_name, mat4 matrix)
{

}

void set_mat3(const char* uniform_name, mat3 matrix)
{

}

void set_float(const char* uniform_name, float number)
{

}

void set_int(const char* uniform_name, int number)
{

}

void set_texture(const char* uniform_name, int slot)
{

}

