
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H_

#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include "Common.h"




//��ϣ��λ�õ�״̬
typedef enum State
{
	EMPTY,	//��ǰλ��Ϊ��
	EXIST,	//��ǰλ����Ԫ��
	DELETE	//������λ�ñ�ɾ��
}State;

typedef int DataType;
//typedef char* DataType;

//ת��Int����ָ��
typedef size_t(*PDT)(DataType str);

//��ֵ��
typedef struct Elem
{
	DataType _data;
	State _state;
}Elem;

typedef enum 
{
	_IsLine,			//����̽��
	_IsNotLine		//����̽��
}IsLine;


//��ϣ��
typedef struct HashTable
{
	Elem * _table;		
	int _capacity;		//����
	int _size;		//EX�ĸ���
	int _total;			//EX/DE�ܹ��ĸ���
	IsLine _Dete;			//̽�ⷽ��
	PDT  _setData;		//������ת��Ϊ���ͣ�
}HashTable;


//��ʼ��
void HashTableInit(HashTable * ht, int capacity, IsLine _Dete, PDT setData);

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

// ���ٹ�ϣ��
void HashTableDestory(HashTable* ht);


////////////////////////////////////////
//̽�ⷽ��

//����̽��
int IsLineDete(HashTable *ht, int HashAddr);

//����̽��
int DeteTwo(HashTable *ht, int HashAddr,int i);


/////////////////////////////////////////////
//��������

//��ϣ����
int HashFunc(HashTable* ht, int data);
//����̽��
int IsLineDete(HashTable* ht, int HashAddr);
//����̽��
int DeteTwo(HashTable * ht, int HashAddr, int i);



//����

void TestHashData();
void TestHashStr();


#endif