
#pragma once
#include <assert.h>
#include <malloc.h>


typedef struct BitMap
{
	size_t *_bit;
	size_t _capacity;			//��Ҫ���ٸ�bitλ
	size_t _size;			//�ж��ٸ�Ԫ��

}BitMap;


//λͼ��ʼ��
void BitMapInit(BitMap * bm, size_t capacity);

//bitλ��1
void BitMapSet(BitMap *bm, size_t data);

//bitλ��0
void BitMapReset(BitMap *bm, size_t data);

//����
int BitMapFind(BitMap *bm, size_t data);

//����
void BitMapDestory(BitMap *bm);


//����
void BitMapTest();

