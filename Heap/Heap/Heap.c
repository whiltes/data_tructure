#include "Heap.h"


//�ѵĳ�ʼ��
void HeapInit(Heap *hp, Compare cmp)
{
	if (NULL == hp)
		return;

	hp->_size = 0;
	hp->cmp = cmp;
}


//������
void CreateHeap(Heap *hp, DataType *array, int size)
 {
	assert(hp);

	//����ռ�
	hp->_array = (DataType *)malloc(sizeof(DataType)*size);
	if (NULL == hp)
		assert(0);
	hp->_size = 0;
	hp->_capacity = size;

	//��ֵ
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size += 1;
	}
	hp->_capacity = size;
	//�ҳ����һ����Ҷ�ӽڵ�
	int root = (size - 1 - 1) >> 1;

	//����Ԫ��
	for (; root >= 0; root--)
		AdjustDown(hp,root);
}

void Swop(DataType *left, DataType *right)
{
	DataType temp = *left;
	*left = *right;
	*right = temp;
}

//���ϵ���
void AdjustUp(Heap *hp, int child)
{
	int parent = (child - 1) >> 1;

	while (child)
	{
		if (hp->cmp(hp->_array[child] , hp->_array[parent]))
		{
			Swop(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
			break;
	}
}


//���µ���
void AdjustDown(Heap  *hp, DataType parent)
{
	int child = (parent<<1)+1;

	if (NULL == hp)
		return;
	while (child < hp->_size)
	{
		//�ҵ������н�С��һ��
		if ((child+1) < hp->_size && 
			hp->cmp(hp->_array[child+1], hp->_array[child]))
		{
			child += 1;
		}
		//���˫�״��ں��ӣ��򽻻�
		if (hp->cmp(hp->_array[child], hp->_array[parent]))
		{
			Swop(&hp->_array[parent], &hp->_array[child]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			break;
		}
	}
}


//����
void InsertHeap(Heap *hp, DataType data)
{
	if (NULL == hp)
		return;
	CheckCatacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;

	if (hp->_size > 1)
	AdjustUp(hp, hp->_size - 1);
}


//�������
void CheckCatacity(Heap *hp)
{
	if (hp->_capacity <= hp->_size)
	{
		DataType * pNewCatacity= (DataType *)malloc(sizeof(DataType)*hp->_capacity*2);
		assert(pNewCatacity);
		//��ԭ�������ݿ����¿ռ�
		memcpy(pNewCatacity, hp->_array, sizeof(DataType)*hp->_size);
		//�ͷžɿռ�
		free(hp->_array);
		hp->_array = pNewCatacity;
		hp->_capacity = hp->_capacity * 2;
	}
}

//ɾ��
void DeleteHeap(Heap *hp)
{
	assert(hp);
	if (NULL == hp)
		return;
	if (EmptyHeap(hp))
		return;

	Swop(&hp->_array[0], &hp->_array[hp->_size-1]);
	hp->_size--;
	AdjustDown(hp, 0);
}

//ȡ�Ѷ�Ԫ��
DataType TopHeap(Heap *hp)
{
	assert(hp);

	return hp->_array[0];
}

//�鿴Ԫ�ظ���
int SizeHeap(Heap *hp)
{
	return hp->_size;
}

//�ж϶��Ƿ�Ϊ��
int EmptyHeap(Heap *hp)
{
	if (NULL == hp)
		return 1;

	return 0;
}


//���ٶ�
void DestoryHeap(Heap *hp)
{
	assert(hp);
	if (EmptyHeap(hp))
		return;

	hp->_size = 0;
	hp->cmp = NULL;
}



//С��
int Less(DataType a, DataType b)
{
	return  a < b;
}


//���
int Greater(DataType a, DataType b)
{
	return a > b;
}

//////////////////////////////////////////////////////////////////////////

void TestHeap()
{
	Heap hp;
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };

	HeapInit(&hp, Less);
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	InsertHeap(&hp, 13);

	DataType top = TopHeap(&hp);
	int ret = EmptyHeap(&hp);

	DestoryHeap(&hp);
}
