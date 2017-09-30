#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image_processing.h"


int main (){
  // Read file.
  long length;
  FILE *f = fopen ("still-640x480.data", "rb");

  if (!f) {
    return -1;
  }

  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);

  rgb_pixel *raw_image = (rgb_pixel*)malloc (length);
  fread (raw_image, 1, length, f);
  fclose (f);

  // Run processing
  gs_pixel* image = image_processing(raw_image);

  // Save file
  FILE *pFile = fopen("greyscale.data", "wb"); 
  if (pFile){
    fwrite(image, (length*2/3), 1, pFile);
    fclose(pFile);
  }

  free(raw_image);
  free(image);

  return 0;
}
