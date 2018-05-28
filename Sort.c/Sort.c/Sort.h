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
//直接插入排序
#if 0
void InsertSort(int array[], int size)
{

	//一张牌的时候不用排，因此i从1开始
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while(end >= 0 && key < array[end])
		{
			//array[end+1]的值已经给key了，因此可以覆盖
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

		//二分查找先找到位置，
#if 0
		int right = i - 1;
		//这里是左闭右闭区间，因此是小于等于
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);

			if (array[mid] > key)
				right = mid - 1;
			else
				left = mid + 1;
		}
		//找到元素的位置后，将left及其后边的元素都往后搬一个位置
		while (end >= left)
		{
			array[end + 1] = array[end];
			end--;
		}
#endif
		int right = i;
		//左闭右开区间
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
		//找到元素的位置后，将left及其后边的元素都往后搬一个位置
		while (end >= left)
		{
			array[end + 1] = array[end];
			--end;
		}

		array[end + 1] = key;
	}
}

//shell排序

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
			
			//这里的end必须大于等于0，否则数组会越界
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

//直接选择排序

void Select(int array[], int size)
{
	int end = size - 1;
	int begin = 0;
	int i = 0;

	//这里i的终止条件必须是size
	//如果是end，就会少排几次
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


//优化后的方法
void Select_OP(int array[], int size)
{
	int end = size - 1;
	int begin = 0;

	//因为end为size-1，闭区间，所以这里的i要小于等于end
	//终止条件不是size，是因为
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

		//如果最小值在末尾，最小值就会被换走，因此要更新Minpos的值
		if (Minpos == end)
			Minpos = Maxpos;

		if (Minpos != begin)
			Swop(&array[Minpos], &array[begin]);
		--end;
		++begin;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//堆排

void AdjustDown(int array[], int size, int parent)
{
	int child = (parent << 1) + 1;

	//这里就是所说的循环条件
	while (child <= size)
	{
		//找到两个孩子中较大的一个
		if (child + 1 <= size && array[child + 1] > array[child])
		{
			child = child + 1;
		}
		//比较parent和孩子的大小
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

//升序-->将大堆
void HeapSort(int array[], int size)
{
	int root = (size - 2) >> 1;
	int end = size - 1;
	//建堆
	while (root >= 0)
	{
		AdjustDown(array, size, root);
		root--;
	}

	//排序
	while (end >= 0)
	{
		//交换根节点和最后一个元素
		Swop(&array[end], &array[0]);


		//这里的end--和向下调整的顺序，取决于向下调整里的循环条件
		//如果是闭区间，则end需要在前边，如果是开区间，则end在后边

		//最后一个元素已经排好，因此下次调整堆，不应包括此节点
		end--;

		//不满足大堆性质，调整
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


