
#pragma once

#include <stdio.h>
#include <windows.h>

typedef int(*Compare)(int a, int b);


//¶ÑÅÅĞò
void HeapSort(int *array, int size ,Compare com);

//½»»»ÔªËØ
void Swop(int *a,int *b);

//µ÷Õû¶Ñ
void AdjustHeap(int* array, int size, int parent,Compare com);

//½µĞò
int Down(int a, int b);

//ÉıĞò
int Up(int a, int b);

//²âÊÔ
void test();
