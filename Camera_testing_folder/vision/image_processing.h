

#pragma once

typedef struct rgb_pixel {
        uint_fast8_t red;
        uint_fast8_t green;
        uint_fast8_t blue;
} rgb_pixel;

typedef struct gs_pixel {
	uint_fast16_t grey;
} gs_pixel;


int make_greyscale (rgb_pixel* color_buffer, gs_pixel* greyscale_buffer; int image_width, int image_height);

