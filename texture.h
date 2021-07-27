//
// Created by bacal on 7/24/21.
//

#ifndef _TEXTURE_H
#define _TEXTURE_H

typedef struct TEXTURE_STRUCT
{
	unsigned int __renderer_id;
	int width;
	int height;
	_Bool in_use;
}texture;

texture* texture_init(const char* file_path);

void texture_bind(texture* tex);

void texture_unbind(texture* tex);

#endif //_TEXTURE_H
