// stack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "arrayStack.h"
#include "OperationStack.h"
#include "stdlib.h"
int main()
{
	/*arrayStack<int> stack(6);
	stack.iStack(1);
	stack.iStack(2);
	stack.iStack(3);
	stack.iStack(4);
	stack.iStack(5);
	stack.iStack(6);
	stack.iStack(7);
	stack.traverseStack();
	cout << endl;
	int num1 = -1;
	stack.oStack(num1);
	int num2 = -1;
	stack.oStack(num2);
	cout << "num1:" << num1 <<"   "<< "num2:" << num2 << endl;
	stack.traverseStack();
	cout << endl;
	cout<<stack.stackTop()<<endl;*/

	OperationStack stack;
	string str = "1+2*(6+4-3)/4";
	double result = stack.operation(str);
	cout << result << endl;
	system("pause");
    return 0;
}

