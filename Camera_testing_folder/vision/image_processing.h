

#pragma once

typedef struct rgb_pixel {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
} rgb_pixel;

typedef struct gs_pixel {
	uint16_t pxl;
} gs_pixel;


typedef struct rgb_buffer {
  rgb_pixel* buffer,
  uint32_t width,
  uint32_t height
}

#define IMAGE_WIDTH 460


int make_greyscale (rgb_pixel* color_buffer, gs_pixel* greyscale_buffer, int image_width, int image_height);

int
