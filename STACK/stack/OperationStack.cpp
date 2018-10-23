#include "stdafx.h"
#include "OperationStack.h"

OperationStack::OperationStack()
{
	stack1 = new arrayStack<int>(50);
	stack2 = new arrayStack<char>(50);
}

OperationStack::~OperationStack()
{
	delete stack1;
	stack1 = nullptr;
	delete stack2;
	stack2 = nullptr;
}

int OperationStack::operation(const string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			stack1->iStack(str[i]);
		}
		else
		{
			if (stack2->stackLength() == 0)
			{
				stack2->iStack(str[i]);
			}
			else
			{
				if ((stack2->stackTop() == '+' || stack2->stackTop() == '-') && (str[i] == '*' || str[i] == '/'));
				{
					stack2->iStack(str[i]);
				}
				if (((stack2->stackTop() == '+' || stack2->stackTop() == '-') && (str[i] == '+' || str[i] == '-')) || ((stack2->stackTop() =='*' || stack2->stackTop() == '/') && (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '/')))
				{
					int temp1 = 0;
					stack1->oStack(temp1);
					int temp2 = 0;
					stack1->oStack(temp2);
					if (stack2->stackTop() == '+')
					{
						int temp = temp1 + temp2;
						stack1->iStack(temp);
					}
					if (stack2->stackTop() == '-')
					{
						int temp = temp1 - temp2;
						stack1->iStack(temp);
					}
					if (stack2->stackTop() == '*')
					{
						int temp = temp1 * temp2;
						stack1->iStack(temp);
					}
					if (stack2->stackTop() == '/')
					{
						int temp = temp1 / temp2;
						stack1->iStack(temp);
					}
				}
			}
			
		
		}
	}
	return stack1->stackTop();
}
