//
// Created by bacal on 7/24/21.
//

#ifndef _PPM_LOADER_H_
#define _PPM_LOADER_H_
#define PPM_TYPE "P3"
#define COLOR_DEPTH "255"

typedef struct PPM_IMAGE_STRUCT
{
	unsigned char* data;
	int width;
	int height;
	int color_depth;
}ppm_image;

ppm_image* ppm_load(const char* file_path);

void ppm_delete(ppm_image* image);

#endif //_PPM_LOADER_H_
