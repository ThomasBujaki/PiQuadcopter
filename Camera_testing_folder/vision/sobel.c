#include "sobel.h"
#include <stdio.h>

void set_sobel_magnitude(greyscale_image* sobel_magnitude, greyscale_pixel gx_value, greyscale_pixel gy_value, int width, int height) {
    greyscale_pixel pixel_magnitude;
    pixel_magnitude.pixel = sqrt((gx_value.pixel*gx_value.pixel)+(gy_value.pixel*gy_value.pixel));
    set_greyscale_pixel(sobel_magnitude, width, height, pixel_magnitude);
}

void set_sobel_angle(matrix* sobel_angle, greyscale_pixel gx_value, greyscale_pixel gy_value, int x, int y) {
//    printf("angle function here\n");
    float angle ;
    double div = (double)gy_value.pixel/(double)gx_value.pixel;
    angle = atan((double)gy_value.pixel/(double)gx_value.pixel);
    set_matrix_value(sobel_angle, x, y, angle);
}

//void sobel_convolution() {
//}

void *sobel(greyscale_image *image, greyscale_image* sobel_magnitude, matrix* sobel_angle) {
    matrix gx;
    matrix gy;
    
    float gx_matrix[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    float gy_matrix[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    
    init_matrix(&gx, 3, 3);
    init_matrix(&gy, 3, 3);

    set_matrix(&gx, gx_matrix, sizeof(gx_matrix));
    set_matrix(&gy, gy_matrix, sizeof(gy_matrix));//for some reason in my tests total sizeof a 9 element float array is 24 bytes? hopefully it copies properly
    
    //sobel_convolution 
    for (int x = 0; x < image->width; x++) {
        for (int y = 0; y < image->height; y++) {

            //gx
            greyscale_pixel gx_value;
            gx_value.pixel = get_mod_pixel_value(&gx, image, x, y);
            //gy
            greyscale_pixel gy_value;
            gy_value.pixel = get_mod_pixel_value(&gy, image, x, y);
            //magnitude
            set_sobel_magnitude(sobel_magnitude, gx_value, gy_value, x, y);
            //angle - not needed yet
            set_sobel_angle(sobel_angle, gx_value, gy_value, x, y);

        }
    }
 //   print_matrix(sobel_angle); ** use to verify the matrix values
 //   int threshold = 211 ; //varies for application [0 768]
 //   output_image = max(mag,threshold)
 //   output_image(output_image==round(threshold))=0;

}
