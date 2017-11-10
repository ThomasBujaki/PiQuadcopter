#include "greyscale_image.h"
#include "gaussian_matrix.h"

greyscale_pixel get_extended_value(greyscale_image* image, int x, int y) {
  if(x > image->width){
    x = image->width - 1;
  }
  if(x < 0){
    x = 0;
  }
  if(y > image->height){
    y = image->height - 1;
  }
  if(y < 0){
    y = 0;
  }
  return get_pixel(image, x, y);
}

void convolve(greyscale_image* image, greyscale_image* gs_smooth, matrix* m){
  for(int x = 0; x < image->width; x++){
    for(int y = 0; y < image->height; y++){
      greyscale_pixel smoothed_pixel_value = 0;
      for(int matrix_x = 0; matrix_x < m->width; matrix_x++){
        for(int matrix_y = 0; matrix_y < m->height; matrix_y++){
          int convolution_x = x - (m->width / 2) + matrix_x;
          int convolution_y = y - (m->height / 2) + matrix_y;
          greyscale_pixel input_pixel_value = get_extended_value(image, x, y);
          float matrix_value = get_matrix_value(m, matrix_x, matrix_y);
          smoothed_pixel_value += input_pixel_value * matrix_value;
        }
      }
      set_pixel(gs_smooth, x, y, smoothed_pixel_value);
    }
  }
}
// note: we will want to change the parameters passed into the gauss_matrix function in the future to see if different variances or matrix sizes change the detection algorithms
void make_smooth(greyscale_image* image, greyscale_image* gs_smooth) {
  matrix gaussian_matrix = gauss_matrix(1, 5);
  convolve(image, gs_smooth, gaussian_matrix);
}
