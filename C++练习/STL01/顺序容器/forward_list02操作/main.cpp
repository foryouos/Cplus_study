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
	//对列表排序
	list1.sort();
	list2.sort();  
	cout << "list1" << list1 << endl;
	cout << "list2" << list2 << endl;
	list1.merge(list2); //合并后list2为空
	cout << "合并后" << list1 << endl;
	//插入
	list1.splice_after(list1.cbegin(), list3,list3.cbegin(), list3.cend());

	cout << "插入后" << list1 << endl;
	//移除满足条件的值
	list1.remove(1);//移除等于1的
	cout << "移除1后" << list1 << endl;
	//移除n大于10的
	list1.remove_if([](int n) { return n > 10; });
	cout << "移除大于10后" << list1 << endl;
	//将所有元素反转
	list1.reverse();
	cout << "列表反转后：" << list1 << endl;
	//删除重复元素
	list1.unique();
	cout << "去重后：" << list1 << endl;
	return 0;
}
/*
list1 1 3 3 3 5 9 9
list2 2 3 4 5 7 8
合并后 1 2 3 3 3 3 4 5 5 7 8 9 9
插入后 1 99 33 2 3 3 3 3 4 5 5 7 8 9 9
移除1后 99 33 2 3 3 3 3 4 5 5 7 8 9 9
移除大于10后 2 3 3 3 3 4 5 5 7 8 9 9
列表反转后： 9 9 8 7 5 5 4 3 3 3 3 2
去重后： 9 8 7 5 4 3 2
*/