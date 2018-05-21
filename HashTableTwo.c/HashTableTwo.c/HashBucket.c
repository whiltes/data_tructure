#include "HashBucket.h"

//��ϣͰ��ʼ��
void HashBucketInit(HashBucket* ht, int capacity, PDT setData)
{
	assert(ht);
	//capacity = GetCapacity(capacity);

	ht->_table = (PNode*)malloc(sizeof(Node)*capacity);
	if (NULL == ht->_table)
		assert(0), exit(1);

	ht->_capacity = capacity;
	ht->_size = 0;
	ht->_setData = setData;

	for (int i = 0; i < ht->_capacity; i++)
	{
		ht->_table[i] = NULL;
	}
}

//����Ψһ��
void HashBucketInsertUnique(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);


	//ͷ�ڵ㲻������
	PNode pCur = ht->_table[HashAddr];

	while (pCur)
	{
		if (pCur->_data == data)
			return;
		else
			pCur = pCur->_pNext;
	}

	//ͷ��
	pCur = BuyNode(data);

	pCur->_pNext = ht->_table[HashAddr];
	ht->_table[HashAddr]= pCur;
	ht->_size++;
}

//ɾ��Ψһ��
void HashBucketDeleteUnique(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	PNode pPre = NULL;
	PNode pCur = NULL;
	
	assert(ht);
	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//Ͱ����
	if (ht->_table[HashAddr] == NULL)
		return;

	 pPre = ht->_table[HashAddr];
	 pCur = ht->_table[HashAddr];

	//ͷ�ڵ�ֵ��data���
	if (pCur->_data == data)
	{
		ht->_table[HashAddr] = pCur->_pNext;
		free(pCur);
		ht->_size--;
		return;
	}

	while (pCur)
	{
		if (pCur->_data == data)
		{
			break;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}

	//��������ж�pCur�Ƿ�Ϊ�գ�����û�ҵ�data�ڵ㣬
	//pCurҲ���˳�whileѭ��
	if (pCur)
	{
		pPre->_pNext = pCur->_pNext;
		ht->_size--;
		free(pCur);
	}
}



//������ͬ��
void HashBucketInsert(HashBucket* ht, DataType data)
{

	int HashAddr = -1;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//ͷ��
	PNode pCur = BuyNode(data);
	pCur->_pNext = ht->_table[HashAddr];
	ht->_table[HashAddr] = pCur;
	ht->_size++;
}

//ɾ������data��Ԫ��
void HashBucketDelete(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	PNode pPre = NULL;
	PNode pCur = NULL;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//Ͱ����
	if (ht->_table[HashAddr] == NULL)
		return;

	 pPre = ht->_table[HashAddr];
	 pCur = ht->_table[HashAddr];

	//ͷ�ڵ��ֵ��data���
	while (pCur&&pCur->_data == data)
	{
		ht->_table[HashAddr] = pCur->_pNext;
		free(pCur);
		ht->_size--;

		pCur = ht->_table[HashAddr];
	}

	//ͷ�ڵ��ж����pCur����Ϊ�գ���������ߵ�
	while (pCur)
	{
		if (pCur->_data == data)
		{
			pPre->_pNext = pCur->_pNext;
			ht->_size--;
			free(pCur);
			pCur = pPre->_pNext;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->_pNext;
		}
	}

}


//����
PNode HashBucketFind(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);
	
	PNode pCur = ht->_table[HashAddr];
	while (pCur)
	{
		if (pCur->_data == data)
			break;
		else
			pCur = pCur->_pNext;
	}

	return pCur;
}

//Ԫ�ظ���
int HashBucketSize(HashBucket*ht)
{
	return ht->_size;
}

//����
void DestroyHashBucket(HashBucket* ht)
{
	assert(ht);

	PNode pDel = NULL;

	for (int i = 0; i < ht->_capacity; ++i)
	{
		pDel = ht->_table[i]->_pNext;
		while (pDel)
		{
			ht->_table[i]->_pNext = pDel->_pNext;
			free(pDel);
			pDel = ht->_table[i]->_pNext;
		}
	}

	free(ht->_table);
	ht->_size = 0;
	ht->_capacity = 0;
}

//��ϣ����
int HashBucketFunc(HashBucket* ht, int data)
{
	assert(ht);

	return data % (ht->_capacity - 1);
}


//�����½ڵ�
PNode BuyNode(DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
		return NULL;

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;

	return pNewNode;
}

//��ӡ
void	 HashBucketPrint(HashBucket* ht)
{
	PNode pCur = NULL;
	assert(ht);

	for (int i = 0; i < ht->_capacity; ++i)
	{
		printf("Hash Bucket No.%ld:   ", i);
		pCur = ht->_table[i];
		while (pCur)
		{
			if (ht->_setData == DataToInt)
			{
				printf("%d\t", pCur->_data);
			}
			else
			{
				printf("%s\t", pCur->_data);
			}
			pCur = pCur->_pNext;
		}
		putchar('\n');
	}
}


#if 0
void TestData()
{
	HashBucket ht;
	HashBucketInit(&ht, 12,  DataToInt);
	HashBucketInsertUnique(&ht, 1);
	HashBucketInsertUnique(&ht, 2);
	HashBucketInsertUnique(&ht, 5);
	HashBucketInsertUnique(&ht, 13);
	HashBucketInsertUnique(&ht, 24);
	HashBucketInsert(&ht, 2);
	HashBucketPrint(&ht);
	HashBucketDelete(& ht, 2);
	HashBucketPrint(&ht);
	//HashBucketDeleteUnique(&ht, 1);
	//HashBucketPrint(&ht);

}
#endif

void TestStr()
{
	HashBucket ht;
	HashBucketInit(&ht, 12, StrToInt);
	HashBucketInsertUnique(&ht, "lala");
	HashBucketInsertUnique(&ht, "hah");
	HashBucketInsertUnique(&ht, "pp");
	HashBucketInsertUnique(&ht, "dsf");
	HashBucketInsertUnique(&ht, "daf");
	HashBucketInsert(&ht, "lala");
	HashBucketPrint(&ht);
	HashBucketDelete(&ht, "lala");
	HashBucketPrint(&ht);

}
