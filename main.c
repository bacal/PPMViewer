#include <stdio.h>
#include "window.h"

int main(int argc, char** argv)
{

	if(argc == 1)
	{
		fprintf(stderr, "Usage: ppmviewer [FILE]\n");
		return 1;
	}

	window* window_object = window_init( 800, 800, "Hello World");
    window_loop(window_object, argv[1]);

	return 0;
}
