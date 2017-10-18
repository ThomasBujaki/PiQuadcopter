#pragma once
#include <stdint.h>

typedef struct rgb_pixel {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} rgb_pixel;

typedef struct greyscale_pixel {
  uint16_t pixel;
} gs_pixel;

typedef struct greyscale_image {
  uint32_t height;
  uint32_t width;
  greyscale_pixel* pixel;
} image;

typedef struct rgb_image {
  uint32_t height;
  uint32_t width;
  rgb_pixel* pixel;
} rgb_image;


 get_t rgb_pixel
