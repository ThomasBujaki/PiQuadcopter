#import "greyscale.h"
/*
 *
 *
 ********************************************************************************************************
 */

/*
 *Function: make_greyscale
 *------------------------------------
 * 	
 *******************************************************************************************************
 */

int make_greyscale (rgb_pixel* rgb_buffer, gs_pixel* gs_buffer, uint32_t image_width, uint32_t image_height) {

	for (int i = 0; i < (image_width*image_height); i++) {
		gs_buffer[i].pixel = rgb_buffer[i].red + rgb_buffer[i].green + rgb_buffer[i].blue;

	} 

	return 0;
}
