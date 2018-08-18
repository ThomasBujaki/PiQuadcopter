#include "sobel.h"

//work here next!
// to do: make convolve function that takes both x and y convolutions and gets gradient and angle on each pixel.
void *sobel(greyscale_image *image, greyscale_image* sobel_magnitude, matrix* angle) {
    matrix gx;
    matrix gy;	

    init_matrix(&gx, 3, 3);
    init_matrix(&gy, 3, 3);

    set_matrix(&gx, {-1f, 0f, 1f, -2f, 0f, 2f, -1f, 0f, 1f})
    set_matrix(&gy, {-1f, -2f, -1f, 0f, 0f, 0f, 1f, 2f, 1f})
    
    convolve(image, sobel_gradient, &gx);
    convolve(image, sobel_gradient, &gy);

    magnitude(); // mag(i+1,j+1)=sqrt(S1.^2+S2.^2)
	
    int threshold = 211 ; //varies for application [0 768]
    output_image = max(mag,threshold)
    output_image(output_image==round(threshold))=0;

}
