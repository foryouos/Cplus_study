#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	//检查文件状态，创建失败返回-1，文件不存在，返回分配的问价描述符
	int fd = open("./new.txt", O_CREAT | O_EXCL | O_RDWR);
	if (fd == -1)
	{
		printf("file open fail\n");
	}
	else
	{
		printf("create file successful fd:%d\n", fd);
	}
	close(fd); //关闭文件
	return 0;
}