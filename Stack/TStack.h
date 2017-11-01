#pragma once
#include <stdexcept>
template <class T>
class TStack
{
	T* arr;
	int size;
	int maxsize;
public:
	TStack(int _size=200);
	~TStack(void);
	TStack(const TStack& ts);
	TStack& operator=(const TStack& ts);
	bool IsFull(void);
	bool IsEmpty(void);
	T Top(void);
	T Pop(void);
	void Push(const T& el);
	void Clear(void);
};
template <class T>
	TStack<T>::TStack(int _size=200)
	{
		arr= new T[size];
		maxsize=_size;
		size=0;
	}
template <class T>
	TStack<T>::~TStack(void)
	{
		delete[] arr;
	}
template <class T>
	TStack<T>::TStack(const TStack& ts)
	{
		size=ts.size;
		maxsize=ts.maxsize;
		arr= new T[maxsize];
		for(int i=0;i<size;i++)
			arr[i]=ts.arr[i];
	}
template <class T>
	TStack<T>& TStack<T>::operator=(const TStack& ts)
	{
		if (this==&ts) return *this;
		if(maxsize !=ts.maxsize)
		{
			delete[] arr;
			arr= new arr[ts.maxsize];
		}
		size = ts.size;
		for(int i=0;i<size;i++)
			arr[i]=ts.arr[i];
		return *this;

	}
template <class T>
bool TStack<T>::IsFull(void)
{
	return (size==maxsize);
}
template <class T>
bool TStack<T>::IsEmpty(void)
{
	return (size==0);
}
template <class T>
T TStack<T>::Top(void)
{
	if (!IsEmpty())
		return arr[size-1];
	 throw logic_error("Stack is Empty");
}
template <class T>
T TStack<T>::Pop(void)
{
	if(IsEmpty())
		throw logic_error("Stack is Empty");
	size--;
	return arr[size];
}
template <class T>
void TStack<T>::Push(const T& el)
{
	if(IsFull())
		throw logic_error("Stack is Full");
	arr[size]=el;
	size++;
}
template <class T>
void TStack<T>::Clear(void)
{
	if(!IsEmpty())
		size=0;
}


