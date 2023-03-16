#include <iostream>
#include <cstdlib>
using namespace std;
struct Student
{
	int id; //ѧ��
	float gpa; //ƽ����
};
template <class T>
class Store //��ģ�棬ʵ�ֶ��������ݽ��д�ȡ
{
private:
	T item;  //item���ڴ���������͵�����
	bool haveValue; //haveValue���item�Ƿ��ѱ���������
public:
	friend T; //����������T����Ϊ��Ԫ��
	Store();
	T& getElem(); //��ȡ���ݺ���
	void pubElem(const T& x); //�������ݺ���
};
template <class T>
Store<T>::Store() :haveValue(false)
{
}
template <class T>
T& Store<T>::getElem()
{
	//����ͼ��ȡδ��ʼ�������ݣ�����ֹ����
	if (!haveValue)
	{
		cout << "No item present!" << endl;
		exit(1); //ʹ������ȫ�˳������ص�����ϵͳ
	}
	return item; //����item�д�ŵ�����
}
template <class T>
void Store<T>::pubElem(const T& x)
{
	//haveValue��Ϊtrue����ʶitem���Ѵ�����ֵ
	haveValue = true;
	item = x; //��xֵ����item
}

int main(void)
{
	using IntStore = Store<int>;
	IntStore s1, s2;
	s1.pubElem(3);
	s2.pubElem(-7);
	cout << s1.getElem() << " " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student> s3;  //���ṹ�崫���� T���ͻ���Student�ṹ��
	s3.pubElem(g);
	cout << "The student id is " << s3.getElem().id << endl;

	Store<double> d;
	cout << "Retrieving object D...";
	cout << d.getElem() << endl;
	//dδ��ʼ����ִ�к���D.getElement()ʱ���³�����ֹ
	return 0;
}
/*
3 -7
The student id is 1000
Retrieving object D...No item present!
*/