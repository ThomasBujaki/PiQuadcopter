#include <stdio.h>
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>			//Used for UART
#include <errno.h>			//Use
#include <stdint.h>

void display_MSP_message(unsigned char * message_data, int message_length) {
	if(message_length < 6) {
		printf("Not a valid MSP message");
		return;
	}
	if(message_data[0] != '$' || message_data[1] != 'M') {
		printf("Invalid preamble on MSP message");
		return;
	}
	if(message_data[2] == '<') {
		printf("Incoming message\n");
	} else if (message_data) {
		printf("Outgoing message\n");
	} else {
		printf("The direction on this MSP message is not valid, found %c, was expecting \'<\' or \'>\'");
		return;
	}
	int message_size = message_data[3];
	printf("Size: %d\n", message_size);
	printf("Command: %d\n", message_data[4]);
	if(5 + message_size > message_length) {
		printf("We don't have the full MSP message :(");
	}
        int i = 0;
	for(i = 0; i < message_size; i++) {
		printf("Data[%d] = %d\n", i, message_data[5 + i]);
	}
}

int main(){
	//-------------------------
	//----- SETUP USART 0 -----
	//-------------------------
	//At bootup, pins 8 and 10 are already set to UART0_TXD, UART0_RXD (ie the alt0 function) respectively
	int uart0_filestream = -1;
	
	//OPEN THE UART
	//The flags (defined in fcntl.h):
	//	Access modes (use 1 of these):
	//		O_RDONLY - Open for reading only.
	//		O_RDWR - Open for reading and writing.
	//		O_WRONLY - Open for writing only.
	//
	//	O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
	//											if there is no input immediately available (instead of blocking). Likewise, write requests can also return
	//											immediately with a failure status if the output can't be written immediately.
	//
	//	O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.
	uart0_filestream = open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);		//Open in non blocking read/write mode
	if (uart0_filestream == -1)
	{
		//ERROR - CAN'T OPEN SERIAL PORT
		printf("Error - Unable to open UART.  Ensure it is not in use by another application\n");
	}
	else
	{
		printf("everting seems ok\n");
	}
	//CONFIGURE THE UART
	//The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
	//	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
	//	CSIZE:- CS5, CS6, CS7, CS8
	//	CLOCAL - Ignore modem status lines
	//	CREAD - Enable receiver
	//	IGNPAR = Ignore characters with parity errors
	//	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
	//	PARENB - Parity enable
	//	PARODD - Odd parity (else even)
	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;		//<Set baud rate
//	printf("%d\n",options.c_cflag);
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	//tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);
//while(1){	
	//----- TX BYTES -----
	unsigned char tx_buffer[200];
	unsigned char *p_tx_buffer;
	
	unsigned char command = 101;
	unsigned char size = 0;
	unsigned char crc = size ^ command;

	p_tx_buffer = &tx_buffer[0];
	*p_tx_buffer++ = '$'; // $M is the preable
	*p_tx_buffer++ = 'M';
	*p_tx_buffer++ = '<'; 
	*p_tx_buffer++ = size; 
	*p_tx_buffer++ = command; 
/*	int j;
	for (j = 0 ; j < 4 ; j++){
		
		uint16_t motor_val = 1800;	

	        if(j == 3) {
			motor_val = 1200;
		} 
	
		
		unsigned char lower_byte = motor_val & 0xff;
		unsigned char upper_byte = motor_val >> 8;

		*p_tx_buffer++ = lower_byte; 
		*p_tx_buffer++ = upper_byte;

		printf("Low: %d\n", lower_byte);
		printf("High: %d\n", upper_byte);
		
		crc = crc ^ lower_byte;
		crc = crc ^ upper_byte; 
		
	}  */
	*p_tx_buffer++ = crc; // checksum

//	*p_tx_buffer++ = '*';
		
	if (uart0_filestream != -1)
	{
		int count = write(uart0_filestream, &tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));		//Filestream, bytes to write, number of bytes to write
		//printf("%d", (p_tx_buffer - &tx_buffer[0]));
		printf("Bytes Written: %d\n", count);
		if (count < 0)
		{
			printf("UART TX error\n");
		}
	}
//}
	//----- CHECK FOR ANY RX BYTES -----
	if (uart0_filestream != -1)
	{
		// Read up to 255 characters from the port if they are there
		unsigned char master_rx_buffer[256];
		int master_rx_length = 0;
		int counter = 0;
		do {
			int j;
			for(j = 0; j < 10000; j++) {

			}
			unsigned char rx_buffer[256];
			int rx_length = read(uart0_filestream, (void*)rx_buffer, 255);		//Filestream, buffer to store in, number of bytes to read (max)
			if (rx_length < 0)
			{
				//An error occured (will occur if there are no bytes)
				//printf("Nothing in the buffer yet error == %d\n", rx_length);
				//printf("Errno raw value %ld", errno);
				//printf("Errno %s", strerror(errno));
			}
			else if (rx_length == 0)
			{
				//No data waiting
				printf("zero data returned\n");
			}
			else
			{
				//Bytes received
				rx_buffer[rx_length] = '\0';
				printf("%i bytes read : %s\n", rx_length, rx_buffer);
				int i;
				for(i = 0; i < rx_length; i++) {
					master_rx_buffer[master_rx_length] = rx_buffer[i];
					master_rx_length++;
				}	
			}
			counter++;
		} while(counter < 1000);
		display_MSP_message(master_rx_buffer, master_rx_length);
	}
	
	//----- CLOSE THE UART -----
	close(uart0_filestream);
	
}
