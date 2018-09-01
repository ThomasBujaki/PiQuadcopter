#include "gaussian_blur.h"

// note: we will want to change the parameters passed into the gauss_matrix function in the future to see if different variances or matrix sizes change the detection algorithms
void gauss_blur(greyscale_image* image, greyscale_image* gs_smooth) {
    matrix gaussian_matrix = gauss_matrix(1, 5);
    convolve(image, gs_smooth, &gaussian_matrix);
    destroy_matrix(&gaussian_matrix);
}
