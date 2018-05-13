#include "Heap.h"


//堆的初始化
void HeapInit(Heap *hp, Compare cmp)
{
	if (NULL == hp)
		return;

	hp->_size = 0;
	hp->cmp = cmp;
}


//创建堆
void CreateHeap(Heap *hp, DataType *array, int size)
 {
	assert(hp);

	//申请空间
	hp->_array = (DataType *)malloc(sizeof(DataType)*size);
	if (NULL == hp)
		assert(0);
	hp->_size = 0;
	hp->_capacity = size;

	//赋值
	for (int i = 0; i < size; ++i)
	{
		hp->_array[i] = array[i];
		hp->_size += 1;
	}
	hp->_capacity = size;
	//找出最后一个非叶子节点
	int root = (size - 1 - 1) >> 1;

	//调整元素
	for (; root >= 0; root--)
		AdjustDown(hp,root);
}

void Swop(DataType *left, DataType *right)
{
	DataType temp = *left;
	*left = *right;
	*right = temp;
}

//向上调整
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


//向下调整
void AdjustDown(Heap  *hp, DataType parent)
{
	int child = (parent<<1)+1;

	if (NULL == hp)
		return;
	while (child < hp->_size)
	{
		//找到孩子中较小的一个
		if ((child+1) < hp->_size && 
			hp->cmp(hp->_array[child+1], hp->_array[child]))
		{
			child += 1;
		}
		//如果双亲大于孩子，则交换
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


//插入
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


//检测容量
void CheckCatacity(Heap *hp)
{
	if (hp->_capacity <= hp->_size)
	{
		DataType * pNewCatacity= (DataType *)malloc(sizeof(DataType)*hp->_capacity*2);
		assert(pNewCatacity);
		//将原来的数据拷到新空间
		memcpy(pNewCatacity, hp->_array, sizeof(DataType)*hp->_size);
		//释放旧空间
		free(hp->_array);
		hp->_array = pNewCatacity;
		hp->_capacity = hp->_capacity * 2;
	}
}

//删除
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

//取堆顶元素
DataType TopHeap(Heap *hp)
{
	assert(hp);

	return hp->_array[0];
}

//查看元素个数
int SizeHeap(Heap *hp)
{
	return hp->_size;
}

//判断堆是否为空
int EmptyHeap(Heap *hp)
{
	if (NULL == hp)
		return 1;

	return 0;
}


//销毁堆
void DestoryHeap(Heap *hp)
{
	assert(hp);
	if (EmptyHeap(hp))
		return;

	hp->_size = 0;
	hp->cmp = NULL;
}



//小堆
int Less(DataType a, DataType b)
{
	return  a < b;
}


//大堆
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
