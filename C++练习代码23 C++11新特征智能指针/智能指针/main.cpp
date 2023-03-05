#include <iostream>
using namespace std;
//class Person {
//	int m_age;
//public:
//	Person() {
//		cout << "Person()" << endl;
//	}
//	Person(int age) :m_age(age) {
//		cout << "Person(int)" << endl;
//	}
//	~Person() {
//		cout << "~Person()" << endl;
//	}
//	void run() {
//		cout << "run() - " << m_age << endl;
//	}
//};
////创建简单的智能指针
//template <typename T>
//class SmartPointer
//{
//private:
//	T *m_obj;
//public:
//	SmartPointer(T* obj) : m_obj(obj)
//	{
//
//	}
//	~SmartPointer()
//	{
//		if (m_obj == nullptr) return;
//		delete m_obj;
//	}
//	T* operator->()
//	{
//		return m_obj;
//	}
//};
void test()
{
	/*Person *p = new Person(20);
	p->run();*/

	// 可以理解为：智能指针p指向了堆空间的Person对象
	/*cout << 1 << endl;
	{
		auto_ptr<Person> p(new Person(20));
		p->run();
	}
	cout << 2 << endl;*/

	/*Person p(20);
	p.run();*/
}
void test2()
{
	//cout << 1 << endl;
	//{
	//	//可以
	//	//shared_ptr<Person> p(new Person(20));
	//	//若为数组
	//	//shared_ptr<Person[]> p(new Person[5]);
	//	//当多个智能指针指向一个对象
	//	shared_ptr<Person> p4; //当最后一个对象销毁后对象才会销毁
	//	{
	//		shared_ptr<Person> p1(new Person(10));
	//		cout << p1.use_count() << endl; //返回使用强引用的数量
	//		shared_ptr<Person> p2 = p1;
	//		cout << p2.use_count() << endl;
	//		shared_ptr<Person> p3 = p2;
	//		cout << p3.use_count() << endl;
	//		p4 = p3;
	//		cout << p4.use_count() << endl;
	//	}
	//	cout << 2 << endl;
	//	cout << p4.use_count() << endl;
	//}
	//cout << 3 << endl;
}
class Person;
class Car
{
public:
	weak_ptr<Person> m_person; //弱引用解决循环引用问题
	Car()
	{
		cout << "Car()" << endl;
	}
	~Car()
	{
		cout << "~ Car()" << endl;
	}
};
class Person
{
public:
	shared_ptr<Car> m_car;
	Person()
	{
		cout << "Person()" << endl;
	}
	~ Person()
	{
		cout << "~ Person()" << endl;
	}
};
int main()

{
	shared_ptr<Person> person(new Person());
	shared_ptr<Car> car(new Car()); 
	//两个强引用循环引用，导致对象无法销毁
	person->m_car = car;
	car->m_person = person;
	return 0;
}
/*
Person()
Car()
~ Person()
~ Car()
*/