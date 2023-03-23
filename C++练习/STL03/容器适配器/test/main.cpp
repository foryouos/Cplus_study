#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>
using namespace std;
template<typename T>
void print(string_view name, T const& q)
{
    cout << name << ": \t";
    for (auto const& n : q)
        cout << n << ' ';
    cout << '\n';
}

template<typename Q>
void print_queue(string_view name, Q q)
{
    // ע�⣺��ֵ���� q��������Ϊ�޷��ڲ�������е�����±��� priority_queue �����ݡ�
    for (cout << name << "��\t"; !q.empty(); q.pop())
        cout << q.top() << ' ';
    cout << '\n';
}

int main()
{
    const auto data = { 1, 8, 5, 6, 3, 4, 0, 9, 7, 2 };
    print("data", data);

    priority_queue<int> q1; // ������ȶ���
    for (int n : data)
        q1.push(n);

    print_queue("q1", q1);

    // ��С���ȶ���
    // std::greater<int> ʹ��������ȶ��е���Ϊ�����С���ȶ��е���Ϊ
    priority_queue<int, vector<int>, greater<int>>
        minq1(data.begin(), data.end());

    print_queue("minq1", minq1);

    
}