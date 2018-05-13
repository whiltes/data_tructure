
#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DataType;
typedef struct BSTreeNode
{
	DataType _data;
	struct BSTreeNode * pLeft;
	struct BSTreeNode * pRight;
}BSTNode;


// ��ʼ������������
void InitBSTree(BSTNode** pRoot);

// ����ֵΪdata��Ԫ��
void InsertBSTree(BSTNode** pRoot, DataType data);

int InseretBSTreeD(BSTNode** pRoot, DataType data);

// ɾ��ֵΪdata�Ľ��
void DeleteBSTree(BSTNode** pRoot, DataType data);

void DeleteBSTreeD(BSTNode** pRoot, DataType data);

// �ڶ����������в���ֵΪdata�Ľ��
BSTNode* FindBSTree(BSTNode* pRoot, DataType data);

BSTNode* FindBSTreeD(BSTNode* pRoot, DataType data);


// �����������������
void PreOrder(BSTNode* pRoot);

// ���ٶ���������
void DestroyBSTree(BSTNode** pRoot);


//�����½ڵ�
BSTNode* BuyBSTNode(DataType data);


//����
void Test();