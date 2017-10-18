#pragma once
#include <stdint.h>

typedef struct greyscale_pixel
{
    uint16_t pixel;
} greyscale_pixel;

typedef struct greyscale_image
{
    uint32_t height;
    uint32_t width;
    greyscale_pixel *pixel;
} greyscale_image;

greyscale_pixel get_greyscale_pixel(greyscale_image *image, uint32_t x, uint32_t y);

void init_greyscale_image(greyscale_image *image, uint32_t height, uint32_t width);
void destroy_greyscale_image(greyscale_image *image);
