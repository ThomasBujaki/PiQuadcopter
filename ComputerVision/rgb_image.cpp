#include "rgb_image.hpp"

#include <stdlib.h>

rgb_pixel get_rgb_pixel(rgb_image *image, uint32_t x, uint32_t y)
{
    return image->pixel[x + y * image->width];
}

void init_rgb_image(rgb_image *image, uint32_t height, uint32_t width)
{
    image->height = height;
    image->width = width;
    image->pixel = (rgb_pixel *)malloc(height * width * sizeof(rgb_pixel));
}

void destroy_rgb_image(rgb_image *image)
{
    free(image->pixel);
}
