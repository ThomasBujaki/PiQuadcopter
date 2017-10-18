#pragma once
#include <stdint.h>

typedef struct matrix {
  uint32_t height;
  uint32_t width;
  float * data;
} matrix;

float getMatrixValue(matrix* matrix, uint32_t x, uint32_t y);
void setMatrixValue(matrix* matrix, uint32_t x, uint32_t y, float newValue);
