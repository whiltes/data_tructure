
#pragma once
#include <assert.h>
#include <malloc.h>


typedef struct BitMap
{
	size_t *_bit;
	size_t _capacity;			//需要多少个bit位
	size_t _size;			//有多少个元素

}BitMap;


//位图初始化
void BitMapInit(BitMap * bm, size_t capacity);

//bit位置1
void BitMapSet(BitMap *bm, size_t data);

//bit位置0
void BitMapReset(BitMap *bm, size_t data);

//查找
int BitMapFind(BitMap *bm, size_t data);

//销毁
void BitMapDestory(BitMap *bm);


//测试
void BitMapTest();

