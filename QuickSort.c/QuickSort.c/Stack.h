#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 10

typedef int DataType;

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack, *PStack;

void StackInit(PStack s);					//栈的初始化
void StackPush(PStack s, DataType data);	//入栈
void	 StackPop(PStack s);					//出栈
DataType StackTop(PStack s);				//查看栈顶数据
int StackSize(PStack s);					//查看当前栈里的元素个数
int StackEmpty(PStack s);					//检查栈是否为空
void StackPrint(PStack s);				//打印栈中元素