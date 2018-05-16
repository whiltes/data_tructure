
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


//��ʼ��
void HashTableInit(HashTable * ht);

//����
void HashTableInsert(HashTable *ht, DataType data);

//ɾ��
void HashTableDelete(HashTable *ht, DataType data);

//����
int HashTableFind(HashTable *ht, DataType data);

//Ԫ�ظ���
int HashTableSize(HashTable *ht);

//�п�
int HashTableEmpty(HashTable *ht);

int HashFunc(DataType data);



//����

void Test();



