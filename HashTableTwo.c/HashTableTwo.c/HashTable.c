#include "HashTable.h"



//初始化
void HashTableInit(HashTable * ht, int capacity, IsLine Dete, PDT setData)
{
	assert(ht);

	capacity = GetCapacity(capacity);
	ht->_table = (Elem*)malloc(sizeof(Elem)*capacity);

	if (NULL == ht->_table)
		return;

	for (int i = 0; i < capacity; i++)
		ht->_table[i]._state = EMPTY;

	ht->_capacity = capacity;
	ht->_size = 0;
	ht->_total = 0;
	ht->_setData = setData;
	ht->_Dete = Dete;
}



//检测容量
int CheckCapacity(HashTable *ht)
{
	if ((ht->_total) * 10 / (ht->_capacity) > 7)
		return 1;

	return 0;
}

//交换
void _Swop(int * newht, int* oldht)
{
	int temp = *newht;
	*newht = *oldht;
	*oldht = temp;
}


void Swop(HashTable* newht, HashTable* oldht)
{
	Elem * pTemp = newht->_table;
	newht->_table = oldht->_table;
	oldht->_table = pTemp;

	_Swop(&newht->_capacity, &oldht->_capacity);
	_Swop(&newht->_size, &oldht->_size);
	_Swop(&newht->_total, &oldht->_total);

}


//扩容
void BuyCapacity(HashTable * ht)
{
	assert(ht);

	HashTable newht;
	int NewCapacity = GetCapacity(ht->_capacity);

	//初始化新的哈希表
	HashTableInit(&newht, NewCapacity, ht->_Dete, ht->_setData);

	//拷贝元素
	for (int i = 0; i < ht->_capacity; ++i)
	{
		if (ht->_table[i]._state == EXIST)
			HashTableInsert(&newht, ht->_table[i]._data);
	}

	//交换
	Swop(&newht, ht);
	HashTableDestory(&newht);
}

//插入
void HashTableInsert(HashTable *ht, DataType data)
{
	int HashAddr = 0;
	int i = 0;
	assert(ht);

	//判断负载因子,检测容量
	if (CheckCapacity(ht))
	{
		BuyCapacity(ht);
	}

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);


	while (EMPTY != ht->_table[HashAddr]._state)
	{
		//设计的哈希表中的数据唯一
		if (ht->_table[HashAddr]._state == EMPTY)
		{
			if (ht->_table[HashAddr]._data == data)
				return;
		}

		//计算出的地址不能使用，发生哈希冲突
		if (ht->_Dete == _IsLine)
			HashAddr = IsLineDete(ht, HashAddr);
		else
			HashAddr = DeteTwo(ht, HashAddr, ++i);
	}

	//说明状态为空，可以直接插入
	ht->_table[HashAddr]._state = EXIST;
	ht->_table[HashAddr]._data = data;
	ht->_size++;
	ht->_total++;
}


//查找元素,找到返回地址
int HashTableFind(HashTable * ht, DataType data)
{
	int HashAddr = 0;
	int StartAddr = 0;
	int i = 0;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	StartAddr = HashAddr;

	while (EMPTY != ht->_table[HashAddr]._state)
	{
		if (ht->_table[HashAddr]._state == EXIST)
		{
			if (ht->_table[HashAddr]._data == data)
				return HashAddr;
		}

		//线性探测
		if (ht->_Dete == _IsLine)

		{
			HashAddr = IsLineDete(ht, HashAddr);
			//找一圈都没找到,退出
			if (HashAddr == StartAddr)
				return -1;

		}
		else//二次探测
			HashAddr = DeteTwo(ht, HashAddr, ++i);

	}

	return -1;
}


//删除
void HashTableDelete(HashTable *ht, DataType data)
{
	assert(ht);
	if (-1 == HashTableFind(ht, data))
		return;

	ht->_table[HashTableFind(ht, data)]._state = DELETE;

	ht->_size--;
}


//元素个数
int HashTableSize(HashTable *ht)
{
	assert(ht);

	return ht->_size;
}

//判空
int HashTableEmpty(HashTable *ht)
{
	assert(ht);

	if (0 == ht->_size)
		return 1;

	return 0;
}


// 销毁哈希表
void HashTableDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_capacity = 0;
	ht->_size = 0;
	ht->_total = 0;
}



//哈希函数
int HashFunc(HashTable* ht, int data)
{
	assert(ht);

	return data % (ht->_capacity);
}


//线性探测
int IsLineDete(HashTable* ht, int HashAddr)
{

	HashAddr = HashAddr + 1;
	if (HashAddr == ht->_capacity)//如果越界
		HashAddr = 0;

	return HashAddr;
}

//二次探测
int DeteTwo(HashTable * ht, int HashAddr, int i)
{
	HashAddr = HashAddr + 2 * i + 1;

	//越界
	if (HashAddr >= ht->_capacity)
		HashAddr %= ht->_capacity;
	return HashAddr;
}


void TestHashData()
{
	HashTable ht;
	HashTableInit(&ht, 10, _IsLine, DataToInt);
	HashTableInsert(&ht, 5);
	HashTableInsert(&ht, 9);
	HashTableInsert(&ht, 13);
	HashTableInsert(&ht, 10);
	HashTableInsert(&ht, 2);
	HashTableInsert(&ht, 13);
	HashTableInsert(&ht, 10);
	HashTableInsert(&ht, 2);
	HashTableInsert(&ht, 8);
	int size = HashTableSize(&ht);
	DataType data = ht._table[HashTableFind(&ht, 9)]._data;

	HashTableDelete(&ht, 13);//删除
	size = HashTableSize(&ht);

	HashTableDestory(&ht);
}


#if 0
void TestHashStr()
{
	HashTable ht;
	HashTableInit(&ht, 10, _IsLine, StrToInt);
	HashTableInsert(&ht, "b");
	HashTableInsert(&ht, "ca");
	HashTableInsert(&ht, "a");
	HashTableInsert(&ht, "ac");

	int size = HashTableSize(&ht);
	DataType data = ht._table[HashTableFind(&ht, "ac")]._data;

	HashTableDelete(&ht, "a");//删除
	size = HashTableSize(&ht);

	HashTableDestory(&ht);
}
#endif