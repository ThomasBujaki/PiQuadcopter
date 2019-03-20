#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Matrix
{
    float* data_;

    public:
        const int width;
        const int height;
        
    
    Matrix(float* data, int width, int height);

    float GetValue(int x, int y);
    void SetValue(int x, int y, float newValue);
    void Print();

}
