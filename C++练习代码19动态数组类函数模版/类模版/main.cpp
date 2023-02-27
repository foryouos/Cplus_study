#include <iostream>
#include <cstdlib>
using namespace std;
struct Student
{
	int id; //学号
	float gpa; //平均分
};
template <class T>
class Store //类模版，实现对任意数据进行存取
{
private:
	T item;  //item用于存放任意类型的数据
	bool haveValue; //haveValue标记item是否已被存入内容
public:
	friend T; //将参数类型T声明为友元类
	Store();
	T& getElem(); //提取数据函数
	void pubElem(const T& x); //存入数据函数
};
template <class T>
Store<T>::Store() :haveValue(false)
{
}
template <class T>
T& Store<T>::getElem()
{
	//如试图提取未初始化的数据，则终止程序
	if (!haveValue)
	{
		cout << "No item present!" << endl;
		exit(1); //使程序完全退出，返回到操作系统
	}
	return item; //返回item中存放的数据
}
template <class T>
void Store<T>::pubElem(const T& x)
{
	//haveValue置为true，标识item中已存入数值
	haveValue = true;
	item = x; //将x值存入item
}

int main(void)
{
	using IntStore = Store<int>;
	IntStore s1, s2;
	s1.pubElem(3);
	s2.pubElem(-7);
	cout << s1.getElem() << " " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student> s3;  //将结构体传给类 T类型换成Student结构体
	s3.pubElem(g);
	cout << "The student id is " << s3.getElem().id << endl;

	Store<double> d;
	cout << "Retrieving object D...";
	cout << d.getElem() << endl;
	//d未初始化，执行函数D.getElement()时导致程序终止
	return 0;
}
/*
3 -7
The student id is 1000
Retrieving object D...No item present!
*/