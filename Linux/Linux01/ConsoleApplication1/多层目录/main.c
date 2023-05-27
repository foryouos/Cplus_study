#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int GetFile(const char* path)
{
	DIR* dir = opendir(path);
	if (dir == NULL) //如果目录 为空
	{
		perror("opendir NULL");
		return -1;
	}
	//遍历当前目录
	struct dirent* ptr = readdir(dir); //读目录的结构体，每次读一层
	int count = 0;
	while ((ptr = readdir(dir)) != NULL) //只要目录不为空，就一直遍历先去
	{
		//当文件名为.或者为..时，表示当前目录或者父级目录,则通过continue语句跳过，不做处理
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
		{
			continue;
		}
		else if (ptr->d_type == DT_DIR) //当读取的为目录类型
		{
			//目录
			char newPath[4096];
			sprintf(newPath, "%s/%s", path, ptr->d_name); //输出未见类型，并递归遍历
			count += GetFile(newPath);
		}
		else
		{
			//若为普通文件
			char* p = strstr(ptr->d_name, ".txt");
			if (p != NULL && *(p + 4) == '\0')
			{
				count++;
				printf("%s/%s\n", path, ptr->d_name);
			}
		}
		
	}
	closedir(dir);
	return count;

}



//传入目录参数
int main(int argc, char* argv[]) //在./a.out 传入参数目录，绝对路径
{
	if (argc < 2)
	{
		printf("./a.out path\n");
		return 0;
	}
	int num = GetFile(argv[1]);
	printf("%s .c :%d\n", argv[1], num);
	return 0;
}