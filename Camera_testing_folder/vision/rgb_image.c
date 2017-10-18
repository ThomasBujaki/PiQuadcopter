#include "rgb_image.h"

rgb_pixel getPixel(rgb_image* image, uint32_t x, uint32_t y) {
  return image.pixel[x + y * image.height];
}
