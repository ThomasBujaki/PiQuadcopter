#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct matrix {
    uint32_t height;
    uint32_t width;
    float * data;
} matrix;

void init_matrix(matrix* m, uint32_t width, uint32_t height);
float get_matrix_value(matrix* m, uint32_t x, uint32_t y);
void set_matrix(matrix* m, float* data, uint32_t size);
void set_matrix_value(matrix* m, uint32_t x, uint32_t y, float newValue);
void destroy_matrix(matrix* m);
void print_matrix(matrix* m);
