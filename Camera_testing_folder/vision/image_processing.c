#include <stdlib.h>

#include "image_processing.h"

greyscale_image *grey_image(rgb_image *raw_image) {
    greyscale_image *gs_image = (greyscale_image *)malloc(sizeof(greyscale_image));
    init_greyscale_image(gs_image, raw_image->height, raw_image->width);
    make_greyscale(raw_image, gs_image);
    return gs_image;
}

greyscale_image *smooth_image(greyscale_image *gs_image) {
    greyscale_image *gs_smooth = (greyscale_image *)malloc(sizeof(greyscale_image));
    init_greyscale_image(gs_smooth, gs_image->height, gs_image->width);
    gauss_blur(gs_image, gs_smooth);     
    return gs_smooth;
}

greyscale_image *apply_sobel(greyscale_image *gs_smooth) {
    greyscale_image *sobel_image = (gs_smooth *)malloc(sizeof(greyscale_image));
    init_greyscale_image(sobel_image, gs_smooth->height, gs_smoth->width);
    sobel(gs_smooth, sobel_image);     
    return sobel_image;
}

greyscale_image *image_processing(rgb_image *raw_image) {
    // Step 1: convert to grey scale
    greyscale_image *gs_image = grey_image(raw_image);
    // Step 2: guasian smoothing
    greyscale_image *gs_smooth = smooth_image(gs_image);
    // Step 3: sobel
    greyscale_image *sobel_image = apply_sobel(gs_smooth);    
	
    // Step 4: canny
    // Step 5: profit.
    // destroy_greyscale_image(gs_image);
    //free(gs_image);
    return gs_smooth;
}
