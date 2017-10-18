#include "greyscale_image.h"

greyscale_pixel getPixel(greyscale_image* image, uint32_t x, uint32_t y) {
  return image.pixel[x + y * image.height];
}
