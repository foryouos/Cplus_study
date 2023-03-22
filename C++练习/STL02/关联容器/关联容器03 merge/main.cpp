#include <iostream>
#include <set>
using namespace std;

template <class Os,class K>
Os& operator<<(Os& os, const std::set<K>& v)
{
	//求出set的大小
	os << '[' << v.size() << "] {";
	bool o{};
	for (const auto& e : v)
	{
		//判断是否为空决定是，还是空
		os << (o ? ", " : (o = 1, " ")) << e;
	}
	return os << " }\n";
}
int main(void)
{
	set<char> 
		p{'C','B','B','A' },
		q{ 'E','D','E','C' };
	cout << "p: " << p << "q: " << q;
	//对set进行合并
	p.merge(q);
	//合并自动去重
	//q留下重复的部分
	cout << "p.merge(q):" << p << "q: " << q;

}
/*
p: [3] { A, B, C }
q: [3] { C, D, E }
p.merge(q):[5] { A, B, C, D, E }
q: [1] { C }
*/