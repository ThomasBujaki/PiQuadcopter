#pragma once
#include <stdint.h>

typedef struct matrix {
  uint32_t height;
  uint32_t width;
  float * data;
} matrix;

void initMatrix(matrix* matrix, uint32_t width, uint32_t height);
float getMatrixValue(matrix* matrix, uint32_t x, uint32_t y);
void setMatrixValue(matrix* matrix, uint32_t x, uint32_t y, float newValue);
void destroyMatrix(matrix* matrix);