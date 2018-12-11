#include <stdlib.h>
#include "image_processing.h"
#include <stdio.h>

void destroy_image_struct(greyscale_image *image_struct) {
    free(image_struct);
}

void destroy_matrix_struct(matrix* matrix_struct) {
    free(matrix_struct);
}

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

sobel_output *apply_sobel(greyscale_image *gs_smooth) {
    greyscale_image *sobel_image = (greyscale_image *)malloc(sizeof(greyscale_image)); 
    init_greyscale_image(sobel_image, gs_smooth->height, gs_smooth->width); 

    matrix *sobel_angle = (matrix *)malloc(sizeof(matrix));
    init_matrix(sobel_angle, gs_smooth->width, gs_smooth->height);

    sobel_output *sobel_g_a = (sobel_output *)malloc(sizeof(sobel_output));
    sobel(gs_smooth, sobel_image, sobel_angle, sobel_g_a);     

    return sobel_g_a;
}

greyscale_image *image_processing(rgb_image *raw_image) {
    // Step 1: convert to grey scale
    greyscale_image *gs_image = grey_image(raw_image);
    printf("converted into greyscale\n");
  
    // Step 2: guasian smoothing
    greyscale_image *gs_smooth = smooth_image(gs_image);
    destroy_greyscale_image(gs_image);
    destroy_image_struct(gs_image);
    printf("applied gaussian smoothing\n");
  
    // Step 3: sobel
    sobel_output *sobel_image = apply_sobel(gs_smooth);    
    destroy_greyscale_image(gs_smooth);
    destroy_image_struct(gs_smooth);
//    destroy_matrix(sobel_image->sobel_angle.data);
//    Need to free sobel_angle matrix memory 
//    print_matrix(sobel_image->sobel_angle);
    printf("applied Sobel kernel\n");
//    greyscale_image *sobel_magnitude = sobel_image->sobel_gradient;
    // Step 4: canny
  
    // Step 5: profit.
    return sobel_image->sobel_gradient;
}
