#include "BSTree.h"

// 初始化二叉搜索树
void InitBSTree(BSTNode** pRoot)
{
	assert(pRoot);

	*pRoot = NULL;

}

// 插入值为data的元素
void InsertBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode * pCur = NULL;
	BSTNode * pParent = NULL;

	//如果根结点为空，直接插入
	if (NULL == (*pRoot))
		*pRoot = BuyBSTNode(data);

	pCur = *pRoot;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
		//如果有结点和data相等，直接返回 
		else
		{
			return;
		}
	}

	pCur = BuyBSTNode(data);

	//如果双亲的值大于它，则让双亲的左指针域指向它
	if (pParent->_data > pCur->_data)
	{
		pParent->pLeft = pCur;
	}
	else
	{
		pParent->pRight = pCur;
	}

}

//递归
int  InseretBSTreeD(BSTNode** pRoot, DataType data)
{
	//如果根结点为空，直接插入
	if (NULL == (*pRoot))
	{
		*pRoot = BuyBSTNode(data);
		return 1;
	}

	if ((*pRoot)->_data > data)
		return InseretBSTreeD(&(*pRoot)->pLeft, data);
	else if ((*pRoot)->_data < data)
		return InseretBSTreeD(&(*pRoot)->pRight, data);
	else
		return 0;
}




// 删除值为data的结点
void DeleteBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode *pCur = NULL;
	BSTNode *pParent = NULL;
	BSTNode *pDel = NULL;

	assert(pRoot);
	if (NULL == (*pRoot))
		return;

	pCur = *pRoot;

	while (pCur)
	{
		if (pCur->_data > data)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}
		else if (pCur->_data < data)
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
		else
		{
			break;
		}
	}

	if (pCur)
	{
		pDel = pCur;
		//如果只有左孩子或者无左孩子
		if (NULL == pCur->pRight)
		{
			//如果时根结点的左孩子
			if ((*pRoot)->pLeft == pCur)
				(*pRoot)->pLeft = pCur->pLeft;
			else
			{
				if (pParent->pLeft == pCur)
					pParent->pLeft = pCur->pLeft;
				else
					pParent->pRight = pCur->pLeft;
			}
		}
		//如果只有右孩子
		else if (pCur->pRight)
		{
			if ((*pRoot)->pRight == pCur)
				(*pRoot)->pRight = pCur->pRight;
			else
			{
				if (pParent->pRight == pCur)
					pParent->pRight = pCur->pRight;
				else
					pParent->pLeft = pCur->pRight;
			}
		}
		//如果有两个孩子
		else
		{
			pParent = pCur;
			pDel = pCur->pRight;

			//查找右子树里最左边的结点
			while (pDel->pLeft)
			{
				pParent = pDel;
				pDel = pDel->pLeft;
			}
			//找到了，替换
			pCur->_data = pDel->_data;

			if (pParent->pLeft == pDel)
				pParent->pLeft = pDel->pRight;
			else
				pParent->pRight = pDel->pRight;
		}
		free(pDel);
		pDel = NULL;
	}

}


//递归删除
void DeleteBSTreeD(BSTNode** pRoot, DataType data)
{
	BSTNode *pDel = NULL;
	assert(pRoot);
	if (NULL == (*pRoot))
		return;
	else if ((*pRoot)->_data > data)
		DeleteBSTreeD(&(*pRoot)->pLeft, data);
	else if ((*pRoot)->_data < data)
		DeleteBSTreeD(&(*pRoot)->pRight, data);
	else
	{
		pDel = *pRoot;
		//只有左孩子或者无孩子
		if (NULL == (*pRoot)->pRight)
		{
			(*pRoot) = (*pRoot)->pLeft;
			free(pDel);
			pDel = NULL;
		}
		//只有右孩子
		else if ((*pRoot)->pLeft)
		{
			(*pRoot) = (*pRoot)->pRight;
			free(pDel);
			pDel = NULL;
		}
		else
		{
			pDel = (*pRoot)->pRight;
			while (pDel->pLeft)
			{
				pDel = pDel->pLeft;
			}
			(*pRoot)->_data = pDel->_data;
			DeleteBSTreeD(&pDel->pRight, data);
		}
	}
}


// 在二叉搜索树中查找值为data的结点
BSTNode* FindBSTree(BSTNode* pRoot, DataType data)
{
	BSTNode * pCur = NULL;
	if (NULL == pRoot)
		return NULL;

	pCur = pRoot;
	while (pCur)
	{
		if (pCur->_data > data)
		{
			pCur = pCur->pLeft;
		}
		else if (pCur->_data < data)
		{
			pCur = pCur->pRight;
		}
		else if (pCur->_data == data)
		{
			return pCur;
		}
	}

	return NULL;

}


BSTNode* FindBSTreeD(BSTNode* pRoot, DataType data)
{
	if (NULL == pRoot)
		return NULL;

	if (pRoot->_data > data)
		return FindBSTreeD(pRoot->pLeft, data);
	else if (pRoot->_data < data)
		return FindBSTreeD(pRoot->pRight, data);
	else
		return pRoot;
}

// 中序遍历二叉搜索树
void PreOrder(BSTNode* pRoot)
{
	if (NULL == pRoot)
		return;
	if (pRoot)
	{
		PreOrder(pRoot->pLeft);
		printf("%d ", pRoot->_data);
		PreOrder(pRoot->pRight);
	}
}


// 销毁二叉搜索树
void DestroyBSTree(BSTNode** pRoot)
{
	if (NULL == *pRoot)
		return;
	else
	{
		//如果左子树存在，销毁左子树
		if ((*pRoot)->pLeft)
		{
			DestroyBSTree(&(*pRoot)->pLeft);
		}
		//如果右子树存在，销毁右子树
		if ((*pRoot)->pRight)
		{
			DestroyBSTree(&(*pRoot)->pRight);
		}
		//销毁根结点
		free((*pRoot));
		(*pRoot) = NULL;
	}
}

//创建新节点
BSTNode * BuyBSTNode(DataType data)
{
	BSTNode *pNewNode = (BSTNode *)malloc(sizeof(BSTNode));

	if (NULL == pNewNode)
	{
		assert(0);
	}

	pNewNode->_data = data;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;

	return pNewNode;
}


void Test()
{
	BSTNode * pRoot;

	InitBSTree(&pRoot);
	InsertBSTree(&pRoot, 5);
	InsertBSTree(&pRoot, 3);
	InsertBSTree(&pRoot, 6);
	InsertBSTree(&pRoot, 9);
	InsertBSTree(&pRoot, 8);	
	InsertBSTree(&pRoot, 4);
	InsertBSTree(&pRoot, 2);
	InsertBSTree(&pRoot, 1);
	InsertBSTree(&pRoot, 7);

	printf("PreOrder: ");
	PreOrder(pRoot);
	putchar('\n');

	InsertBSTree(&pRoot, 10);

	DeleteBSTree(&pRoot, 8);

	printf("PreOrder:");
	PreOrder(pRoot);
	putchar('\n');

	BSTNode * Find = FindBSTree(pRoot, 5);

	DestroyBSTree(& pRoot);
}