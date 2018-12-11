#pragma once
#include <stdint.h>
#include <rgbPixel.h>
#include <string>

class RgbImage
{ 
    RgbPixel** image_data_;

    public:
        const int width;
        const int height;
    
    RgbImage(std::string fileName, int width, int height);
    
    RgbPixel GetRgbPixel(int x, int y);

}

