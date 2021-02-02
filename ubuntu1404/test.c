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
	char					*str="I am Ubuntu!";

	self=SerialPort_create(portNo,115200,8,'N',1);
	rt=SerialPort_open(self,portNo);
	printf("rt:%d\n",rt);
	if(rt<0)
	{
		printf("at line %d open serial failture!\n",__LINE__);
		return -1;
	}
	printf("%s;line:%d\n",__FILE__,__LINE__);
	while(1)
	{
		rt=SerialPort_readByte(self->fd, buf,sizeof(buf));
		if(rt<0)
		{
			printf("at line %d read port failture!\n",__LINE__);
			close(self->fd);
			return -2;
		}

		printf("read %d bytes in buf:%s\n",rt,buf);
		sleep(3);
		memset(buf,0,sizeof(buf));
		memcpy(buf,str,strlen(str));
		rt=SerialPort_write(self->fd, buf,0,sizeof(buf));
		if(rt<0)
		{
			printf("at line %d write port failture!\n",__LINE__);
			return -3;
		}
		printf("send %d bytes to buf:%s\n",rt,buf);
	}
	return 0;
}

