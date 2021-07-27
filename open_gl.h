//
// Created by Bacal Mesfin on 7/13/21.
//

/* GLEW On Windows/Linux, Apple's Implementation on macOS */
#ifndef ____OPEN_GL_H__
#define ____OPEN_GL_H__

#if defined(__APPLE_CC__)
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#endif

#if defined(__linux__) || defined(WIN32)
#include <GL/glew.h>
#endif

/* GLFW3 included on all systems */
#include <GLFW/glfw3.h>
#endif /*____OPEN_GL_H__*/