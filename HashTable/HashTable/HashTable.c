#include "HashTable.h"


//初始化
void HashTableInit(HashTable * ht)
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		ht->table[i]._s = EMPTY;
	}

	ht->_total = 0;
	ht->_size = 0;
}

//插入
void HashTableInsert(HashTable *ht, DataType data)
{
	int HashAddr = -1;
	int StartAddr = -1;

	if (MAX_SIZE == ht->_total)
		return;

	HashAddr = HashFunc(data);
	StartAddr = HashAddr;

	while (EMPTY != ht->table[HashAddr]._s)
	{
		if (EXIST != ht->table[HashAddr]._s)
			HashAddr++;

		if (MAX_SIZE == HashAddr)
			HashAddr = 0;
		if (HashAddr == StartAddr)
			break;
	}

	ht->table[HashAddr]._data = data;
	ht->_size++;
	ht->_total++;
	ht->table[HashAddr]._s = EXIST;
}

//删除
void HashTableDelete(HashTable *ht, DataType data)
{
	if (0 == ht->_total)
		return;
	if (-1 != HashTableFind(ht, data))
	{
		ht->table[HashTableFind(ht, data)]._s = DELTE;
		ht->_total -= 1;
	}
}

//查找
int HashTableFind(HashTable *ht, DataType data)
{
	int HashAddr = -1;
	int StartAddr = -1;

	if (0 == ht->_total)
		return -1;

	HashAddr = HashFunc(data);
	StartAddr = HashAddr;

	while (EMPTY != ht->table[HashAddr]._s)
	{
		if (ht->table[HashAddr]._data == data)
		{
			return HashAddr;
		}

		HashAddr++;

		if (MAX_SIZE == HashAddr)
			HashAddr = 0;

		if (HashAddr == StartAddr)
			break;
	}

	return -1;
}

//元素个数
int HashTableSize(HashTable *ht)
{
	return ht->_total;
}

//判空
int HashTableEmpty(HashTable *ht)
{
	if (0 == ht->_size)
		return 1;

	return 0;
}

int HashFunc(DataType data)
{
	return data % MAX_SIZE;
}


void Test()
{
	HashTable ht;
	HashTableInit(&ht);
	HashTableInsert(&ht, 23);
	HashTableInsert(&ht, 44);
	HashTableInsert(&ht, 64);
	HashTableInsert(&ht, 11);
	HashTableInsert(&ht, 67);
	HashTableInsert(&ht, 80);
	HashTableDelete(&ht, 11);
	HashTableInsert(&ht, 21);
	DataType num = HashTableFind(&ht, 11);
	int size = HashTableSize(&ht); 
	int ret= HashTableEmpty(&ht);
}