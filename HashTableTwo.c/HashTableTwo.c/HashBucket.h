
#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Common.h"


//typedef int DataType;
typedef char* DataType;

//ת��Int����ָ��
typedef size_t(*PDT)(DataType str);


typedef struct Node
{
	struct Node* _pNext;
	DataType _data;
}Node, *PNode;

//��ϣ��
typedef struct HashBucket
{
	PNode * _table;
	int _capacity;		//Ͱ�ĸ���
	int _size;			//Ԫ�ظ���
	PDT  _setData;		//������ת��Ϊ���ͣ�
}HashBucket;


//��ϣͰ��ʼ��
void HashBucketInit(HashBucket* ht, int capacity, PDT  _setData);

//����Ψһ�Ĳ�����ɾ��
void HashBucketInsertUnique(HashBucket* ht, DataType data);
void HashBucketDeleteUnique(HashBucket* ht, DataType data);

//���ݲ�Ψһ
void HashBucketInsert(HashBucket* ht, DataType data);
void HashBucketDelete(HashBucket* ht, DataType data);

//����
PNode HashBucketFind(HashBucket* ht, DataType data);

//Ԫ�ظ���
int HashBucketSize(HashBucket*ht);

//����
void DestroyHashBucket(HashBucket* ht);

/////////////////////////////////////////////
//��������

//��ϣ����
int HashFunc(HashBucket* ht, int data);
//�����½ڵ�
PNode BuyNode(DataType data);
//��ӡ
void	 HashBucketPrint(HashBucket* ht);
//����
void TestData();
void TestStr();