#pragma once
#ifndef NODE_H
#define NODE_H
//������Ľ����ģ�� NOde.h
template <class T>
class Node
{
private:
	Node<T>* next;  //ָ���̽ڵ��ָ��
public:
	T data;  //������
	Node(const T& item, Node<T>* next = 0);  //���캯��
	void insertAfter(Node<T>* p); //�ڱ����֮�����һ��ͬ����P
	Node<T>* deleteAfter();  //��ɾ�������ĺ�̽ڵ㣬���������ַ
	Node<T>* nextNode();  //��ȡ��̽ڵ�ĵ�ַ
	const Node<T>* nextNode() const;  //��ȡ�����ڵ�ĵ�ַ
};
//���ʵ�ֺ���
//���캯������ʼ�����ݺ�ָ���Ա
template <class T>
Node<T>::Node(const T& data, Node<T>* next = 0)
	:data(data), next(next)
{
}
//���غ�̽ڵ��ָ��
template <class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}
//���غ�̽ڵ��ָ��
template <class T>
const Node<T>* Node<T>::nextNode() const  //���صĳ�ָ�룬ֻ�ܶ�
{
	return next;
}

//�ڽ��֮�����һ�����
template <class T>
void Node<T>::insertAfter(Node<T>* p)
{
	//p���ָ����ָ��ǰ�ڵ�ĺ�̽ڵ�
	p->data = next;
	next = p;  //��ǰ�ڵ��ָ����ָ��p
}
//ɾ���ڵ�֮��Ľ��
template <class T>
Node<T>* Node<T>::deleteAfter(void)
{    //��������ϲ�ֱ��ɾ��
	Node<T>* tempPtr = next;
	if (next == 0)   //����Ϊ��ָ��
		return 0;
	next = tempPtr->next; //
	return tempPtr;  //���صľ��Ǳ�ɾ����ָ��
}
#endif // !NODE_H