//
// Created by bacal on 7/25/21.
//

#include "vertex_buffer.h"
#include "open_gl.h"
#include <stdlib.h>
vertex_buffer* vertex_buffer_init(const void* data, unsigned int size)
{
	vertex_buffer* buffer = (vertex_buffer*) malloc(sizeof(struct VERTEX_BUFFER_STRUCT));
	glGenBuffers(1, &buffer->__renderer_id);
	glBindBuffer(GL_ARRAY_BUFFER, buffer->__renderer_id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	buffer->bound = 0;
	return buffer;
}
void vertex_buffer_delete(vertex_buffer* buffer)
{
	glDeleteBuffers(1,&buffer->__renderer_id);
	free(buffer);
}
void vertex_buffer_bind(vertex_buffer* buffer)
{
	if(!buffer->bound)
	{
		buffer->bound = 1;
		glBindBuffer(GL_ARRAY_BUFFER, buffer->__renderer_id);
	}
}
void vertex_buffer_unbind(vertex_buffer* buffer)
{
	if(buffer->bound)
	{
		buffer->bound = 0;
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}
