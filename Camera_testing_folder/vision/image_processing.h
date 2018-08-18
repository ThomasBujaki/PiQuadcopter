#pragma once
#include <stdint.h>
#include "greyscale_image.h"
#include "rgb_image.h"
#include "gaussian_blur.h"
#include "rgb_image.h"
#include "greyscale.h"
#include "greyscale_image.h"
#include "sobel.h"

greyscale_image *image_processing(rgb_image *raw_image);
