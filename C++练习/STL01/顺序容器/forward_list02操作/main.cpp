#include <iostream>
#include <forward_list>
#include <list>
using namespace std;
ostream& operator<<(ostream& ostr, const forward_list<int>& list)
{
	for (auto& i : list)
	{
		ostr << " " << i;
	}
	return ostr;
}
int main(void)
{
	forward_list<int> list1 = { 5,9,1,3,3,3,9};
	forward_list<int> list2 = { 8,7,2,3,4,5 };
	forward_list<int> list3 = { 66,99,33 };
	//���б�����
	list1.sort();
	list2.sort();  
	cout << "list1" << list1 << endl;
	cout << "list2" << list2 << endl;
	list1.merge(list2); //�ϲ���list2Ϊ��
	cout << "�ϲ���" << list1 << endl;
	//����
	list1.splice_after(list1.cbegin(), list3,list3.cbegin(), list3.cend());

	cout << "�����" << list1 << endl;
	//�Ƴ�����������ֵ
	list1.remove(1);//�Ƴ�����1��
	cout << "�Ƴ�1��" << list1 << endl;
	//�Ƴ�n����10��
	list1.remove_if([](int n) { return n > 10; });
	cout << "�Ƴ�����10��" << list1 << endl;
	//������Ԫ�ط�ת
	list1.reverse();
	cout << "�б�ת��" << list1 << endl;
	//ɾ���ظ�Ԫ��
	list1.unique();
	cout << "ȥ�غ�" << list1 << endl;
	return 0;
}
/*
list1 1 3 3 3 5 9 9
list2 2 3 4 5 7 8
�ϲ��� 1 2 3 3 3 3 4 5 5 7 8 9 9
����� 1 99 33 2 3 3 3 3 4 5 5 7 8 9 9
�Ƴ�1�� 99 33 2 3 3 3 3 4 5 5 7 8 9 9
�Ƴ�����10�� 2 3 3 3 3 4 5 5 7 8 9 9
�б�ת�� 9 9 8 7 5 5 4 3 3 3 3 2
ȥ�غ� 9 8 7 5 4 3 2
*/