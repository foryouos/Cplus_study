#include <iostream>
#include <forward_list>
#include <string>
#include <vector>
using namespace std;
//重载输出
template<typename T>
ostream& operator<<(ostream& s, const forward_list<T>& v)
{
	s.put('[');
	char comma[3] = { '\0',' ,','\0' };
	for (const auto& e : v)
	{
		s << comma << e;
		comma[0] = ', ';
	}
	return s << ']';
}
int main(void)
{
	forward_list<string> words{ "the","forgurt","is","alse","cursed" };
	cout << "words:" << words << endl;
	auto beginIn = words.begin();
	words.insert_after(beginIn, "strawberry");
	// insert_after (3)                                                         
	auto anotherIt = beginIn;
	++anotherIt;
	anotherIt = words.insert_after(anotherIt, 2, "strawberry");
	std::cout << "words: " << words << '\n';

	// insert_after (4)
	std::vector<std::string> V = { "apple", "banana", "cherry" };
	anotherIt = words.insert_after(anotherIt, V.begin(), V.end());
	std::cout << "words: " << words << '\n';

	// insert_after (5)                                                         
	words.insert_after(anotherIt, { "jackfruit", "kiwifruit", "lime", "mango" });
	std::cout << "words: " << words << '\n';
	//更改元素个数
	words.resize(6);
	std::cout << "words: " << words << '\n';
	//移除首元素
	words.pop_front();
	std::cout << "words: " << words << '\n';
	//从容器中移除指定元素
	words.erase_after(words.begin());
	std::cout << "words: " << words << '\n';
	//
	words.emplace_after(words.begin(), "hello");
	std::cout << "words: " << words << '\n';
	//清除元素
	words.clear();
	return 0;
}
/*
words:[the ,forgurt ,is ,alse ,cursed]
words: [the ,strawberry ,strawberry ,strawberry ,forgurt ,is ,alse ,cursed]
words: [the ,strawberry ,strawberry ,strawberry ,apple ,banana ,cherry ,forgurt ,is ,alse ,cursed]
words: [the ,strawberry ,strawberry ,strawberry ,apple ,banana ,cherry ,jackfruit ,kiwifruit ,lime ,mango ,forgurt ,is ,alse ,cursed]
words: [the ,strawberry ,strawberry ,strawberry ,apple ,banana]
words: [strawberry ,strawberry ,strawberry ,apple ,banana]
words: [strawberry ,strawberry ,apple ,banana]
words: [strawberry ,hello ,strawberry ,apple ,banana]
*/