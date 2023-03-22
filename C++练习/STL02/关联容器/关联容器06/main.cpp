#include <iostream>
#include <map>
#include <string>
using namespace std;
//�����ֵ��map
auto print_map = [](auto const comment, map<string,int>&map)
{
	cout << comment ;
	//C++11����
	for (const auto& pair : map)
	{
		cout << "{" << pair.first << ":" << pair.second << "}";
	}
	
	
	cout << endl;
};

int main()
{
	map<string, int> m{ {"cpu",10},{"GPU",15},{"RAM",20} };
	print_map("��ʼmap:", m);
	//�Բ����ڵļ�ִ�в������
	m["SSD"] = 30;
	print_map("���벻���ڵģ�", m);
	//�Ƴ�GPU
	m.erase("GPU");
	print_map("�Ƴ���", m);
	//�����Ƴ�
	erase_if(m, [](const auto& pair) { return pair.second > 25; });
	print_map("�����Ƴ���", m);
	cout << m.size() << endl;

	m.clear();
	cout << boolalpha << "m�Ƿ�Ϊ��:" << m.empty() << endl;
	return 0;
}
/*
��ʼmap:{GPU:15}{RAM:20}{cpu:10}
���벻���ڵģ�{GPU:15}{RAM:20}{SSD:30}{cpu:10}
�Ƴ���{RAM:20}{SSD:30}{cpu:10}
�����Ƴ���{RAM:20}{cpu:10}
2
m�Ƿ�Ϊ��:true

*/