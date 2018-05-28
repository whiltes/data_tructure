#include <stdio.h>

///////////////////////////////////////////////////

void Print(int array[], int size);


void InsertSort(int array[], int size);

/////////////////////////////////////////////////

void Print(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////
//ֱ�Ӳ�������
#if 0
void InsertSort(int array[], int size)
{

	//һ���Ƶ�ʱ�����ţ����i��1��ʼ
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while(end >= 0 && key < array[end])
		{
			//array[end+1]��ֵ�Ѿ���key�ˣ���˿��Ը���
			array[end + 1] = array[end];
			end--;
		}
		
		array[end + 1] = key;
	}

}
#endif

void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{

		int key = array[i];
		int end = i - 1;
		int left = 0;

		//���ֲ������ҵ�λ�ã�
#if 0
		int right = i - 1;
		//����������ұ����䣬�����С�ڵ���
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);

			if (array[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}
		//�ҵ�Ԫ�ص�λ�ú󣬽�left�����ߵ�Ԫ�ض������һ��λ��
		while (end >= left)
		{
			array[end + 1] = array[end];
			end--;
		}
#endif
		int right = i;
		//����ҿ�����
		while (left < right)
		{
			int mid = left + ((right - left) >> 1);

			if (array[mid] >key)
			{
				right = mid;
			}
			else
				left = mid + 1;
		}
		//�ҵ�Ԫ�ص�λ�ú󣬽�left�����ߵ�Ԫ�ض������һ��λ��
		while (end >= left)
		{
			array[end + 1] = array[end];
			--end;
		}

		array[end + 1] = key;
	}
}

//shell����

void ShellSort(int array[], int size)
{
	int gap = size;
	
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i += gap)
		{
			int key = array[i];
			int end = i - gap;
			
			//�����end������ڵ���0�����������Խ��
			while (end >= 0&&array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}

	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
void Swop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//ֱ��ѡ������

void Select(int array[], int size)
{
	int end = size - 1;
	int begin = 0;
	int i = 0;

	//����i����ֹ����������size
	//�����end���ͻ����ż���
	for ( i = begin; i <= size; ++i)
	{
		int Maxpos = begin;

		for (int j = begin; j <= end; ++j)
		{
			if (array[Maxpos] < array[j])
				Maxpos = j;
		}

		if (Maxpos != end)
			Swop(&array[Maxpos], &array[end]);

		--end;
	}
}


//�Ż���ķ���
void Select_OP(int array[], int size)
{
	int end = size - 1;
	int begin = 0;

	//��ΪendΪsize-1�������䣬���������iҪС�ڵ���end
	//��ֹ��������size������Ϊ
	for (int i = begin; i <= end; ++i)
	{
		int Maxpos = begin;
		int Minpos = begin;

		for (int j = begin + 1; j <= end; ++j)
		{
			if (array[Maxpos] < array[j])
				Maxpos = j;
			if (array[Minpos] > array[j])
				Minpos = j;
		}
		if (Maxpos != end)
			Swop(&array[Maxpos], &array[end]);

		//�����Сֵ��ĩβ����Сֵ�ͻᱻ���ߣ����Ҫ����Minpos��ֵ
		if (Minpos == end)
			Minpos = Maxpos;

		if (Minpos != begin)
			Swop(&array[Minpos], &array[begin]);
		--end;
		++begin;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//����

void AdjustDown(int array[], int size, int parent)
{
	int child = (parent << 1) + 1;

	//���������˵��ѭ������
	while (child <= size)
	{
		//�ҵ����������нϴ��һ��
		if (child + 1 <= size && array[child + 1] > array[child])
		{
			child = child + 1;
		}
		//�Ƚ�parent�ͺ��ӵĴ�С
		if (array[parent] < array[child])
		{

			Swop(&array[parent], &array[child]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			break;
		}
	}
}

//����-->�����
void HeapSort(int array[], int size)
{
	int root = (size - 2) >> 1;
	int end = size - 1;
	//����
	while (root >= 0)
	{
		AdjustDown(array, size, root);
		root--;
	}

	//����
	while (end >= 0)
	{
		//�������ڵ�����һ��Ԫ��
		Swop(&array[end], &array[0]);


		//�����end--�����µ�����˳��ȡ�������µ������ѭ������
		//����Ǳ����䣬��end��Ҫ��ǰ�ߣ�����ǿ����䣬��end�ں��

		//���һ��Ԫ���Ѿ��źã�����´ε����ѣ���Ӧ�����˽ڵ�
		end--;

		//�����������ʣ�����
		AdjustDown(array, end, 0);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////
//Test


void InsertSortTest()
{

	int array[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int size = sizeof(array) / sizeof(array[0]);

	Print(array, size);
	putchar('\n');
	//InsertSort(array, size);
	//ShellSort(array, size);
	//Select(array, size);
	HeapSort(array, size);
	Print(array, size);
	putchar('\n');
}


