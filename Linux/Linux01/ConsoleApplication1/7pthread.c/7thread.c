#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	//����ļ�״̬������ʧ�ܷ���-1���ļ������ڣ����ط�����ʼ�������
	int fd = open("./new.txt", O_CREAT | O_EXCL | O_RDWR);
	if (fd == -1)
	{
		printf("file open fail\n");
	}
	else
	{
		printf("create file successful fd:%d\n", fd);
	}
	close(fd); //�ر��ļ�
	return 0;
}