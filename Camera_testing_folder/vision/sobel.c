#include "sobel.h"
#include <math.h>

void set_sobel_magnitude(greyscale_image* sobel_magnitude, greyscale_pixel gx_value, greyscale_pixel gy_value, int width, int height) {
    int pixel_magnitude;
    pixel_magnitude = sqrt((gx_value*gx_value)+(gy_value*gy_value));
    //put threshold calculation here (if needed)
    set_greyscale_pixel(sobel_magnitude, width, height, pixel_magnitude);
}

void set_sobel_angle(matrix* sobel_angle, greyscale_pixel gx_value, greyscale_pixel gy_value, int angle_matrix_size) {
    for (int x = 0; x < sobel_angle->width; x++) {
    	for (int y = 0; y < sobel_angle->height; y++) {
            float angle = (float)atan((double)(gy_value/gx_value));
            set_matrix_value(&sobel_angle, x, y, angle);
        }
    }
}

//void sobel_convolution() {
//}

void *sobel(greyscale_image *image, greyscale_image* sobel_magnitude, matrix* sobel_angle) {
    matrix gx;
    matrix gy;

    init_matrix(&gx, 3, 3);
    init_matrix(&gy, 3, 3);

    set_matrix(&gx, {-1f, 0f, 1f, -2f, 0f, 2f, -1f, 0f, 1f})
    set_matrix(&gy, {-1f, -2f, -1f, 0f, 0f, 0f, 1f, 2f, 1f})

    //sobel_convolution 
    for (int x = 0; x < image->width; x++) {
        for (int y = 0; y < image->height; y++) {

            //gx
            greyscale_pixel gx_value;
            gx_value.pixel = get_mod_pixel_value(gx, image, x, y);
            //gy
            greyscale_pixel gy_value;
            gy_value.pixel = get_mod_pixel_value(gy, image, x, y);
            //magnitude
            set_sobel_magnitude(sobel_magnitude, gx_value, gy_value, x, y);
            //angle - not needed yet
            set_sobel_angle(sobel_angle, gx_value, gy_value);

        }
    }
	
 //   int threshold = 211 ; //varies for application [0 768]
 //   output_image = max(mag,threshold)
 //   output_image(output_image==round(threshold))=0;

}
