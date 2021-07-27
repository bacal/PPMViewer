//
// Created by Bacal Mesfin on 7/18/2021.
//

#ifndef _WINDOW_H_
#define _WINDOW_H_
#include "open_gl.h"
#include <GLFW/glfw3.h>

typedef struct WINDOW_STRUCT
{
	int width;
	int height;
	GLFWwindow* glfw_window_ptr;
	const char* title;
}window;

window* window_init(int width, int height, const char* title);
void window_loop(window* window, char* file_path);

#endif //_WINDOW_H_
