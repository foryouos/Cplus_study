#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void func(int num, string str)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "���̣߳�i = " << i << ", num: " << num << ", str :" << str << endl;
		//��ǰ�߳�����500ms
		this_thread::sleep_for(chrono::microseconds(500));
	}
	
}
void func1()
{
	for (int j = 0; j < 10; j++)
	{
		cout << "���̣߳�j = " << j << endl;
		//��ǰ�߳�����500ms
		this_thread::sleep_for(chrono::microseconds(500));
	}
}
int main(void)
{
	//��ȡ��ǰCPU��������
	//ÿ���̶߳���ռ��һ��CPU���ģ���Щ�߳̾Ͳ��÷�ʱ����CPUʱ��Ƭ����ʱ���򲢷�Ч�����
	cout << "��ǰ�������CPU������" << thread::hardware_concurrency() << endl;

	cout << "���߳�id :" << this_thread::get_id() << endl; //��ȡ�߳�id
	//���ù��캯���������ֳ���t��t1
	//ͬʱ���ò��������̺߳������������
	thread t(func, 520, "I Love You");
	thread t1(func1);
	// ������߳�id
	cout << "���߳� t ID �� " << t.get_id() << endl;;
	cout << "���߳� t1 ID �� " << t1.get_id() <<endl;
	//���߳���ִ����ϣ�
	
#if 0
	//1,�ȵ����߳̽����������̼߳��뵽��ǰ�̵߳���
	t.join();
	t1.join();
#else if 1
	//2�����߳������̷߳��룬���߳�������ϣ��ͷſռ䣬���߳̿����������̼߳������У������������֮�����߲���Զ��ͷ��Լ�ռ�õ�ϵͳ��Դ
	t.detach();
	t1.detach();
#endif // 0
	cout << "���߳̽���!!" << endl;
	//���̵߳ȴ����߳����н������ȴ�5��
	this_thread::sleep_for(chrono::microseconds(5000));
	//���������е��ӳ����޷������������ֵ�����Ļ��
	return 0;
}