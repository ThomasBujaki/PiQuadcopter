#pragma once
#include "greyscale_image.h"
#include "matrix.h"

greyscale_pixel get_extended_value(greyscale_image* image, int x, int y);
void convolve(greyscale_image* image, greyscale_image* gs_smooth, matrix* m);
uint16_t get_mod_pixel_value(matrix* m, greyscale_image* image, int x, int y);
