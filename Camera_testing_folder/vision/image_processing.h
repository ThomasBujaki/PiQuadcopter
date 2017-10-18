#pragma once
#include <stdint.h>

typedef struct rgb_pixel {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
} rgb_pixel;


typedef struct gs_pixel {
	uint16_t pixel;
} gs_pixel;

#define HEIGHT 480
#define WIDTH  640

#define SMOOTH_HEIGHT HEIGHT-6
#define SMOOTH_WIDTH WIDTH-6

gs_pixel* image_processing(rgb_pixel* raw_image);
