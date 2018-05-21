
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H_

#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "Common.h"




//哈希表位置的状态
typedef enum State
{
	EMPTY,	//当前位置为空
	EXIST,	//当前位置有元素
	DELETE	//档期那位置被删除
}State;

typedef int DataType;
//typedef char* DataType;

//转换Int函数指针
typedef size_t(*PDT)(DataType str);

//键值对
typedef struct Elem
{
	DataType _data;
	State _state;
}Elem;

typedef enum 
{
	_IsLine,			//线性探测
	_IsNotLine		//二次探测
}IsLine;


//哈希表
typedef struct HashTable
{
	Elem * _table;		
	int _capacity;		//容量
	int _size;		//EX的个数
	int _total;			//EX/DE总共的个数
	IsLine _Dete;			//探测方法
	PDT  _setData;		//将数据转化为整型，
}HashTable;


//初始化
void HashTableInit(HashTable * ht, int capacity, IsLine _Dete, PDT setData);

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

// 销毁哈希表
void HashTableDestory(HashTable* ht);


////////////////////////////////////////
//探测方法

//线性探测
int IsLineDete(HashTable *ht, int HashAddr);

//二次探测
int DeteTwo(HashTable *ht, int HashAddr,int i);


/////////////////////////////////////////////
//辅助方法

//哈希函数
int HashFunc(HashTable* ht, int data);
//线性探测
int IsLineDete(HashTable* ht, int HashAddr);
//二次探测
int DeteTwo(HashTable * ht, int HashAddr, int i);



//测试

void TestHashData();
void TestHashStr();


#endif