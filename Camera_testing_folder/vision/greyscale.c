#include "greyscale.h"

#include "greyscale_image.h"
#include "rgb_image.h"

void convert_rgb_to_greyscale(rgb_pixel *rgb, greyscale_pixel *gs)
{
    gs->pixel = rgb->red + rgb->green + rgb->blue;
}

void make_greyscale(rgb_image *rgb_buffer, greyscale_image *gs_buffer)
{

    for (int i = 0; i < rgb_buffer->height; i++)
    {
        for (int j = 0; j < rgb_buffer->width; j++)
        {
            rgb_pixel rgb = get_rgb_pixel(rgb_buffer, i, j);
            greyscale_pixel gs = get_greyscale_pixel(gs_buffer, i, j);
            convert_rgb_to_greyscale(&rgb, &gs);
        }
    }
}
