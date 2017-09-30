#include "image_processing.h"
#include "greyscale.h"
#include <stdlib.h>

gs_pixel* image_processing(rgb_pixel* raw_image) {
	// Step 1: convert to grey scale
	gs_pixel* gs_image = (gs_pixel*)malloc (HEIGHT*WIDTH*3);
	make_greyscale(raw_image, gs_image, HEIGHT,WIDTH);
	// Step 2: guasian smoothing
	// Step 3: sobel
	// Step 4: canny
	// Step 5: profit.
	return gs_image;
}
