#pragma once

greyscale_pixel get_extended_value(greyscale_image* image, int x, int y);
void convolve(greyscale_image* image, greyscale_image* gs_smooth, matrix* m);
