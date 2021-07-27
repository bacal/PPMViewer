//
// Created by bacal on 7/24/21.
//

#include "texture.h"
#include "open_gl.h"
#include "ppm_loader.h"
#include <stdlib.h>
#include <stdio.h>
texture* texture_init(const char* file_path)
{
	ppm_image* image = ppm_load(file_path);
	if(!image)
    {
	    fprintf(stderr, "Error: invalid file\n");
    }
	texture* tex = (texture*) malloc(sizeof(struct TEXTURE_STRUCT));
	glGenTextures(1, &tex->__renderer_id);
	glBindTexture(GL_TEXTURE_2D,tex->__renderer_id);
	tex->in_use = 1;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height,0,GL_RGB,GL_UNSIGNED_BYTE,image->data);
	glGenerateMipmap(GL_TEXTURE_2D);
	ppm_delete(image);

	return tex;
}
void texture_bind(texture* tex)
{
	if(!tex->in_use)
	{
		glBindTexture(GL_TEXTURE_2D, tex->__renderer_id);
		tex->in_use = 1;
	}
}

void texture_unbind(texture* tex)
{
	if(tex->in_use)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		tex->in_use = 0;
	}
}