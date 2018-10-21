#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack(const int capacity);
	~Stack();
	void iStack(const int num);
	void oStack(int &num);
	void traverseStack();
private:
	int *m_iArray;
	int m_iCapacity;
	int m_iLength;
};