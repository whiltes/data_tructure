#include "Stack.h"

//ջ�ĳ�ʼ��
void StackInit(PStack s)
{
	assert(s);
	s->_size = 0;
}

//��ջ
void StackPush(PStack s, DataType data)
{
	assert(s);
	if (10 == s->_size)				//ջ����
		return;
    s->_array[s->_size] = data;
	s->_size++;
}

//��ջ
void	 StackPop(PStack s)
{
	assert(s);
	if (0 == s->_size)
		return;
	s->_size--;
}


//�鿴ջ������
DataType StackTop(PStack s)
{
	assert(s);
	if (0 == s->_size)
	{
		exit(EXIT_FAILURE);
	}
	return s->_array[s->_size - 1];
}

//�鿴��ǰջ���Ԫ�ظ���
int StackSize(PStack s)
{
	assert(s);

	return s->_size;
}

//���ջ�Ƿ�Ϊ��
int StackEmpty(PStack s)
{
	if (0 == s->_size)
		return 1;

	return 0;
}

//��ӡ
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

