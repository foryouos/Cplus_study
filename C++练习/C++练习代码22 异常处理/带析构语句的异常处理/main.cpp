/*
带析构语句的类的C++异常处理
*/
#include <iostream>
#include <string>
using namespace std;
class MyException
{
public:
	MyException(const string& message) :message(message)
	{

	}
	~ MyException() {}
	const string& getMessage() const
	{
		return message;
	}
private:
	string message;
};
class Demo
{
public:
	Demo()
	{
		cout << "Constructor of Demo" << endl;
	}
	~Demo()
	{
		cout << "Destructor of Demo" << endl;
	}
};
void func() throw(MyException)
{
	Demo d;
	cout << "Throw MyException in func() " << endl;
	throw MyException("exception thrown by func()");
}
int main(void)
{
	cout << "In main function" << endl;
	try
	{
		func();
	}
	catch (MyException& e)
	{
		cout << "Caught an exception: " << e.getMessage() << endl;
	}
	cout << "Resume the exception of main()" << endl;
	return 0;
}
/*
In main function
Constructor of Demo
Throw MyException in func()
Destructor of Demo
Caught an exception: exception thrown by func()
Resume the exception of main()
*/