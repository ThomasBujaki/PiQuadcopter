// put main here
// read file as binary.
// pass binary to image processing file
// get result.




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image_processing.h"


int main (){
  long length;
  FILE *f = fopen ("still-640x480.data", "rb");

  if (!f) {
    return -1;
  }

  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);

  rgb_pixel *raw_image = (rgb_pixel*)malloc (length);
  fread (rgb_buffer, 1, length, f);
  fclose (f);

  someType image = image_processing(raw_image);
  
  saveImage();

  return 0;
}
