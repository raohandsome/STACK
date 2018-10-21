#include "stdafx.h"
#include "Stack.h"


Stack::Stack(const int capacity)
{
	m_iCapacity = capacity;
	m_iArray = new int[m_iCapacity];
	m_iLength = 0;
}

Stack::~Stack()
{
	delete[] m_iArray;
	m_iArray = nullptr;
}

void Stack::iStack(const int num)
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

void Stack::oStack(int &num)
{
	if (m_iLength > 0)
	{
		num = m_iArray[m_iLength-1];
		m_iLength--;
	}
	else
	{
		cout << "stack is empty" << endl;
	}
}

void Stack::traverseStack()
{
	for (int i = 0; i < m_iLength; i++)
	{
		cout << m_iArray[i] << endl;
	}
}
