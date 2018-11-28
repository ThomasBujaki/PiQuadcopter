#pragma once

typedef struct sobel_output {
    greyscale_image *sobel_gradient;
    matrix *sobel_angle;
} sobel_output;
