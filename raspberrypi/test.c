//#include "master.h"
#include "serial.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

int main()
{
	SerialPort				self;
	int						portNo=0;
	int						rt=0;
	char					buf[512];
	char					*str="I am Raspberry!";

	self=SerialPort_create(portNo,115200,8,'N',1);
	rt=SerialPort_open(self,portNo);
	if(rt<0)
	{
		printf("at line %s open serial failture!\n",__LINE__);
		return -1;
	}
	while(1)
	{
		rt=SerialPort_readByte(self->fd, buf,sizeof(buf));
		if(rt<0)
		{
			printf("at line %s read port failture!\n",__LINE__);

			close(self->fd);
			return -2;
		}
		printf("read %d bytes from buf is:%s\n",rt,buf);
		sleep(3);
		memset(buf,0,sizeof(buf));
		memcpy(buf,str,strlen(str));
		rt=SerialPort_write(self->fd, buf,0,strlen(str));
		if(rt<0)
		{
			printf("at line %s write port failture!\n",__LINE__);
			return -3;
		}
		printf("send %d bytes to buf is:%s\n",rt,buf);
	}
	return 0;
}

