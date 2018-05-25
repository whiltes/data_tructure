#include "BitMap.h"



//位图初始化
void BitMapInit(BitMap * bm, size_t capacity)
{
	assert(bm);
	//加一是因为capacity/32可能会有余数,
	bm->_capacity = ((capacity >> 5) + 1);

	bm->_bit = (size_t*)malloc(sizeof(size_t)*bm->_capacity);
	assert(bm->_bit);

	bm->_size = 0;

	for (size_t i = 0; i < bm->_capacity; ++i)
	{
		bm->_bit[i] = 0;
	}
}

//bit位置1
void BitMapSet(BitMap *bm, size_t data)
{
	assert(bm);
	//data除32，算出data应该在那个整型位上
	int Addr = data >> 5;
	//算出data应该在那个bit位上
	int bit = data % 32;

	bm->_bit[Addr] |= 1 << bit;
	bm->_size++;

}

//bit位置0
void BitMapReset(BitMap *bm, size_t data)
{
	assert(bm);
	int Addr = data >> 5;
	int bit = data % 32;

	bm->_bit[Addr] &= ~(1 << bit);
	bm->_size--;
}

//查找
int BitMapFind(BitMap *bm, size_t data)
{
	assert(bm);

	int Addr = data >> 5;
	int bit = data % 32;

	return	(bm->_bit[Addr] & (1 << bit)) != 0;
}


//查看元素个数
int BitMapSize(BitMap * bm)
{
	assert(bm);

	return bm->_size;
}

//查看bit位为1的个数
int BitMapCount(BitMap* bm)
{
	int i = 0;
	int count = 0;
	const char bitCount[] = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";//'\'相当于逗号，将0-15一的个数直接写在表中

	for (; i < bm->_capacity; i++)
	{
		int tmp = bm->_bit[i];
		int j = 0;

		//每一次循环算一个字节中比特位的个数
		while (j < sizeof(bm->_bit[0]))
		{
			char c = tmp;
			count += bitCount[c & 0x0f];//每次只能算四个比特位中1的个数

			c >>= 4;
			count += bitCount[c & 0x0f];

			tmp >>= 8;//算第二个字节
			j++;
		}
	}

	return count;
}

//销毁
void BitMapDestory(BitMap *bm)
{
	assert(bm);

	free(bm->_bit);
	bm->_capacity = 0;
	bm->_size = 0;
}


void BitMapTest()
{
	BitMap bm;

 	BitMapInit(&bm, 100);
	BitMapSet(&bm, 32);
	BitMapSet(&bm, 33); 
	BitMapSet(&bm, 34);
	int ret = BitMapFind(&bm, 33);
	BitMapReset(&bm, 34);

	//BitMapDestory(&bm); 
	int size = BitMapSize(&bm);
	int count = BitMapCount(&bm);
}
