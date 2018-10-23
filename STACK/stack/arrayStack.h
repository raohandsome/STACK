#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
template <class T>
class arrayStack
{
public:
	arrayStack(const int capacity);
	~arrayStack();
	void iStack(const T num);
	void oStack(T &num);
	T stackTop();
	int stackLength();
	void traverseStack();
private:
	T * m_iArray;
	int m_iLength;
	int m_iCapacity;
};
template <class T>
arrayStack<T>::arrayStack(const int capacity)
{
	m_iCapacity = capacity;
	m_iArray = new T[m_iCapacity];
	m_iLength = 0;
}
template <class T>
arrayStack<T>::~arrayStack()
{
	delete[] m_iArray;
	m_iArray = nullptr;
}
template <class T>
void arrayStack<T>::iStack(const T num)
{
	if (m_iLength < m_iCapacity)
	{
		m_iArray[m_iLength] = num;
		m_iLength++;
	}
	else
	{
		cout << "stack is full" << endl;
	}

}
template <class T>
void arrayStack<T>::oStack(T &num)
{
	if (m_iLength > 0)
	{
		num = m_iArray[m_iLength - 1];
		m_iLength--;
	}
	else
	{
		cout << "stack is empty" << endl;
	}
}
template<class T>
inline T arrayStack<T>::stackTop()
{
	return m_iArray[m_iLength-1];
}
template<class T>
inline int arrayStack<T>::stackLength()
{
	return m_iLength;
}
template <class T>
void arrayStack<T>::traverseStack()
{
	for (int i = 0; i < m_iLength; i++)
	{
		cout << m_iArray[i] << endl;
	}
}
