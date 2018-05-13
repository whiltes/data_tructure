

#include "HeapSort.h"


void HeapSort(int *array, int size, Compare com)
{
	int root = (size - 2) >> 1;
	int end = size - 1;

	//先调整堆
	while (root>=0)
	{
		AdjustHeap(array, size, root, com);
		root--;
	}

	//最后一个节点与根节点交换后，end--，当根节点不满足堆的性质，调整
	while (end > 0)
	{
		Swop(&array[0], &array[end]);
		AdjustHeap(array, end, 0, com);
		end--;
	}

}

void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustHeap(int *array, int size, int parent, Compare com)
{
	int child = (parent << 1) + 1;

	while (child<size)
	{
		//找到两个孩子中较小的一个
		if (child + 1 < size && com(array[child+1], array[child]))
		{
			child += 1;
		}
		if (com(array[child], array[parent]))
		{
			Swop(&array[child], &array[parent]);

			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			break;
		}
	}

}


void Heap_Print(int *array, int size)
{
	int i = 0;
	for (; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


int Down(int a, int b)
{
	return a < b;
}

int Up(int a, int b)
{
	return a > b;
}

void test()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };

	Heap_Print(array, sizeof(array) / sizeof(array[0]));
	HeapSort(array, sizeof(array) / sizeof(array[0]), Down);
	Heap_Print(array, sizeof(array) / sizeof(array[0]));
}



