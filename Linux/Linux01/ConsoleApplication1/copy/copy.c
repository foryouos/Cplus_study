#include <sys/stat.h>
#include <stdio.h>
int main(void)
{
	//����ṹ��洢�ļ���Ϣ
	struct stat myst;
	int ret = stat("./english.txt", &myst);
	if (ret == -1)
	{
		perror("stat error"); //ʧ��
	}
	printf("�ļ���СΪ:%d\n", (int)myst.st_size);
	return 0;
}