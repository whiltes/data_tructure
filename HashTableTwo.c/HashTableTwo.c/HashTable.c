#include "HashTable.h"



//��ʼ��
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



//�������
int CheckCapacity(HashTable *ht)
{
	if ((ht->_total) * 10 / (ht->_capacity) > 7)
		return 1;

	return 0;
}

//����
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


//����
void BuyCapacity(HashTable * ht)
{
	assert(ht);

	HashTable newht;
	int NewCapacity = GetCapacity(ht->_capacity);

	//��ʼ���µĹ�ϣ��
	HashTableInit(&newht, NewCapacity, ht->_Dete, ht->_setData);

	//����Ԫ��
	for (int i = 0; i < ht->_capacity; ++i)
	{
		if (ht->_table[i]._state == EXIST)
			HashTableInsert(&newht, ht->_table[i]._data);
	}

	//����
	Swop(&newht, ht);
	HashTableDestory(&newht);
}

//����
void HashTableInsert(HashTable *ht, DataType data)
{
	int HashAddr = 0;
	int i = 0;
	assert(ht);

	//�жϸ�������,�������
	if (CheckCapacity(ht))
	{
		BuyCapacity(ht);
	}

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);


	while (EMPTY != ht->_table[HashAddr]._state)
	{
		//��ƵĹ�ϣ���е�����Ψһ
		if (ht->_table[HashAddr]._state == EMPTY)
		{
			if (ht->_table[HashAddr]._data == data)
				return;
		}

		//������ĵ�ַ����ʹ�ã�������ϣ��ͻ
		if (ht->_Dete == _IsLine)
			HashAddr = IsLineDete(ht, HashAddr);
		else
			HashAddr = DeteTwo(ht, HashAddr, ++i);
	}

	//˵��״̬Ϊ�գ�����ֱ�Ӳ���
	ht->_table[HashAddr]._state = EXIST;
	ht->_table[HashAddr]._data = data;
	ht->_size++;
	ht->_total++;
}


//����Ԫ��,�ҵ����ص�ַ
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

		//����̽��
		if (ht->_Dete == _IsLine)

		{
			HashAddr = IsLineDete(ht, HashAddr);
			//��һȦ��û�ҵ�,�˳�
			if (HashAddr == StartAddr)
				return -1;

		}
		else//����̽��
			HashAddr = DeteTwo(ht, HashAddr, ++i);

	}

	return -1;
}


//ɾ��
void HashTableDelete(HashTable *ht, DataType data)
{
	assert(ht);
	if (-1 == HashTableFind(ht, data))
		return;

	ht->_table[HashTableFind(ht, data)]._state = DELETE;

	ht->_size--;
}


//Ԫ�ظ���
int HashTableSize(HashTable *ht)
{
	assert(ht);

	return ht->_size;
}

//�п�
int HashTableEmpty(HashTable *ht)
{
	assert(ht);

	if (0 == ht->_size)
		return 1;

	return 0;
}


// ���ٹ�ϣ��
void HashTableDestory(HashTable* ht)
{
	assert(ht);
	free(ht->_table);
	ht->_table = NULL;
	ht->_capacity = 0;
	ht->_size = 0;
	ht->_total = 0;
}



//��ϣ����
int HashFunc(HashTable* ht, int data)
{
	assert(ht);

	return data % (ht->_capacity);
}


//����̽��
int IsLineDete(HashTable* ht, int HashAddr)
{

	HashAddr = HashAddr + 1;
	if (HashAddr == ht->_capacity)//���Խ��
		HashAddr = 0;

	return HashAddr;
}

//����̽��
int DeteTwo(HashTable * ht, int HashAddr, int i)
{
	HashAddr = HashAddr + 2 * i + 1;

	//Խ��
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

	HashTableDelete(&ht, 13);//ɾ��
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

	HashTableDelete(&ht, "a");//ɾ��
	size = HashTableSize(&ht);

	HashTableDestory(&ht);
}
#endif