#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>

#include<wiringPi.h>
#include<wiringSerial.h>

int main()
{
	printf("<code>\n");
	int fd;

	//fd = open("/dev/ttyA0", O_RDWR);
	if((fd = serialOpen("/dev/ttyACM0",115200)) < 0)
	{
		printf("error_fd\n");
		return(1);		
	}
	printf("serial test start...\n");

	//serialPrintf(fd, "\r";
	
	while(serialDataAvail(fd))
	{
		printf("%c", serialGetchar(fd));
	}
	serialClose(fd);
	return(0);
}

