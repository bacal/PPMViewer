//
// Created by bacal on 7/25/21.
//

#ifndef _VERTEX_BUFFER_H_
#define _VERTEX_BUFFER_H_

typedef struct VERTEX_BUFFER_STRUCT
{
	unsigned int __renderer_id;
	_Bool bound;
}vertex_buffer;

vertex_buffer* vertex_buffer_init(const void* data, unsigned int size);

void vertex_buffer_delete(vertex_buffer* buffer);

void vertex_buffer_bind(vertex_buffer* buffer);

void vertex_buffer_unbind(vertex_buffer* buffer);

#endif //_VERTEX_BUFFER_H_
