#include "Common.h"

int GetCapacity(size_t capacity)
{
	int i = 0;
	for (; i < 28; i++)
	{
		if (capacity < _PrimeList[i])
			return _PrimeList[i];
	}

	return _PrimeList[27];
}

//���ַ���ת��Ϊ����
size_t StrToInt(const char * str)
{
	unsigned int seed = 131; // 31 131 1313 13131 131313
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}
	return (hash & 0x7FFFFFFF);
}

//����ת�޷�������
size_t DataToInt(int data)
{
	return data;
}