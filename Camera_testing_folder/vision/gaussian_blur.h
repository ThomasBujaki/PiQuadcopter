#pragma once
#include "greyscale_image.h"
#include "gaussian_matrix.h"

greyscale_pixel get_extended_value(greyscale_image* image, int x, int y);
void convolve(greyscale_image* image, greyscale_image* gs_smooth, matrix* m);
void make_smooth(greyscale_image* image, greyscale_image* gs_smooth);
