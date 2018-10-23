#include "stdafx.h"
#include "OperationStack.h"

OperationStack::OperationStack()
{
	stack1 = new arrayStack<double>(50);
	stack2 = new arrayStack<char>(50);
}

OperationStack::~OperationStack()
{
	delete stack1;
	stack1 = nullptr;
	delete stack2;
	stack2 = nullptr;
}


double OperationStack::operation(const string str)

{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			stack1->iStack(str[i] - '0');
		
		}

		else
		{
			if (stack2->stackLength() == 0)
			{
				stack2->iStack(str[i]);

			}
			else if (str[i] == '(')
			{
				stack2->iStack(str[i]);
			}
			else if (str[i] == ')')
			{
				while (stack2->stackTop()!='(')
				{
					double temp1 = 0;
					stack1->oStack(temp1);
					double temp2 = 0;
					stack1->oStack(temp2);
					double temp = 0;
					if (stack2->stackTop() == '+')
					{
						temp = temp1 + temp2;
					}
					if (stack2->stackTop() == '-')
					{
						//temp = temp1 - temp2;
						temp = temp2 - temp1;//两个数的顺序
					}
					if (stack2->stackTop() == '*')
					{
						temp = temp1 * temp2;
					}
					if (stack2->stackTop() == '/')
					{
						temp = temp2 / temp1;

					}
					stack1->iStack(temp);
					char a = ' ';
					stack2->oStack(a);
					
				}
				char a = ' ';
				stack2->oStack(a);
			}
			else
			{
				if ((stack2->stackTop() == '*' || stack2->stackTop() == '/') && (str[i] == '+' || str[i] == '/'))
					// if (((stack2->stackTop() == '+' || stack2->stackTop() == '-') && (str[i] == '+' || str[i] == '-')) || ((stack2->stackTop() =='*' || stack2->stackTop() == '/') && (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '/')))

				{
					double temp1 = 0;
					stack1->oStack(temp1);
					double temp2 = 0;
					stack1->oStack(temp2);
					double temp = 0;
					if (stack2->stackTop() == '+')
					{
						temp = temp1 + temp2;
					}
					if (stack2->stackTop() == '-')
					{
						temp = temp1 - temp2;
					}
					if (stack2->stackTop() == '*')
					{
						temp = temp1 * temp2;
					}
					if (stack2->stackTop() == '/')
					{
						temp = temp1 / temp2;

					}
					stack1->iStack(temp);
					char a = ' ';
					stack2->oStack(a);
					stack2->iStack(str[i]);
					

				}
				else
				{
					stack2->iStack(str[i]);
				}
			}
				

		}
		//stack2->traverseStack();
	}
		while (stack2->stackLength() != 0)
		{
			double temp1 = 0;
			stack1->oStack(temp1);
			double temp2 = 0;
			stack1->oStack(temp2);
			double temp = 0;
			if (stack2->stackTop() == '+')
			{
				temp = temp1 + temp2;
			}
			if (stack2->stackTop() == '-')
			{
				//temp = temp1 - temp2;
				temp = temp2 - temp1;//两个数的顺序
			}
			if (stack2->stackTop() == '*')
			{
				temp = temp1 * temp2;
			}
			if (stack2->stackTop() == '/')
			{
				temp = temp2 / temp1;

			}
			stack1->iStack(temp);
			char a = ' ';
			stack2->oStack(a);
			
		}
		return stack1->stackTop();
	}

