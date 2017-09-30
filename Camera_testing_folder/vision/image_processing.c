/*
*
*
********************************************************************************************************
*/

#include <stdio.h>
#include <stdint.h>
#include "image_processing.h"

/*
*Function: make_greyscale
*------------------------------------
* 	
*******************************************************************************************************
*/

int make_greyscale (rgb_pixel* rgb_buffer, gs_pixel* gs_buffer, uint32_t image_width, uint32_t image_height){

	for (int i=0; i < ((image_width*image_height)); i++){
	
		gs_buffer[i].pxl = (rgb_buffer[i].red + rgb_buffer[i].green + rgb_buffer[i].blue);
	
	} 
			
	return 0;
}

/*
*Function: sobel_x
*------------------------------------
* 	sobel x kernel:
*		-1	0	1	
*		-2	0	2
*		-1	0	1
*******************************************************************************************************
*/

int sobel_x (gs_pixel* gs_buffer,gs_pixel* sobel_x_buffer, uint32_t image_width, uint32_t image_height){

	int offset=0; 
	int temp;
	int kernel[3][3];

	kernel[0][0]=-1;
	kernel[0][1]=0;
	kernel[0][2]=1;
	kernel[1][0]=-2;
	kernel[0][1]=0;
	kernel[0][2]=2;
	kernel[2][0]=-1;
	kernel[0][1]=0;
	kernel[0][2]=1;
	
	for (int i=0; i < (image_width)*(image_height); i++){
		temp=0;
		for (int m=0; m < 3; m++){
			for (int n=0; n < 3; n++){
				temp = temp + kernel[m][n] * gs_buffer[i+offset+n];
			}
		offset = offet + image_width;
		}
		sobel_x_buffer[i].pxl = temp;
		if (i % (image_width - 2) == 0 ){
			i=i+4;
		}
	}

	return 0;
}


/*
*Function: 
*------------------------------------
* 	sobel y kernel:
*		1	2	1
*		0	0	0
*		-1	-2	-1
*******************************************************************************************************
*/

int sobel_y (gs_pixel* gs_buffer, uint32_t image_width, uint32_t image_height){
	
        int offset=0;           
        int temp;
        int kernel[3][3];

        kernel[0][0]=1;
        kernel[0][1]=2;
        kernel[0][2]=1;
        kernel[1][0]=0;
        kernel[0][1]=0;
        kernel[0][2]=0;
        kernel[2][0]=-1;
        kernel[0][1]=-2;
        kernel[0][2]=-1;

        for (int i=0; i < (image_width)*(image_height); i++){
                temp=0;
                for (int m=0; m < 3; m++){
                        for (int n=0; n < 3; n++){
                                temp = temp + kernel[m][n] * gs_buffer[i+offset+n];
                        }
                offset = offet + image_width;
                }
                sobel_x_buffer[i].pxl = temp;
                if (i % (image_width - 2) == 0 ){
                        i=i+4;
                }
        }

        return 0;

}
