#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	typedef struct pixel {
        uint_fast8_t red;
        uint_fast8_t green;
        uint_fast8_t blue;
    } pixel;
	
	pixel* buffer = 0;
	long length;
	FILE * f = fopen ("video-640x480.data", "rb");

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
	int iteration=0;
	pixel *pointer;

	for (int i=0; i<=length/3; i++){
        int discriminant = buffer[i].red + buffer[i].green + buffer[i].blue;
        if(discriminant > 255 * 3 / 5){
            	printf("1");
        }
	else{
            	printf(" ");
        }
        
		iteration++;
		if (iteration>=(640)){
			iteration=0;
			printf("\n");
		}
    }

	free(buffer);
	return 0;
}
