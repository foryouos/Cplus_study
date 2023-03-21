#include <iostream>
//需要引入 array 头文件
#include <array>
using namespace std;
int main()
{
    array<int, 5>values{ 1,2,3,4,5 };
    int h = 1;
    auto first = values.cbegin();
    auto last = values.cend();

    //由于 *first 为 const 类型，不能用来修改元素
    //*first = 10;

    //遍历容器并输出容器中所有元素
    while (first != last)
    {
        //可以使用 const 类型迭代器访问元素
        cout << *first << " ";
        ++first;
    }
    return 0;
}