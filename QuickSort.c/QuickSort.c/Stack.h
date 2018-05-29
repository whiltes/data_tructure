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

void StackInit(PStack s);					//ջ�ĳ�ʼ��
void StackPush(PStack s, DataType data);	//��ջ
void	 StackPop(PStack s);					//��ջ
DataType StackTop(PStack s);				//�鿴ջ������
int StackSize(PStack s);					//�鿴��ǰջ���Ԫ�ظ���
int StackEmpty(PStack s);					//���ջ�Ƿ�Ϊ��
void StackPrint(PStack s);				//��ӡջ��Ԫ��