#pragma once
#include <stdint.h>

typedef struct greyscale_pixel {
  uint16_t pixel;
} gs_pixel;

typedef struct greyscale_image {
  uint32_t height;
  uint32_t width;
  greyscale_pixel* pixel;
} image;

greyscale_pixel getPixel(greyscale_image* image, uint32_t x, uint32_t y);
void setPixel(greyscale_image* image, uint32_t x, uint32_t y, greyscale_pixel pixel);
