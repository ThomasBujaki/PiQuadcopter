#pragma once
#include <stdint.h>
#include "greyscale_image.h"
#include "rgb_image.hpp"
#include "gaussian_blur.h"
#include "greyscale.h"
#include "greyscale_image.h"
#include "sobel.h"
#include "sobel_output.h"

greyscale_image *image_processing(rgb_image *raw_image);

