#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Matrix
{
    float* data_;

    public:
        const int height;
        const int width;
    
    Matrix(float* data, int height, int width);

    float GetValue(int x, int y);
    void SetValue(int x, int y, float newValue);
    void Print();

}
