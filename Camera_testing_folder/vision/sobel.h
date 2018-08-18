#pragma once
#include "greyscale_image.h"
#include "matrix.h"
#include "matrix_operations.h"
#include <math.h>


void *sobel(greyscale_image *image, greyscale_image* sobel_magnitude, matrix* sobel_angle);
