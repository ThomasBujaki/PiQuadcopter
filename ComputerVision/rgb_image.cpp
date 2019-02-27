#include "rgb_image.hpp"

#include <stdlib.h>

RgbImage::RgbImage(std::string fileName, int width, int height): width(width), height(height)
{
    this->image_data_ = (RgbPixel**)malloc(width * height * sizeof(RgbPixel));
}

RgbPixel RgbImage::GetRgbPixel(int x, int y)
{
    return this->image_data_[x][y];
}

RgbImage::~RgbImage()
{
    free(this->image_data_);
}
