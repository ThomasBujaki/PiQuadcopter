#include <stdio.h>

int main()
{

	unsigned char buffer[1290240];
	FILE *ptr;
	
	ptr = fopen("video-672x480.rgba","rb");  // r for read, b for binary
	
	fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to our buffer
	
	for(int i = 0; i<1290241; i++){ 
	//	if ((i+1) % 4 != 0 ) {
			printf("%u ", buffer[i]); 
	//	}
//		if ((i+1) % (672*4) ==0){
//			printf("\n");
//		}
	}// prints a series of bytes
	
	FILE *write_ptr;

	write_ptr = fopen("test.bin","wb");  // w for write, b for binary

	fwrite(buffer,sizeof(buffer),1,write_ptr); // write 10 bytes from our buffer
}
