
void convolve(greyscale_image* image, greyscale_image* gs_smooth, matrix* m){
  for(int x = 0; x < image.width; x++){
    for(int y = 0; y < image.width; y++){
      
    }
  }
}

void make_smooth(greyscale_image* image, greyscale_image* gs_smooth) {
  matrix gaussian_matrix = gauss_matrix();
  convolve(image, gs_smooth, gaussian_matrix);
}
