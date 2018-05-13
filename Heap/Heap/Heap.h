
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef int DataType;

typedef int(*Compare)(DataType a, DataType b);

typedef struct Heap
{
	DataType * _array;
	int _capacity;
	int _size;
	Compare cmp;
}Heap;



//������
void CreateHeap(Heap *hp, DataType *array, int size);

//������С�ѵ����µ���
void AdjustDown(Heap  *hp, int size);

//����
void InsertHeap(Heap *hp, DataType data);

//ɾ�����һ��Ԫ��
void DeleteHeap(Heap *hp);

//���ٶ�
void DestoryHeap(Heap *hp);


//ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap *hp);

//Ԫ�ظ���
int SizeHeap(Heap *hp);

//�ж϶��Ƿ�Ϊ��
int EmptyHeap(Heap *hp);

//��С�ѵ����ϵ���
void AdjustUp(Heap *hp, DataType parent);

//�������
void CheckCatacity(Heap *hp);

//С��
int Less(DataType a, DataType b);

//���
int Greater(DataType a, DataType b);

//�Ѳ���
void TestHeap();