#include <iostream>
#include <map>
#include <string>
using namespace std;
//输出键值队map
auto print_map = [](auto const comment, map<string,int>&map)
{
	cout << comment ;
	//C++11方案
	for (const auto& pair : map)
	{
		cout << "{" << pair.first << ":" << pair.second << "}";
	}
	
	
	cout << endl;
};

int main()
{
	map<string, int> m{ {"cpu",10},{"GPU",15},{"RAM",20} };
	print_map("初始map:", m);
	//以不存在的键执行插入操作
	m["SSD"] = 30;
	print_map("插入不存在的：", m);
	//移除GPU
	m.erase("GPU");
	print_map("移除后：", m);
	//条件移除
	erase_if(m, [](const auto& pair) { return pair.second > 25; });
	print_map("条件移除后：", m);
	cout << m.size() << endl;

	m.clear();
	cout << boolalpha << "m是否为空:" << m.empty() << endl;
	return 0;
}
/*
初始map:{GPU:15}{RAM:20}{cpu:10}
插入不存在的：{GPU:15}{RAM:20}{SSD:30}{cpu:10}
移除后：{RAM:20}{SSD:30}{cpu:10}
条件移除后：{RAM:20}{cpu:10}
2
m是否为空:true

*/