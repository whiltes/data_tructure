#include "HashBucket.h"

//哈希桶初始化
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

//插入唯一的
void HashBucketInsertUnique(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);


	//头节点不存数据
	PNode pCur = ht->_table[HashAddr];

	while (pCur)
	{
		if (pCur->_data == data)
			return;
		else
			pCur = pCur->_pNext;
	}

	//头插
	pCur = BuyNode(data);

	pCur->_pNext = ht->_table[HashAddr];
	ht->_table[HashAddr]= pCur;
	ht->_size++;
}

//删除唯一的
void HashBucketDeleteUnique(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	PNode pPre = NULL;
	PNode pCur = NULL;
	
	assert(ht);
	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//桶空着
	if (ht->_table[HashAddr] == NULL)
		return;

	 pPre = ht->_table[HashAddr];
	 pCur = ht->_table[HashAddr];

	//头节点值和data相等
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

	//这里必须判断pCur是否为空，就算没找到data节点，
	//pCur也会退出while循环
	if (pCur)
	{
		pPre->_pNext = pCur->_pNext;
		ht->_size--;
		free(pCur);
	}
}



//插入相同的
void HashBucketInsert(HashBucket* ht, DataType data)
{

	int HashAddr = -1;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//头插
	PNode pCur = BuyNode(data);
	pCur->_pNext = ht->_table[HashAddr];
	ht->_table[HashAddr] = pCur;
	ht->_size++;
}

//删除所有data的元素
void HashBucketDelete(HashBucket* ht, DataType data)
{
	int HashAddr = -1;
	PNode pPre = NULL;
	PNode pCur = NULL;
	assert(ht);

	int Newdata = ht->_setData(data);
	HashAddr = HashFunc(ht, Newdata);

	//桶空着
	if (ht->_table[HashAddr] == NULL)
		return;

	 pPre = ht->_table[HashAddr];
	 pCur = ht->_table[HashAddr];

	//头节点的值和data相等
	while (pCur&&pCur->_data == data)
	{
		ht->_table[HashAddr] = pCur->_pNext;
		free(pCur);
		ht->_size--;

		pCur = ht->_table[HashAddr];
	}

	//头节点判断完后，pCur还不为空，继续看后边的
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


//查找
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

//元素个数
int HashBucketSize(HashBucket*ht)
{
	return ht->_size;
}

//销毁
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

//哈希函数
int HashBucketFunc(HashBucket* ht, int data)
{
	assert(ht);

	return data % (ht->_capacity - 1);
}


//创建新节点
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

//打印
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
