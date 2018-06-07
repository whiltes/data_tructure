#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>




////////////////////////////////////////////////////////////////////////////////////////////////////
//计数排序
void CountSort(int array[], int size)
{
	int range = 0;
	int index = 0;
	int MaxValue = array[0]; int MinValue = array[0];
	int i = 0;

	for (; i < size; ++i)
	{
		if (array[i] > MaxValue)
			MaxValue = array[i];
		if (array[i] < MinValue)
			MinValue = array[i];
	}
	//先找出这组数值集中的范围
	//在测试时，一直free错误，原因时这里没有+1
	//导致内存分配不足；

	range = MaxValue - MinValue + 1;

	int * count = (int *)malloc(sizeof(int) * range);
	if (NULL == count)
	{
		assert(0);
		return;
	}

	memset(count, 0, range*sizeof(int));

	//统计每个元素出现的次数
	for (i = 0; i < size; ++i)
	{
		count[array[i] - MinValue]++;
	}

	//回收元素
	for (i = 0; i < range; ++i)
	{
		while (count[i]--)
			array[index++] = i + MinValue;
	}

	free(count);

}
//////////////////////////////////////////////////////////////////////////////////////
//基排序

//算一个这组数最大是几位数
int GetBitCount(int* array, int size)
{
	int count = 1;
	int radix = 10; //设置的基数
	int i = 0;

	for (i = 0; i < size; i++)
	{
		while (array[i] >= radix)
		{
			count++;
			radix *= 10;
		}
	}
	return count;
}

#if 0
int getdigit(int x, int d)
{
	int a[] = { 1, 1, 10, 100 };   //最大三位数，所以这里只要百位就满足了。  
	return (x / a[d]) % 10;
}
#endif


void RadixSort(int array[], int size)
{
	int bitCount = GetBitCount(array, size);
	int bitIdx = 0;
	int radix = 1;
	int *tmp = (int*)malloc(sizeof(array[0])* size);
	if (NULL == tmp)
	{
		assert(0);

		return;
	}

	//有几位数，就要循环几次
	for (bitIdx = 0; bitIdx < bitCount; ++bitIdx)
	{
		int count[10] = { 0 };
		int i = 0;
		int StartAddr[10] = { 0 };

		//统计每个桶的元素个数
		for (i = 0; i < size; i++)
			count[array[i] / radix % 10]++;

		//统计每个桶的起始地址,这里不是i<size,因为桶的个数是10个。
		for (i = 1; i < 10; i++)
			StartAddr[i] = StartAddr[i - 1] + count[i - 1];

		//将数据放到对应桶中
		for (i = 0; i < size; i++)
		{
			int bucketNo = (array[i] / radix) % 10;
			tmp[StartAddr[bucketNo]] = array[i];
			StartAddr[bucketNo]++;
		}

		//回收数据(按桶编号从小到大，每个桶按先进先出)
		memcpy(array, tmp, sizeof(array[0]) * size);

		radix *= 10;
	}

	free(tmp);
}



/////////////////////////////////////////////////////////////////

void Print(int array[], int size)
{
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
	}

	putchar('\n');
}


void Test()
{
	/*int array[] = { 3, 4, 3, 2, 1, 2, 6, 5, 7 };
	int size = sizeof(array) / sizeof(array[0]);*/

	int array[] = { 81, 22, 78, 93, 14, 55, 65, 28, 39 };
	int size = sizeof(array) / sizeof(array[0]);
	Print(array, size);
	RadixSort (array, size);
	//CountSort(array, size);
	Print(array, size);
}