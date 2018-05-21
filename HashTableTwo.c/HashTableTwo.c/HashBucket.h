
#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Common.h"


//typedef int DataType;
typedef char* DataType;

//转换Int函数指针
typedef size_t(*PDT)(DataType str);


typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

//哈希表
typedef struct HashBucket
{
	PNode * _table;
	int _capacity;		//桶的个数
	int _size;			//元素个数
	PDT  _setData;		//将数据转化为整型，
}HashBucket;


//哈希桶初始化
void HashBucketInit(HashBucket* ht, int capacity, PDT  _setData);

//数据唯一的插入与删除
void HashBucketInsertUnique(HashBucket* ht, DataType data);
void HashBucketDeleteUnique(HashBucket* ht, DataType data);

//数据不唯一
void HashBucketInsert(HashBucket* ht, DataType data);
void HashBucketDelete(HashBucket* ht, DataType data);

//查找
PNode HashBucketFind(HashBucket* ht, DataType data);

//元素个数
int HashBucketSize(HashBucket*ht);

//销毁
void DestroyHashBucket(HashBucket* ht);

/////////////////////////////////////////////
//辅助方法

//哈希函数
int HashFunc(HashBucket* ht, int data);
//创建新节点
PNode BuyNode(DataType data);
//打印
void	 HashBucketPrint(HashBucket* ht);
//测试
void TestData();
void TestStr();