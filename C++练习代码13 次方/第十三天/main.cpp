/*
* project: C++输出已经响铃实例
* environment：VS2022
*/
#include <iostream>  //预处理指令iostream中声明了程序所需要的输入和输出操作有关信息
#include <cstdlib>
#include <cmath>
using namespace std;  //命名空间
int main(void)  //main主函数，执行入口，int返回值类型
{
	//cout 输出流对象
	srand(45);
	int n = rand();  //
	
	cout << n << endl;
	
	
	


	cout << "Hello Word " <<endl;  
	//endl表示换行符

	printf("Hello word\n\a"); /*    \a响铃 */
	return 0;  //0意味着正常结束，非0返回，意味着程序异常结束
}