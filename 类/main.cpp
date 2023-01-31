/*
* project:钟表类
* environment :VS2022
* time:2023年1月31日
*/
#include <iostream>
using namespace std;
class Clock  //定义类边界
{
	public:  //特定访问权限
		//外部接口，并赋默认参数值
		void setTime(int newH = 0, int newM = 0, int newS = 0);  
		void showTime();
	private: //公有函数共享私有成员
		int hour, minute, second;
};
//成员函数的实现，类中的函数
void Clock::setTime(int newH, int newM, int newS) 
{
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime()
{
	cout << "Time:" << hour << ":" << minute << ":" << second << endl;
};

int main(void)
{
	Clock C;  //定义对象
	cout << "First time set and output:" << endl;
	C.setTime(); //类外访问，使用默认时间
	C.showTime(); //x显示时间
	cout << "Second time set and output:" << endl;
	C.setTime(12, 48, 30);  //类外访问
	C.showTime();

	return 0;
}
