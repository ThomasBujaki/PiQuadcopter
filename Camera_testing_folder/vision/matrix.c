#include "matrix.h"

void initMatrix(matrix* matrix, uint32_t width, uint32_t height) {
  matrix->data = calloc(1, sizeof(matrix));
  matrix->width = width;
  matrix->height = height;
}

float getMatrixValue(matrix* matrix, uint32_t x, uint32_t y) {
  return matrix->data[x + y * matrix->height];
}

void setMatrixValue(matrix* matrix, uint32_t x, uint32_t y, float newValue) {
  matrix->data[x + y * matrix->height] = newValue;
}

void destroyMatrix(matrix* matrix) {
  free(matrix->data);
}