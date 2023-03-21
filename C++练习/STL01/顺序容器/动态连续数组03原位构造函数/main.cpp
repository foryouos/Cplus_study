#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <vector>
class MyString
{
public:
    MyString(const char* str = NULL);// ��ͨ���캯��
    MyString(const MyString& other);// �������캯��
    ~MyString(void);// ��������
    MyString& operator = (const MyString& other);// ��ֵ����
private:
    char* m_data;// ���ڱ����ַ���
};


//��ͨ���캯��
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


// String����������
MyString::~MyString(void)
{
    std::cout << "deconstruct:" << m_data << std::endl;
    delete[] m_data;
}


//�������캯��
MyString::MyString(const MyString& other)
{
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    std::cout << "copy construct:" << m_data << std::endl;
}


//��ֵ����
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
        std::cout << "�Ա�push_back��emplace_back��Ч��" << std::endl;
        std::cout << "push_back"<<std::endl;
        std::vector<MyString> vStr;
        // Ԥ�ȷ��䣬��������vector��������������������·����ڴ�
        vStr.reserve(100);
        //��Ԫ�����ӵ�ĩβ
        vStr.push_back(MyString("can ge ge blog"));
    }
    {

        std::cout << "emplace_back" << std::endl;
        std::vector<MyString> vStr;
        // Ԥ�ȷ��䣬��������vector��������������������·����ڴ�
        vStr.reserve(100);
        vStr.emplace_back("hello world");
    }


    return 0;
}
/*
�Ա�push_back��emplace_back��Ч��
push_back
construct:can ge ge blog
copy construct:can ge ge blog
deconstruct:can ge ge blog
deconstruct:can ge ge blog
emplace_back
construct:hello world
deconstruct:hello world
*/