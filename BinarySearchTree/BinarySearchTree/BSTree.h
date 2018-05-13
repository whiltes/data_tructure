
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


// 初始化二叉搜索树
void InitBSTree(BSTNode** pRoot);

// 插入值为data的元素
void InsertBSTree(BSTNode** pRoot, DataType data);

int InseretBSTreeD(BSTNode** pRoot, DataType data);

// 删除值为data的结点
void DeleteBSTree(BSTNode** pRoot, DataType data);

void DeleteBSTreeD(BSTNode** pRoot, DataType data);

// 在二叉搜索树中查找值为data的结点
BSTNode* FindBSTree(BSTNode* pRoot, DataType data);

BSTNode* FindBSTreeD(BSTNode* pRoot, DataType data);


// 中序遍历二叉搜索树
void PreOrder(BSTNode* pRoot);

// 销毁二叉搜索树
void DestroyBSTree(BSTNode** pRoot);


//创建新节点
BSTNode* BuyBSTNode(DataType data);


//测试
void Test();