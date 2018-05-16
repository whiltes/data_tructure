
#pragma once
#include <stdio.h>

#define MAX_SIZE 10

typedef int DataType;

typedef enum
{	
	EMPTY,
	EXIST,
	DELTE
}State;

typedef struct Elem
{
	DataType _data;
	State _s;
}Elem;

typedef struct HashTable
{	
	Elem table[MAX_SIZE];
	int _size;
	int _total;
}HashTable;


//初始化
void HashTableInit(HashTable * ht);

//插入
void HashTableInsert(HashTable *ht, DataType data);

//删除
void HashTableDelete(HashTable *ht, DataType data);

//查找
int HashTableFind(HashTable *ht, DataType data);

//元素个数
int HashTableSize(HashTable *ht);

//判空
int HashTableEmpty(HashTable *ht);

int HashFunc(DataType data);



//测试

void Test();



