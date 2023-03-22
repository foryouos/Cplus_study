#include <iostream>
#include <map>
#include <string>
using namespace std;
//输出键值队map
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
	print("letter_counts初始状态下包含:", letter_counts);

	letter_counts['b'] = 42;
	letter_counts['x'] = 9;
	print("修改后的值", letter_counts);

	//统计每个单词出现的次数
	map<string, int> word_map;
	for (const auto& w : { "this","sentence","is","not","a","sentence","this","sentence","is","a","hoax" })
	{
		++word_map[w];
	}
	word_map["that"]; //插入对{"that",0}

	print("输出map:",word_map);
	
}