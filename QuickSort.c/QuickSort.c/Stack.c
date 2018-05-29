#include "Stack.h"

//栈的初始化
void StackInit(PStack s)
{
	assert(s);
	s->_size = 0;
}

//入栈
void StackPush(PStack s, DataType data)
{
	assert(s);
	if (10 == s->_size)				//栈已满
		return;
    s->_array[s->_size] = data;
	s->_size++;
}

//出栈
void	 StackPop(PStack s)
{
	assert(s);
	if (0 == s->_size)
		return;
	s->_size--;
}


//查看栈顶数据
DataType StackTop(PStack s)
{
	assert(s);
	if (0 == s->_size)
	{
		exit(EXIT_FAILURE);
	}
	return s->_array[s->_size - 1];
}

//查看当前栈里的元素个数
int StackSize(PStack s)
{
	assert(s);

	return s->_size;
}

//检查栈是否为空
int StackEmpty(PStack s)
{
	if (0 == s->_size)
		return 1;

	return 0;
}

//打印
void StackPrint(PStack s)
{
	assert(s);
	if (0 == s->_size)
		return;
	for (int i = 0; i < s->_size; i++)
	{
		printf("%d->", s->_array[i]);
	}
	putchar('\n');
}

