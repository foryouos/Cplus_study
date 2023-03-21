#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <vector>
class MyString
{
public:
    MyString(const char* str = NULL);// 普通构造函数
    MyString(const MyString& other);// 拷贝构造函数
    ~MyString(void);// 析构函数
    MyString& operator = (const MyString& other);// 赋值函数
private:
    char* m_data;// 用于保存字符串
};


//普通构造函数
MyString::MyString(const char* str)
{
    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
    std::cout << "construct:" << m_data << std::endl;
}


// String的析构函数
MyString::~MyString(void)
{
    std::cout << "deconstruct:" << m_data << std::endl;
    delete[] m_data;
}


//拷贝构造函数
MyString::MyString(const MyString& other)
{
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    std::cout << "copy construct:" << m_data << std::endl;
}


//赋值函数
MyString& MyString::operator = (const MyString& other)
{
    std::cout << "copy assignment" << std::endl;
    if (this == &other)
        return *this;
    if (m_data)
        delete[] m_data;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    return *this;
}

int main(void)
{
    {
        std::cout << "对比push_back和emplace_back的效率" << std::endl;
        std::cout << "push_back"<<std::endl;
        std::vector<MyString> vStr;
        // 预先分配，否则整个vector在容量不够的情况下重新分配内存
        vStr.reserve(100);
        //将元素增加到末尾
        vStr.push_back(MyString("can ge ge blog"));
    }
    {

        std::cout << "emplace_back" << std::endl;
        std::vector<MyString> vStr;
        // 预先分配，否则整个vector在容量不够的情况下重新分配内存
        vStr.reserve(100);
        vStr.emplace_back("hello world");
    }


    return 0;
}
/*
对比push_back和emplace_back的效率
push_back
construct:can ge ge blog
copy construct:can ge ge blog
deconstruct:can ge ge blog
deconstruct:can ge ge blog
emplace_back
construct:hello world
deconstruct:hello world
*/