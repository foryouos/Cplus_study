#include <iostream>
using namespace std;
class Clock
{
public:
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime() const;
	//前置单目运算符重载
	Clock& operator ++ ();
	//后置单目运算符重载
	Clock operator ++ (int);  //int区分前置后置
private:
	int hour, minute, second;
};
Clock::Clock(int hour, int minute, int second)
{
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <=second &&second <60)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
	{
		cout << "Time error!" << endl;
	}
}
void Clock::showTime() const //显示时间
{
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock& Clock::operator++() //前置++
{ 
	second++;
	if (second >= 60)
	{
		second -= 60;
		minute++;
		if (minute >= 60)
		{
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return *this;
}
Clock Clock::operator++(int)  //后置++
{
	//注意形参表中额整型参数
	Clock old = *this;
	++(*this);  //调用前置“++”运算符
	return old;  //返回当前值之后才加加
}

int main(void)
{
	Clock myclock(23, 59, 59);
	cout << "First time output:";
	myclock.showTime();
	cout << "Show myclock++";
	(myclock++).showTime();
	cout << "Show ++myclock:";
	(++myclock).showTime();
	return 0;
}
/*
First time output:23:59:59
Show myclock++23:59:59
Show ++myclock:0:0:1
*/