#pragma once
#ifndef NODE_H
#define NODE_H
//单链表的结点类模版 NOde.h
template <class T>
class Node
{
private:
	Node<T>* next;  //指向后继节点的指针
public:
	T data;  //数据域
	Node(const T& item, Node<T>* next = 0);  //构造函数
	void insertAfter(Node<T>* p); //在本结点之后插入一个同类结点P
	Node<T>* deleteAfter();  //在删除本结点的后继节点，并返回其地址
	Node<T>* nextNode();  //获取后继节点的地址
	const Node<T>* nextNode() const;  //获取后续节点的地址
};
//类的实现函数
//构造函数，初始化数据和指针成员
template <class T>
Node<T>::Node(const T& data, Node<T>* next = 0)
	:data(data), next(next)
{
}
//返回后继节点的指针
template <class T>
Node<T>* Node<T>::nextNode()
{
	return next;
}
//返回后继节点的指针
template <class T>
const Node<T>* Node<T>::nextNode() const  //返回的常指针，只能读
{
	return next;
}

//在结点之后插入一个结点
template <class T>
void Node<T>::insertAfter(Node<T>* p)
{
	//p结点指针域指向当前节点的后继节点
	p->data = next;
	next = p;  //当前节点的指针域指向p
}
//删除节点之后的结点
template <class T>
Node<T>* Node<T>::deleteAfter(void)
{    //结点物理上不直接删除
	Node<T>* tempPtr = next;
	if (next == 0)   //代表为空指针
		return 0;
	next = tempPtr->next; //
	return tempPtr;  //返回的就是被删除的指针
}
#endif // !NODE_H