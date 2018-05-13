
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



//创建堆
void CreateHeap(Heap *hp, DataType *array, int size);

//创建最小堆的向下调整
void AdjustDown(Heap  *hp, int size);

//插入
void InsertHeap(Heap *hp, DataType data);

//删除最后一个元素
void DeleteHeap(Heap *hp);

//销毁堆
void DestoryHeap(Heap *hp);


//取堆顶元素
DataType TopHeap(Heap *hp);

//元素个数
int SizeHeap(Heap *hp);

//判断堆是否为空
int EmptyHeap(Heap *hp);

//最小堆的向上调整
void AdjustUp(Heap *hp, DataType parent);

//检测容量
void CheckCatacity(Heap *hp);

//小堆
int Less(DataType a, DataType b);

//大堆
int Greater(DataType a, DataType b);

//堆测试
void TestHeap();