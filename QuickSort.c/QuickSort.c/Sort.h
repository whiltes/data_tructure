

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
//��������


void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//ǰ��ָ�뷨

int Partion_3(int array[], int begin, int end)
{
	int pre = begin - 1;
	int cur = begin;
	int key = array[end - 1];

	while (cur < end)
	{
		if (array[cur] < key)
		{
			//��pre��cur���ʱ��˵��ǰ��Ԫ�ض�С�ڻ�׼ֵ
			pre++;
			//���pre������cur��˵���±�Ϊpre��ֵ���ڻ�׼ֵ
			//cur���������ߣ���cur�ҵ�һ��С�ڻ�׼ֵ��ֵʱ��
			//�����±�Ϊpre��cur��ֵ��
			if (pre != cur)
				Swop(&array[cur], &array[pre]);
		}
		cur++;
	}

	//��ʱcur�Ѿ��ߵ�end�����pre������cur��preָ�����С�ڻ�׼ֵ��ֵ
	//˵���±����pre�ĵ�ֵ�����ڻ�׼ֵ��
	//++pre����������׼ֵ�������λ��
	if (++pre != end)
		Swop(&array[pre], &array[end - 1]);

	return pre;
}



//�ڿӷ�
int Partion_2(int array[], int begin, int end)
{
	//����ҿ�����
	int left = begin;
	int right = end - 1;
	//ȷ����׼ֵ���������ұߵ�Ԫ���Ѿ���key���棬
	//��ʱ������һ����
	int key = array[right];

	while (left < right)
	{
		while (left < right && array[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			//���ұ߿ӣ������ұ߳����µĿ�
			array[right--] = array[left];
		}
		while (left < right && array[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			//����ߵĿӣ���߳����µĿ�
			array[left++] = array[right];
		}
	}

	//���ֻʣһ���ӣ�leftλ�õĿӡ�
	//��key����
	array[left] = key;


	return left;
}



//������
int Partion(int array[], int begin, int end)
{
	//����ҿ�
	int left = begin;
	int right = end - 1;

	int key = array[end-1];

	//��Ϊ������ҿ������䣬����û�еȺ�
	while (left < right)
	{
		//����߿�ʼ�ң��ҵ�һ�����ڻ�׼ֵ��ֵ
		while (left < right && array[left] <= key)
		{
			++left;
		}
		//���ұ߿�ʼ�ң��ҵ�һ��С�ڻ�׼ֵ��ֵ
		while (left < right && array[right] >= key)
		{
			--right;
		}
		//�ҵ��󣬽���
		if (left < right)
		{
			Swop(&array[left], &array[right]);
		}
	}
	//��ѭ����ֹ�󣬽����±�Ϊleft��end-1��Ԫ��
	//������׼ֵ����߶�С�ڻ�׼ֵ���ұ߶����ڻ�׼ֵ
	Swop(&array[left], &array[end - 1]);

	return left;
}


//�ݹ鷽ʽ
void _QuickSort(int array[], int begin, int end)
{
	if (end - begin <= 1)
		return;

	//ȡ���һ��Ԫ��Ϊ��׼ֵ
	int mid = Partion_3(array, begin, end);

	//������������
	_QuickSort(array, begin, mid);

	//������������
	//mid+1����Ϊ�����õ�������ҿ�������
	_QuickSort(array, mid + 1, end);
}

#if 0
//�ǵݹ�
void QuickSortNor(int array[], int size)
{
	if (size < 1)
		return;
	Stack s;
	StackInit(&s);

	//Partion�����õĶ�������ҿ�����
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
		
		//����ջ������
		StackPush(&s, begin);
		StackPush(&s, mid);

		//��ջ������
		StackPush(&s, mid + 1);
		StackPush(&s, end);
	}
}
#endif

void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size);
}




//ð������

void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		//j��ȡ��j+1�����Ӧ��С��size-i-1
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
	//����ҿ�����
	int leftL = left; int rightL = mid;
	int leftR = mid ; int rightR = right;
	int Index = left;

	while (leftL < rightL && leftR < rightR)
	{

		//�ȵ�С��
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
	//������������һ��Ԫ��
	//�������1������ʣһ��Ԫ�ص�ʱ�򣬻�һֱ���µݹ飬
	//���վͻ����ջ���
	if (left + 1 < right)
	{
		int mid = left + ((right - left) >> 1);
		//�ȵݹ������������
		_MergeSort(array, left, mid, temp);
		//�ݹ����ұ�������
		_MergeSort(array, mid , right, temp);
		//�������䶼������ڽ��кϲ�����
		_MergeData(array, left, mid, right, temp);

		//����Ԫ�ص��ɿռ�
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

//�ǵݹ�
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

			//���Խ�磬�����ǵ�������
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