/*
*
*
********************************************************************************************************
*/

#include <stdio.h>
#include <stdint.h>

/*
*Function: make_greyscale
*------------------------------------
* 	
*******************************************************************************************************
*/

int make_greyscale (rgb_pixel* color_buffer, gs_pixel* greyscale_buffer, int image_width, int image_height){
		
	for (int i=0; i < (image_width*image_height); i++){
		
		greyscale_buffer[i]=color_buffer[i].red + color_buffer[i].green + color_buffer[i].blue;
		
	} 
			
	return 0;
}
