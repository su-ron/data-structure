#pragma once
//线性表链式结构
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
    Node *next;
}; 

template<class T>
class LinkList
{
	Node<T> *front;
public:
	LinkList()
	{
		front = new Node<T>;
		front->next = NULL;
	}

	LinkList(T a[], int n);
	~LinkList();//析构函数，释放内存
	void print();
	bool Insert(int i, T a);
	bool Delete(int i, T&a);
	bool SetValue(int i,T a);
	bool GetValue(int i, T& a);
	int Locate(T a);
	int GetLength();

};

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n; i > 0; i--)  //使用头插法
	{
		Node<T> *s = new Node<T>;
		s->data = a[i - 1];
		s->next = front->next;
		front->next = s;
	}

	front->data = n;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T> *s =front->next;
	while (front->next)
	{
		front->next =s->next;
		delete s;
		s = front->next;
	}
	front = NULL;
}

template<class T>
void LinkList<T>::print()
{
	Node<T> *s=front->next;
	while (s)
	{
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
}


template<class T>
bool LinkList<T> ::Insert(int i, T a)
{
	if (i > front->data || i < 0)
		return false;
	Node<T>*s = front;
	for (int j = 1; j < i; j++)
	{
		s = s->next;
	}
	Node<T>*p = new Node<T>;
	p->data = a;
	p->next = s->next;
	s->next = p;
	++front->data;//线性表长度加一

	return true;
}


template<class T>
bool LinkList<T>::Delete(int i, T &a)
{
	if (i > front->data || i < 1)
		return false;
	Node<T> *s = front;
	for (int j = 1; j < i; j++)//该循环结束时，s在第i-1个元素
	{
		s = s->next;
	}
	Node<T> *p;
	p = s->next;
	s->next = p->next;
	a = p->data;
	delete p;
	--front->data;
	return true;
}

template<class T>
bool LinkList<T>::SetValue(int i, T a)
{
	if (i > front->data || i < 1)
		return false;
	Node<T> *s = front->next;
	for (int j = 1; j < i; j++)
	{
		s = s->next;
	}
	s->data = a;
	return true;
}

template<class T>
bool LinkList<T>::GetValue(int i, T&a)
{
	if (i > front->data || i < 1)
		return false;
	Node<T> *s = front->next;
	for (int j = 1; j < i; j++)
	{
		s = s->next;
	}
	a = s->data;
	return true;
}

template<class T>
int LinkList<T>::Locate(T a)
{
	Node<T>*s = front->next;
	for (int j = 1; s->next != NULL; j++)
	{
		if (s->data == a)
			return j;
		s = s->next;
	}
	if (!s->next) return -1;
}

template<class T>
int LinkList<T>::GetLength()
{
	return front->data;
}