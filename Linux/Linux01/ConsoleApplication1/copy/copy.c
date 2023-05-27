#include <sys/stat.h>
#include <stdio.h>
int main(void)
{
	//定义结构体存储文件休息
	struct stat myst;
	int ret = stat("./english.txt", &myst);
	if (ret == -1)
	{
		perror("stat error"); //失败
	}
	printf("文件大小为:%d\n", (int)myst.st_size);
	return 0;
}