//
// Created by Bacal Mesfin on 7/18/2021.
//

#include "window.h"
#include "shader.h"
#include "vertex_buffer.h"
#include "texture.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#if defined(__linux__) || defined(WIN32)
void GLAPIENTRY open_gl_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
{

	fprintf(stderr, "[Open GL %s] (0x%x): \n%s\n",type==GL_DEBUG_TYPE_ERROR?"Error":"Debug Message",type,message);
}
#endif
window* window_init(int width, int height, const char* title)
{
    window* window_object = malloc(sizeof(struct WINDOW_STRUCT));
    window_object->width = width;
    window_object->height = height;
    window_object->title = title;

	if(!glfwInit())
	{
		fprintf(stderr, "Indigo Error: Failed to initialize GLFW!\n");
		raise(SIGABRT);
	}
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    window_object->glfw_window_ptr = glfwCreateWindow(window_object->width, window_object->height, window_object->title, NULL, NULL);
	glfwMakeContextCurrent(window_object->glfw_window_ptr);
	glfwSwapInterval(1);

	#if defined(WIN32) || defined(__linux__)
	glewExperimental = 1;
	if(glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Indigo Error: Failed to initialize GLEW!\n");
		raise(SIGABRT);
	}
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(open_gl_debug_message_callback,0);

	#endif

	return window_object;
}

void window_loop(window* window, char* file_path)
{
	float vertices[] = {
		// positions          // colors           // texture coords
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,   // top right
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f    // top left
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	shader* shader_object = shader_init("Assets/Shaders/default.vert","Assets/Shaders/default.frag");
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vertex_buffer* vbo = vertex_buffer_init(vertices, sizeof(vertices));
	vertex_buffer_bind(vbo);
	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3*sizeof(float)));
	glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	texture* tex = texture_init(file_path);

	while(!glfwWindowShouldClose(window->glfw_window_ptr))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		shader_use(shader_object);
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		texture_bind(tex);
		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
		glfwPollEvents();
		glfwSwapBuffers(window->glfw_window_ptr);
	}
}

