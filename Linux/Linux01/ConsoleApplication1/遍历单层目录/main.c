#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
//传入目录参数
int main(int argc, char* argv[]) //在./a.out 传入参数目录，绝对路径
{
	DIR* dir = opendir(argv[1]);   //打开文件
	if (dir == NULL) //如果目录 为空
	{
		perror("opendir NULL");
		return -1;
	}
	//遍历当前目录中的文件
	int count = 0;
	while (1) //循环遍历
	{
		struct dirent* ptr = readdir(dir); //读目录的结构体，每次读一层
		if (ptr == NULL)  //如果为空
		{
			printf("目录读完了...\n");
			break;
		}
		//读到一个文件，判断文件类型
		if (ptr->d_type == DT_REG) 
		{
			char* p = strstr(ptr->d_name, ".txt"); //输出名字
			if (p != NULL && *(p + 4) == '\0') //若明细不空
			{
				count++;
				printf("file %d: %s\n", count, ptr->d_name);
			}
		}
	}
	printf("%s目录中txt文件的格式：%d\n", argv[1], count);
	closedir(dir); //关闭目录
	return 0;
}