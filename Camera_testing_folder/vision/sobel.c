#include "sobel.h"

set_magnitude(uint16_t );

//work here next!
// to do: make convolve function that takes both x and y convolutions and gets gradient and angle on each pixel.
void *sobel(greyscale_image *image, greyscale_image* sobel_magnitude, matrix* angle) {
    matrix gx;
    matrix gy;	

    init_matrix(&gx, 3, 3);
    init_matrix(&gy, 3, 3);

    set_matrix(&gx, {-1f, 0f, 1f, -2f, 0f, 2f, -1f, 0f, 1f})
    set_matrix(&gy, {-1f, -2f, -1f, 0f, 0f, 0f, 1f, 2f, 1f})

    //convolution 
    for(int x = 0; x < image->width; x++) {
        for(int y = 0; y < image->height; y++) {

            //gx
            uint16_t gx_value = get_mod_pixel_value(gx, image, x, y);
            //gy
            uint16_t gy_value = get_mod_pixel_value(gy, image, x, y);
            //magnitude
            set_magnitude(sobel_magnitude, gx_value, gy_value);
            //angle
            set_angle();

        }
    }
	
    int threshold = 211 ; //varies for application [0 768]
    output_image = max(mag,threshold)
    output_image(output_image==round(threshold))=0;

}
