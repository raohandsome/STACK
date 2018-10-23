#pragma once
#include "stdafx.h"
#include <iostream>
#include "arrayStack.h"
using namespace std;
class OperationStack
{
public:
	OperationStack();
	~OperationStack();
	int operation(const string str);
	
private:
	arrayStack<int> *stack1;
	arrayStack<char> *stack2;
};