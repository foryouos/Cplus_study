/*
* project : ��ŵ��CMD���ӻ�
* language��C
* time��2023��1��25��
* environment: VS2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
/*
*�����ͼ�����Ϣ
* @sleepTime:�ȴ�ʱ��
* @autoPlay:�Ƿ��Զ�����
* @wall��ǽ
* @pillar:����
* @hanoiLeft����ŵ��Բ�������ʾ
* @hanoiRight:��ŵ��Բ���ұ���ʾ
* @hanoiAir:��ŵ��Բ���м��οղ�����ʾ
*/
const int sleepTime = 5;  //ÿ���೤ʱ���ƶ�һ��
const int autoPlay = 1;  //�Ƿ��Զ����� 0�ֶ����ţ�
const char wall = '@';
const char pillar = '^';
const char hanoiLeft = '{';
const char hanoiRight = '}';
const char hanoiAir = '-';
const int up = 0, down = 1, left = 2, right = 3;
/*[�����ƶ�]
*@next_go ��һ���ƶ����� //��0,��1��2��3
*/
int next_go[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
/*ϵͳ����
*@abc_pillar[3][1000]  //��ǰ���ӷ��õ�Բ����
* [�߶ȣ�1���ȣ�2���ȣ�]
* [i][0]��ŵ�i�����ӵ�ǰ�߶�
* [i][j]��ʾ��i�����ӵ�j���ŵ�Բ�̴�С
* @abc_x[3] abc���ӵ�����
*	�������ֱ��ͨ��ABC-'A'ֱ�ӻ�ȡ�±�ȡֵ
*ȫ�ֱ���
* N�����ӵĲ���
* sum:��¼�ƶ����� 2^n -1;
*/
int N;
int sum; 
int abc_pillar[3][1000] = { {0},{0},{0} };
int abc_x[3] = { 0,0,0 };
int mapHeight, mapWidth;
int deep;

void gotoxy(int x, int y)//���ù��λ�ã������￪ʼ���
{
	COORD pos;//��ʾһ���ַ��ڿ���̨��Ļ�ϵ����꣬���Ͻǣ�0��0��
	pos.X = x;
	pos.Y = y;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//GetStdhandle���ڴ�һ���ض��ı�׼�豸����׼���롢��׼������׼������ȡ��һ�������������ʶ��ͬ�豸����ֵ��������Ƕ��ʹ�á�

	SetConsoleCursorPosition(handle, pos);
}
/*
*���x��y�ط��Ļ���
* ���һ�����һ������Ϊn�ĺ�ŵ��
*/
void drawHanoi(int& x, int& y, int n, int next) {
	// ���ԭ���� 
	char* replace = (char*)malloc(sizeof(char) * (2 * n + 1));

	for (int i = 0; i < 2 * n + 1; i++) {
		replace[i] = ' ';
		if (i == n && y != 1) {
			replace[i] = pillar;
		}
		if (i == 2 * n) {
			replace[i + 1] = '\0';
		}
	}
	gotoxy(x - n, y);
	printf("%s", replace);
	// �����µ� 
	if (next != -1) {
		x += next_go[next][0];
		y += next_go[next][1];
	}
	for (int i = 0; i < 2 * n + 1; i++) {
		if (i == n && y != 1) {
			replace[i] = pillar;
		}
		else if (i == 0) {
			replace[i] = hanoiLeft;
		}
		else if (i == 2 * n) {
			replace[i] = hanoiRight;
		}
		else {
			replace[i] = hanoiAir;
		}
		if (i == 2 * n) {
			replace[i + 1] = '\0';
		}
	}
	gotoxy(x - n, y);
	printf("%s", replace);
	Sleep(sleepTime);
}


//�������ع�꺯��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;     //�����α���Ϣ
	cursor.bVisible = FALSE;        //�����α겻�ɼ�
	cursor.dwSize = sizeof(cursor);  //�����α겻�ɼ�����ֵ
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);  //�������λ��
}
void move(char from, char to)
{
	gotoxy(0, mapHeight);
	printf("\n\t%c--->%c\n", from, to);
	sum++;
	printf("\n\t�ƶ�������%d", sum);
	//��ȡfrom�������ж��ٸ߶�λ���Ŀ�ʼ
	int fromHeight = abc_pillar[from - 'A'][0];  //��ȡfrom���ӷŵ�Բ����
	int n = abc_pillar[from - 'A'][fromHeight];//��ȡ����Բ�̴�С
	int x = abc_x[from - 'A'];//��ȡ��ǰ���ӵ�x����
	int y = 2 + N - fromHeight; //��ȡ��ǰy����
	abc_pillar[from - 'A'][0]--;//���������������
	//��ȡto�����Ӹ߶ȣ���λ���ǽ���
	abc_pillar[to - 'A'][0]++; //������λ��+1
	int toHeight = abc_pillar[to - 'A'][0]; //��ȡto���ӵ�Բ����
	abc_pillar[to - 'A'][toHeight] = n;//��������Բ�̴��ȥ
	int to_X = abc_x[to - 'A'];    //�ﵽx������
	int to_Y = 2 + N - toHeight;   //����y������
	//ȡ����--->����������
	while (y > 1)
	{
		drawHanoi(x, y, n, up);  //�ƶ��滭����
	}
	//�ƶ��̣��ƶ���ָ��λ��
	if (x < to_X)
	{
		while (x < to_X)
		{
			drawHanoi(x, y, n, right);
		}
	}
	else if (x > to_X)
	{
		while (x > to_X)
		{
			drawHanoi(x, y, n, left);
		}
	}
	//������---->�½�������
	while (y < to_Y)
	{
		drawHanoi(x, y, n, down);
	}
	//�ֶ�����
	if (0 == autoPlay )
	{
		gotoxy(0, mapHeight + 2);
		printf("�س�������һ��");
		getchar();
	}

}
void init() {
	// ��ʼ��������Ϣ 
	abc_pillar[0][0] = N;
	for (int i = 1; i <= N; i++) {
		abc_pillar[0][i] = N + 1 - i;
	}
	//�߶� = ����ǽ(2) + deep(4) + �Ͽ���(1) 
	//��� = ����ǽ(2) + 3������[3*(deep*2+1)] + �����м����(2)
	mapHeight = 2 + N + 1;
	mapWidth = 2 + 3 * (N * 2 + 1) + 2;

	//����0(a)ˮƽ���� = ���ǽ(1) + deep(4) 
	//����1(b)ˮƽ���� = ����1 + 2*deep + 2 
	//����2(c)ˮƽ���� = ����2 + 2*deep + 2 
	abc_x[0] = 1 + N;
	abc_x[1] = abc_x[0] + 2 * N + 2;
	abc_x[2] = abc_x[1] + 2 * N + 2;

	// ���Ƶ�ͼ
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			//ǽ����� 
			if (i == 0 || i == mapHeight - 1 || j == 0 || j == mapWidth - 1) {
				gotoxy(j, i);
				printf("%c", wall);
			}
			//��������
			else if (i > 1 && i < mapHeight - 1) {
				if (j == abc_x[0] || j == abc_x[1] || j == abc_x[2]) {
					//��ʼ������Բ��
					int abc_x_index = 0;
					if (j == abc_x[0]) abc_x_index = 0;
					else if (j == abc_x[1]) abc_x_index = 1;
					else if (j == abc_x[2]) abc_x_index = 2;
					drawHanoi(j, i, abc_pillar[abc_x_index][N - i + 2], -1);
				}
			}
		}
	}
}
/*
* ��ŵ���ݹ��㷨
* from ��ʼ��
* temp ��ת��
* to   �ƶ�Ŀ�ĵ�
*/
void hanoi(int n, char from, char temp, char to)
{
	if (1 == n)
	{
		move(from, to);//�ݹ��������
	}
	else
	{
		hanoi(n - 1, from, to, temp);
		move(from, to);
		hanoi(n - 1, temp, from, to);
	}
}

int main(void)
{
	HideCursor();
	printf("��Ҫ���Ĳ���:");
	scanf("%d", &N);
	init();
	getchar();//��ȡ����
	HideCursor();
	hanoi(N, 'A', 'B', 'C');

	getchar(); //����ʱ���˳�
	getchar();
	
	return 0;
}