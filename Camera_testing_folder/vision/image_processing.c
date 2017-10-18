#include "image_processing.h"
#include "greyscale.h"
#include <stdlib.h>


gs_pixel* grey_image(rgb_pixel* raw_image) {
	gs_pixel* gs_image = (gs_pixel*)malloc (HEIGHT*WIDTH*sizeof(gs_pixel));
	make_greyscale(raw_image, gs_image, HEIGHT,WIDTH);
	return gs_pixel;
}

gs_pixel* smooth_image(gs_pixel* gs_image) {
	gs_pixel* gs_smooth = (gs_pixel*) malloc(SMOOTH_HEIGH * SMOOTH_WIDTH * sizeof(gs_pixel));
	make_smooth(gs_image, gs_smooth);
	return gs_smooth;
}


gs_pixel* image_processing(rgb_pixel* raw_image) {
	// Step 1: convert to grey scale
	gs_pixel* gs_image = grey_image(raw_image);
	// Step 2: guasian smoothing
	gs_pixel* gs_smooth = smooth_image(gs_image);

	// Step 3: sobel
	// Step 4: canny
	// Step 5: profit.
	
	free(gs_image);
	return gs_smooth;
}
