
#pragma once

#include "image_processing.h"
#include <stdint.h>

int make_greyscale (rgb_pixel* rgb_buffer, gs_pixel* gs_buffer, uint32_t image_width, uint32_t image_height);

