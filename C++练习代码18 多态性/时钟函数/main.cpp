#include <iostream>
using namespace std;
class Clock
{
public:
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime() const;
	//ǰ�õ�Ŀ���������
	Clock& operator ++ ();
	//���õ�Ŀ���������
	Clock operator ++ (int);  //int����ǰ�ú���
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
void Clock::showTime() const //��ʾʱ��
{
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock& Clock::operator++() //ǰ��++
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
Clock Clock::operator++(int)  //����++
{
	//ע���βα��ж����Ͳ���
	Clock old = *this;
	++(*this);  //����ǰ�á�++�������
	return old;  //���ص�ǰֵ֮��żӼ�
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