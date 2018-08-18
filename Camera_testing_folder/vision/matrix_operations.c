#include "matrix_operations.h"

int get_x_value(greyscale_image* image, int x) {
  if(x > image->width) {
    return image->width - 1;
  } else if(x < 0) {
    return 0;
  }
  return x;
}

int get_y_value(greyscale_image* image, int y) {
  if(y > image->height) {
    return image->height - 1;
  } else if(y < 0) {
    return 0;
  }
  return y;
}

greyscale_pixel get_extended_value(greyscale_image* image, int x, int y) {
  int x_val = get_x_value(image, x); 
  int y_val = get_y_value(image, y); 
  return get_greyscale_pixel(image, x_val, y_val);
}

void convolve(greyscale_image* image, greyscale_image* convolved_image, matrix* m) {
  for(int x = 0; x < image->width; x++) {
    for(int y = 0; y < image->height; y++) {
      greyscale_pixel mod_pixel_value;
      mod_pixel_value.pixel = get_mod_pixel_value(m, image, x, y);
      set_greyscale_pixel(convolved_image, x, y, mod_pixel_value);
    }
  }
}

uint16_t get_mod_pixel_value(matrix* m, greyscale_image* image, int x, int y) {
    uint16_t value = 0;
    for(int matrix_x = 0; matrix_x < m->width; matrix_x++) {
      for(int matrix_y = 0; matrix_y < m->height; matrix_y++) {
        int convolution_x = x - (m->width / 2) + matrix_x;
        int convolution_y = y - (m->height / 2) + matrix_y;
        greyscale_pixel input_pixel_value = get_extended_value(image, convolution_x, convolution_y);
        float matrix_value = get_matrix_value(m, matrix_x, matrix_y);
        value += (float)input_pixel_value.pixel * matrix_value;
      }   
    }   
    return value;
}
