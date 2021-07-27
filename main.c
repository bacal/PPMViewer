#include <stdio.h>
#include "PPMViewer/window.h"
#include "PPMViewer/shader.h"
#include "PPMViewer/ppm_loader.h"
int main()
{
	window* window_object = window_init( 800, 800, "Hello World");

    window_loop(window_object);

	return 0;
}
