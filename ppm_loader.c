//
// Created by bacal on 7/24/21.
//

#include "ppm_loader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ppm_image* ppm_load(const char* file_path)
{
	char ppm_type[2];
	ppm_image* image = (ppm_image*) malloc(sizeof(struct PPM_IMAGE_STRUCT));

	FILE* fp = fopen(file_path,"r");
	fscanf(fp,"%s%d %d%d",ppm_type,&image->width,&image->height,&image->color_depth);
	if(strcmp(ppm_type,PPM_TYPE) !=0)
	{
		fprintf(stderr,"Error: Invalid file format!\n");
		return NULL;
	}
	long size = ((image->width*image->height)*3);

	image->data = (unsigned char*) malloc(size);
	for(long i=0; i<size; i++)
	{
	    char num[4];
		fscanf(fp,"\n%s",num);
		image->data[i] = atoi(num);
		//printf("%d\n",image->data[i]);
	}
	return image;
}

void ppm_delete(ppm_image* image)
{
	free(image->data);
	free(image);
}