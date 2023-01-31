#include <iostream>
using namespace std;
class Clock
{
	public:
		void setTime(int newH, int newM, int newS);
		void showTime();
	private:
		int hour, minute, second;
};
void Clock::setTime(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime()
{
	cout << "Time:" << hour << ":" << minute << ":" << second << endl;
}
int main(void)
{
	Clock C;
	C.setTime(12, 48, 02);
	C.showTime();

	return 0;
}
