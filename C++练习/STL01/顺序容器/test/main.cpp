#include <iostream>
//��Ҫ���� array ͷ�ļ�
#include <array>
using namespace std;
int main()
{
    array<int, 5>values{ 1,2,3,4,5 };
    int h = 1;
    auto first = values.cbegin();
    auto last = values.cend();

    //���� *first Ϊ const ���ͣ����������޸�Ԫ��
    //*first = 10;

    //�����������������������Ԫ��
    while (first != last)
    {
        //����ʹ�� const ���͵���������Ԫ��
        cout << *first << " ";
        ++first;
    }
    return 0;
}