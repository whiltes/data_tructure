
#pragma once

#include <stdio.h>
#include <windows.h>

typedef int(*Compare)(int a, int b);


//������
void HeapSort(int *array, int size ,Compare com);

//����Ԫ��
void Swop(int *a,int *b);

//������
void AdjustHeap(int* array, int size, int parent,Compare com);

//����
int Down(int a, int b);

//����
int Up(int a, int b);

//����
void test();
