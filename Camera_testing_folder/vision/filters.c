/*
* This program takes in raw image data and applies various filters to it
*	Filters appiled:
*		Gaussian 
*		Sobel
*		Laplacian
*		Mean
********************************************************************************************************
*/

#include <stdio.h>
#include <stdint.h>

/*
*
********************************************************************************************************
*/

int main(){
	typedef struct pixel {
        	unsigned char red;
	        unsigned char green;
	        unsigned char blue;
	} pixel;

	pixel* buffer = 0;
	long length;
        FILE * f = fopen ("tree.data", "rb");

        if (f)
        {
                fseek (f, 0, SEEK_END);
                length = ftell (f);
                fseek (f, 0, SEEK_SET);
                buffer = (pixel*)malloc (length);
                if (buffer)
                {
                        fread (buffer, 1, length, f);
                }
                fclose (f);
        }

}

/*
*Function: gaussian_filter
*------------------------------------
* Applies the gaussian filter
********************************************************************************************************
*/
intptr_t *gaussian_filter(int *image_buffer_ptr){ // there are many differnt kernal sizes which can be used. don't currently know the best one
	
	


}







