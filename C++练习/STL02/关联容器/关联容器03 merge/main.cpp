#include <iostream>
#include <set>
using namespace std;

template <class Os,class K>
Os& operator<<(Os& os, const std::set<K>& v)
{
	//���set�Ĵ�С
	os << '[' << v.size() << "] {";
	bool o{};
	for (const auto& e : v)
	{
		//�ж��Ƿ�Ϊ�վ����ǣ����ǿ�
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
	//��set���кϲ�
	p.merge(q);
	//�ϲ��Զ�ȥ��
	//q�����ظ��Ĳ���
	cout << "p.merge(q):" << p << "q: " << q;

}
/*
p: [3] { A, B, C }
q: [3] { C, D, E }
p.merge(q):[5] { A, B, C, D, E }
q: [1] { C }
*/