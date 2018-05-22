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
}

//查找
int BitMapFind(BitMap *bm, size_t data)
{
	assert(bm);

	int Addr = data >> 5;
	int bit = data % 32;

	return	(bm->_bit[Addr] & (1 << bit)) != 0;
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

	BitMapDestory(&bm);
}
