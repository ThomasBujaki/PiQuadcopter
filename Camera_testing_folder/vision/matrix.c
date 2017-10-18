#include <stdlib.h>
#include "matrix.h"

void init_matrix(matrix* m, uint32_t width, uint32_t height) {
  m->data = calloc(width*height, sizeof(float));
  m->width = width;
  m->height = height;
}

float get_matrix_value(matrix* m, uint32_t x, uint32_t y) {
  return m->data[x + y * m->height];
}

void set_matrix_value(matrix* m, uint32_t x, uint32_t y, float newValue) {
  m->data[x + y * m->height] = newValue;
}

void destroy_matrix(m* matrix) {
  free(m->data);
}