#include "matrix.h"

float getMatrixValue(matrix* matrix, uint32_t x, uint32_t y) {
  return matrix->data[x + y * matrix->height];
}

void setMatrixValue(matrix* matrix, uint32_t x, uint32_t y, float newValue) {
  matrix->data[x + y * matrix->height] = newValue;
}