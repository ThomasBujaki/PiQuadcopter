
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image_processing.h"


int main (){
	
	int image_width = 640;
	int image_height = 480;

	rgb_pixel *rgb_buffer = 0;
	gs_pixel *gs_buffer = 0;
	long length;
        FILE *f = fopen ("still-640x480.data", "rb");

        if (f)
        {
                fseek (f, 0, SEEK_END);
                length = ftell (f);
		fseek (f, 0, SEEK_SET);
                rgb_buffer = (rgb_pixel*)malloc (length);
		gs_buffer = (gs_pixel*)malloc (length*2/3);
		sobel_x_buffer = (gs_pixel*)mallox (length*2/3);
		sobel_y_buffer = (gs_pixel*)mallox (length*2/3);
                if (rgb_buffer)
                {
                        fread (rgb_buffer, 1, length, f);
                }
                fclose (f);
        }
/*	for (int i=0; i<307200; i++){
		printf("iteration %d, buffer val %ld\n", i, gs_buffer[i].grey);	
	}
*/ 
	
	make_greyscale(rgb_buffer, gs_buffer, image_width, image_height);
	
	sobel_x(gs_buffer, sobel_x_buffer, image_width, image_height);
	sobel_y(gs_buffer, sobel_x_buffer, image_width, image_height);
	
	printf("sizeof 16 %ld\n ", sizeof(uint_fast16_t));	
	printf("sizeof 8 %ld\n ", sizeof(uint_fast8_t));	
	printf("sizeof grey %ld\n", sizeof(gs_buffer[0].grey));	
	printf("sizeof rgb_pixel start %ld\n", sizeof(rgb_pixel));	
	printf("sizeof gs_pixel start %ld\n", sizeof(gs_pixel));	
	
   	FILE *pFile = fopen("greyscale.data", "wb"); 
	if (pFile){
		fwrite(gs_buffer, (length*2/3), 1, pFile);
		printf(" printed");
		fclose(pFile);
	}
	
        free(rgb_buffer);
	free(gs_buffer);
	free(sobel_x_buffer);
	free(sobel_y_buffer);
        return 0;

}
