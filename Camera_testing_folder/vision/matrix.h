#pragma once
#include <stdint.h>

typedef struct matrix {
  uint32_t height;
  uint32_t width;
  float * data;
} matrix;

void init_matrix(matrix* m, uint32_t width, uint32_t height);
float get_matrix_value(matrix* m, uint32_t x, uint32_t y);
void set_matix(matrix* m, float* data);
void set_matrix_value(matrix* m, uint32_t x, uint32_t y, float newValue);
void destroy_matrix(matrix* m);
void print_matrix(matrix* m);
