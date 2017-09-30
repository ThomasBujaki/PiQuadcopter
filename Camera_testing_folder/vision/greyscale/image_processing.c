#include "image_processing.h"
#include "greyscale.h"

gs_pixel* image_processing(rgb_pixel* raw_image) {
	// Step 1: convert to grey scale
	gs_image = (gs_pixel*)malloc (image_height*image_width*3);
	make_greyscale(raw_image, gs_image, image_height,image_width);
	// Step 2: guasian smoothing
	// Step 3: sobel
	// Step 4: canny
	// Step 5: profit.
	return gs_address;
}
