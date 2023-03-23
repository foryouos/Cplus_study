#include <stack>
#include <iostream>
using namespace std;

int main(void)
{
	//����ջ
	stack<int> s;
	//��ջ������Ԫ��
	s.push(2);
	s.push(6);
	s.push(51);
	//���ջ������
	cout << s.size() << " elements on stack\n";
	//����ջ��Ԫ��
	cout << "s Top element:" << s.top() << endl;
	//ɾ��ջ��Ԫ��
	s.pop();
	//���ջ������
	cout << s.size() << "s elements on stack\n";

	stack<int> a;
	//��s������a���н���
	s.swap(a);
	cout << a.size() << "a elements on stack\n";
	//���a��ջ��Ԫ��
	cout << "a Top element:" << a.top() << endl;
	return 0;
}
/*
3 elements on stack
s Top element:51
2s elements on stack
2a elements on stack
a Top element:6
*/