

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

void Print(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
//快速排序


void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//前后指针法

int Partion_3(int array[], int begin, int end)
{
	int pre = begin - 1;
	int cur = begin;
	int key = array[end - 1];

	while (cur < end)
	{
		if (array[cur] < key)
		{
			//当pre和cur相等时，说明前边元素都小于基准值
			pre++;
			//如果pre不等于cur，说明下标为pre的值大于基准值
			//cur继续往后走，当cur找到一个小于基准值的值时，
			//交换下表为pre，cur的值，
			if (pre != cur)
				Swop(&array[cur], &array[pre]);
		}
		cur++;
	}

	//这时cur已经走到end，如果pre不等于cur，pre指向的是小于基准值的值
	//说明下标大于pre的的值都大于基准值，
	//++pre交换，将基准值放在这个位置
	if (++pre != end)
		Swop(&array[pre], &array[end - 1]);

	return pre;
}



//挖坑法
int Partion_2(int array[], int begin, int end)
{
	//左闭右开区间
	int left = begin;
	int right = end - 1;
	//确定基准值，并且左右边的元素已经被key保存，
	//此时出现了一个坑
	int key = array[right];

	while (left < right)
	{
		while (left < right && array[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			//填右边坑，并且右边出现新的坑
			array[right--] = array[left];
		}
		while (left < right && array[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			//填左边的坑，左边出现新的坑
			array[left++] = array[right];
		}
	}

	//最后只剩一个坑，left位置的坑。
	//将key填入
	array[left] = key;


	return left;
}



//交换法
int Partion(int array[], int begin, int end)
{
	//左闭右开
	int left = begin;
	int right = end - 1;

	int key = array[end-1];

	//因为是左闭右开的区间，所以没有等号
	while (left < right)
	{
		//从左边开始找，找到一个大于基准值的值
		while (left < right && array[left] <= key)
		{
			++left;
		}
		//从右边开始找，找到一个小于基准值的值
		while (left < right && array[right] >= key)
		{
			--right;
		}
		//找到后，交换
		if (left < right)
		{
			Swop(&array[left], &array[right]);
		}
	}
	//当循环终止后，交换下标为left和end-1的元素
	//这样基准值的左边都小于基准值，右边都大于基准值
	Swop(&array[left], &array[end - 1]);

	return left;
}


//递归方式
void _QuickSort(int array[], int begin, int end)
{
	if (end - begin <= 1)
		return;

	//取最后一个元素为基准值
	int mid = Partion_3(array, begin, end);

	//排序左子区间
	_QuickSort(array, begin, mid);

	//排序右子区间
	//mid+1是因为我们用的是左闭右开的区间
	_QuickSort(array, mid + 1, end);
}

#if 0
//非递归
void QuickSortNor(int array[], int size)
{
	if (size < 1)
		return;
	Stack s;
	StackInit(&s);

	//Partion函数用的都是左闭右开区间
	int begin = 0;
	int end = size;

	StackPush(&s, end);
	StackPush(&s, begin);

	while (!StackEmpty(&s))
	{
		begin = StackTop(&s);
		StackPop(&s);
		end = StackTop(&s);
		StackPop(&s);

		int mid = Partion(array, begin, end);
		
		//先入栈左区间
		StackPush(&s, begin);
		StackPush(&s, mid);

		//入栈右区间
		StackPush(&s, mid + 1);
		StackPush(&s, end);
	}
}
#endif

void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size);
}




//冒泡排序

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		//j会取到j+1，因此应该小于size-i-1
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j + 1] < array[j])
			{
				Swop(&array[j + 1], &array[j]);
			}
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////



void _MergeData(int array[], int left, int mid, int right, int *temp)
{
	//左闭右开区间
	int leftL = left; int rightL = mid;
	int leftR = mid ; int rightR = right;
	int Index = left;

	while (leftL < rightL && leftR < rightR)
	{

		//先当小的
		if (array[leftL] < array[leftR])
		{
			temp[Index++] = array[leftL++];
		}
		else
		{
			temp[Index++] = array[leftR++];
		}
	}
	while (leftL < rightL)
	{
		temp[Index++] = array[leftL];
		++leftL;
	}
	while (leftR < rightR)
	{
		temp[Index++] = array[leftR];
		++leftR;
	}

}

void _MergeSort(int array[], int left, int right, int* temp)
{
	//至少区间里有一个元素
	//如果不加1程序在剩一个元素的时候，会一直往下递归，
	//最终就会造成栈溢出
	if (left + 1 < right)
	{
		int mid = left + ((right - left) >> 1);
		//先递归排左边子序列
		_MergeSort(array, left, mid, temp);
		//递归排右边子序列
		_MergeSort(array, mid , right, temp);
		//左右区间都有序后，在进行合并数据
		_MergeData(array, left, mid, right, temp);

		//拷贝元素到旧空间
		memcpy(array + left,temp + left, (right - left)*sizeof(array[0]));
	}
}

void MergeSort(int array[], int size)
{
	int *temp = (int *)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, temp);

	free(temp);
}

//非递归
void MergeSortNor(int array[], int size)
{
	int *temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	int gap = 1;

	for (; gap < size; gap *= 2)
	{
		int i = 0;
		for (; i < size; i += 2 * gap)
		{
			int begin = i;
			int mid = begin + gap;
			int right = mid + gap;

			//如果越界，则将它们调整回来
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;

			_MergeData(array, begin, mid, right, temp);
		}

		memcpy(array, temp, sizeof(int)*size);
	}
	free(temp);
}


/////////////////////////////////////////////////////////////////////////////////////////////
//Test


void QuickSortTest()
{
	int array[] = { 2, 0, 4, 9, 3, 6, 8, 7, 1, 5 };
	int size = sizeof(array) / sizeof(array[0]);

	Print(array, size);
	putchar('\n');
	//QuickSortNor(array, size);
	//BubbleSort(array, size);
	//MergeSort(array, size);
	MergeSortNor(array, size);
	Print(array, size);
	putchar('\n');
}