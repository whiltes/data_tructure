#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>




////////////////////////////////////////////////////////////////////////////////////////////////////
//��������
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
	//���ҳ�������ֵ���еķ�Χ
	//�ڲ���ʱ��һֱfree����ԭ��ʱ����û��+1
	//�����ڴ���䲻�㣻

	range = MaxValue - MinValue + 1;

	int * count = (int *)malloc(sizeof(int) * range);
	if (NULL == count)
	{
		assert(0);
		return;
	}

	memset(count, 0, range*sizeof(int));

	//ͳ��ÿ��Ԫ�س��ֵĴ���
	for (i = 0; i < size; ++i)
	{
		count[array[i] - MinValue]++;
	}

	//����Ԫ��
	for (i = 0; i < range; ++i)
	{
		while (count[i]--)
			array[index++] = i + MinValue;
	}

	free(count);

}
//////////////////////////////////////////////////////////////////////////////////////
//������

//��һ������������Ǽ�λ��
int GetBitCount(int* array, int size)
{
	int count = 1;
	int radix = 10; //���õĻ���
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
	int a[] = { 1, 1, 10, 100 };   //�����λ������������ֻҪ��λ�������ˡ�  
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

	//�м�λ������Ҫѭ������
	for (bitIdx = 0; bitIdx < bitCount; ++bitIdx)
	{
		int count[10] = { 0 };
		int i = 0;
		int StartAddr[10] = { 0 };

		//ͳ��ÿ��Ͱ��Ԫ�ظ���
		for (i = 0; i < size; i++)
			count[array[i] / radix % 10]++;

		//ͳ��ÿ��Ͱ����ʼ��ַ,���ﲻ��i<size,��ΪͰ�ĸ�����10����
		for (i = 1; i < 10; i++)
			StartAddr[i] = StartAddr[i - 1] + count[i - 1];

		//�����ݷŵ���ӦͰ��
		for (i = 0; i < size; i++)
		{
			int bucketNo = (array[i] / radix) % 10;
			tmp[StartAddr[bucketNo]] = array[i];
			StartAddr[bucketNo]++;
		}

		//��������(��Ͱ��Ŵ�С����ÿ��Ͱ���Ƚ��ȳ�)
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