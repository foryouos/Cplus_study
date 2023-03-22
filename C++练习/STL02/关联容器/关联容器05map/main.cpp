#include <iostream>
#include <map>
#include <string>
using namespace std;
//�����ֵ��map
auto print = [](auto const comment, auto const& map)
{
	cout << comment << "{";
	for (const auto& pair : map)
	{
		cout << "{" << pair.first << ":" << pair.second << "}";
	}
	cout << endl;
};

int main()
{
	map<char,int> letter_counts { {'a',27},{'b',3},{'c',1} };
	print("letter_counts��ʼ״̬�°���:", letter_counts);

	letter_counts['b'] = 42;
	letter_counts['x'] = 9;
	print("�޸ĺ��ֵ", letter_counts);

	//ͳ��ÿ�����ʳ��ֵĴ���
	map<string, int> word_map;
	for (const auto& w : { "this","sentence","is","not","a","sentence","this","sentence","is","a","hoax" })
	{
		++word_map[w];
	}
	word_map["that"]; //�����{"that",0}

	print("���map:",word_map);
	
}