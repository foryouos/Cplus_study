#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void func(int num, string str)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "子线程：i = " << i << ", num: " << num << ", str :" << str << endl;
		//当前线程阻塞500ms
		this_thread::sleep_for(chrono::microseconds(500));
	}
	
}
void func1()
{
	for (int j = 0; j < 10; j++)
	{
		cout << "子线程：j = " << j << endl;
		//当前线程阻塞500ms
		this_thread::sleep_for(chrono::microseconds(500));
	}
}
int main(void)
{
	//获取当前CPU核心数，
	//每个线程独自占有一个CPU核心，这些线程就不用分时复用CPU时间片，此时层序并发效率最高
	cout << "当前计算机的CPU核心数" << thread::hardware_concurrency() << endl;

	cout << "主线程id :" << this_thread::get_id() << endl; //获取线程id
	//利用构造函数，创建现车个t和t1
	//同时利用参数将子线程函数与参数传入
	thread t(func, 520, "I Love You");
	thread t1(func1);
	// 输出子线程id
	cout << "子线程 t ID ： " << t.get_id() << endl;;
	cout << "子线程 t1 ID ： " << t1.get_id() <<endl;
	//主线程先执行完毕，
	
#if 0
	//1,等到子线程结束。将子线程加入到当前线程当中
	t.join();
	t1.join();
#else if 1
	//2，子线程与主线程分离，主线程运行完毕，释放空间，子线程可以脱离主线程继续运行，任务运行完毕之后，子线层会自动释放自己占用的系统资源
	t.detach();
	t1.detach();
#endif // 0
	cout << "主线程结束!!" << endl;
	//主线程等待子线程运行结束，等待5秒
	this_thread::sleep_for(chrono::microseconds(5000));
	//来不及运行的子程序将无法将输出结果呈现到主屏幕上
	return 0;
}