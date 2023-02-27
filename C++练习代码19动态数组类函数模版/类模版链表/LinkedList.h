#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
template <class T>
class LinkedList
{
private:  //����������������Ҳ��д��˽�к���
	Node<T>* front, * rear; //��ͷ�ͱ�βָ��
	NOde<T>* prevPtr, * currPtr; //��¼��ǰ����λ�õ�ָ�룬�ɲ����ɾ����������
	int size; //����Ԫ�ظ���
	int position; //��ǰԪ���ڱ��е�λ����ţ��ɺ���resetʹ��
	//�����½ڵ㣬������Ϊitem��ָ����ΪptrNext
	Node<T>* newNode(const T& item, Node<T>* ptrNext = NULL);
	void freeNode(Node<T>* p);//�ͷŽ��
	//������L���Ƶ���ǰ��(���赱ǰ��Ϊ�ձ����ƹ��캯����operator = ����
	void copy(const LinkedList<T>& L);
public:
	LinkedList();//���캯��
	LinkedList(const LinkedList<T>& L);//���ƹ��캯��
	~LinkedList(); //��������
	LinkedList<T>& operator = (const LinkedList<T>& L);//���ظ�ֵ�����
	int getSize() const; //���������е�Ԫ�ظ���
	bool isEmpty() const; //�����Ƿ�Ϊ��

	void reset(int pos = 0); //��ʼ���α��λ��
	void next(); //ʹ�α��ƶ�����һ�����
	bool endOfList() const; //�α��Ƿ�����β
	int currentPosition() const; //�����α굱ǰ��λ��

	void insertFront(const T& item); //�ڱ�ͷ������
	void insertRear(const T& item);//�ڱ�β��ӽ��
	void insertAt(const T& item); //�ڵ�ǰ�ڵ�֮ǰ������
	void insertAfter(const T& item); //�ڵ�ǰ�ڵ�֮ǰ������
	T deleteFront();  //ɾ��ͷ���
	void deleteCurrent();  //ɾ����ǰ���

	T& data(); //���ضԵ�ǰ�ڵ��Ա���ݵ�����
	const T& data() const; //���ضԵ�ǰ�ڵ��Ա���ݵĳ�����
	 
	//��������ͷ����н������ݿռ䣬������������operator=����
	void clear();
}; 


#endif // !LINKEDLIST_H
