#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void init_matrix(matrix* m, uint32_t width, uint32_t height) {
  m->data = calloc(width*height, sizeof(float));
  m->width = width;
  m->height = height;
}

float get_matrix_value(matrix* m, uint32_t x, uint32_t y) {
  return m->data[x + y * m->height];
}

void set_matix(matrix* m, float* data) {
  memcpy(m->data, data);
}

void set_matrix_value(matrix* m, uint32_t x, uint32_t y, float newValue) {
  m->data[x + y * m->height] = newValue;
}

void destroy_matrix(matrix* m) {
  free(m->data);
}

void print_matrix(matrix* m) {
 for (int y=0; y < m->height; y++ ) {
    for (int x=0; x < m->width; x++ ) {
      printf("\t%.2f", get_matrix_value(m, x, y));
    }
  printf("\n");
  }
}
