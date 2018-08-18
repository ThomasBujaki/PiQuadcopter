#include <stdlib.h>
#include "image_processing.h"
#include <stdio.h> 

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
    greyscale_image *sobel_image = (greyscale_image *)malloc(sizeof(greyscale_image)); 
    init_greyscale_image(sobel_image, gs_smooth->height, gs_smooth->width); 
    matrix sobel_angle;
    init_matrix(&sobel_angle, gs_smooth->width, gs_smooth->height);
    sobel(gs_smooth, sobel_image, &sobel_angle);     
    return sobel_image;
}

greyscale_image *image_processing(rgb_image *raw_image) {
    // Step 1: convert to grey scale
    greyscale_image *gs_image = grey_image(raw_image);
    printf("converted into greyscale\n");
    // Step 2: guasian smoothing
    greyscale_image *gs_smooth = smooth_image(gs_image);
    printf("applied gaussian smoothing\n");
    // Step 3: sobel
    greyscale_image *sobel_image = apply_sobel(gs_smooth);    
    printf("applied Sobel kernel\n");
    // Step 4: canny
    // Step 5: profit.
    // destroy_greyscale_image(gs_image);
    //free(gs_image);
    //free(gs_smooth)
    return sobel_image;
}
