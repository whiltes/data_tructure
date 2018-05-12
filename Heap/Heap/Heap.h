
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef int DataType;

typedef struct Heap
{
	DataType * _array;
	int _capacity;
	int _size;
}Heap;



//������
void CreateHeap(Heap *hp, DataType *array, int size);

//���µ���
void AdjustDown(Heap  *hp, int size);

//����
void InsertHeap(Heap *hp, DataType data);

//ɾ��
void DeleteHeap(Heap *hp);

//ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap *hp);

//Ԫ�ظ���
int SizeHeap(Heap *hp);

//�ж϶��Ƿ�Ϊ��
int EmptyHeap(Heap *hp);

//���ϵ���
void AdjustUp(Heap *hp, DataType parent);

//�������
void CheckCatacity(Heap *hp);

//С��
//int Less(DataType Left, DataType Right);

//���
//int Great(DataType Left, DataType Right);

//�Ѳ���
void TestHeap();