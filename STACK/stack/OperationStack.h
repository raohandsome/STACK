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
	double operation(const string str);
	
private:
	arrayStack<double> *stack1;
	arrayStack<char> *stack2;
};