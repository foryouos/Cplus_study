#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int GetFile(const char* path)
{
	DIR* dir = opendir(path);
	if (dir == NULL) //���Ŀ¼ Ϊ��
	{
		perror("opendir NULL");
		return -1;
	}
	//������ǰĿ¼
	struct dirent* ptr = readdir(dir); //��Ŀ¼�Ľṹ�壬ÿ�ζ�һ��
	int count = 0;
	while ((ptr = readdir(dir)) != NULL) //ֻҪĿ¼��Ϊ�գ���һֱ������ȥ
	{
		//���ļ���Ϊ.����Ϊ..ʱ����ʾ��ǰĿ¼���߸���Ŀ¼,��ͨ��continue�����������������
		if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
		{
			continue;
		}
		else if (ptr->d_type == DT_DIR) //����ȡ��ΪĿ¼����
		{
			//Ŀ¼
			char newPath[4096];
			sprintf(newPath, "%s/%s", path, ptr->d_name); //���δ�����ͣ����ݹ����
			count += GetFile(newPath);
		}
		else
		{
			//��Ϊ��ͨ�ļ�
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



//����Ŀ¼����
int main(int argc, char* argv[]) //��./a.out �������Ŀ¼������·��
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