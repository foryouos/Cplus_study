#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
//����Ŀ¼����
int main(int argc, char* argv[]) //��./a.out �������Ŀ¼������·��
{
	DIR* dir = opendir(argv[1]);   //���ļ�
	if (dir == NULL) //���Ŀ¼ Ϊ��
	{
		perror("opendir NULL");
		return -1;
	}
	//������ǰĿ¼�е��ļ�
	int count = 0;
	while (1) //ѭ������
	{
		struct dirent* ptr = readdir(dir); //��Ŀ¼�Ľṹ�壬ÿ�ζ�һ��
		if (ptr == NULL)  //���Ϊ��
		{
			printf("Ŀ¼������...\n");
			break;
		}
		//����һ���ļ����ж��ļ�����
		if (ptr->d_type == DT_REG) 
		{
			char* p = strstr(ptr->d_name, ".txt"); //�������
			if (p != NULL && *(p + 4) == '\0') //����ϸ����
			{
				count++;
				printf("file %d: %s\n", count, ptr->d_name);
			}
		}
	}
	printf("%sĿ¼��txt�ļ��ĸ�ʽ��%d\n", argv[1], count);
	closedir(dir); //�ر�Ŀ¼
	return 0;
}