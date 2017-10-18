#include "greyscale_image.h"

#include <stdlib.h>

greyscale_pixel get_greyscale_pixel(greyscale_image *image, uint32_t x, uint32_t y)
{
    return image->pixel[x * image->width + y];
}

void init_greyscale_image(greyscale_image *image, uint32_t height, uint32_t width)
{
    image->height = height;
    image->width = width;
    image->pixel = (greyscale_pixel *)malloc(height * width * sizeof(greyscale_pixel));
}

void destroy_greyscale_image(greyscale_image *image)
{
    free(image->pixel);
}
