#include "BSTree.h"

// ��ʼ������������
void InitBSTree(BSTNode** pRoot)
{
	assert(pRoot);

	*pRoot = NULL;

}

// ����ֵΪdata��Ԫ��
void InsertBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode * pCur = NULL;
	BSTNode * pParent = NULL;

	//��������Ϊ�գ�ֱ�Ӳ���
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
		//����н���data��ȣ�ֱ�ӷ��� 
		else
		{
			return;
		}
	}

	pCur = BuyBSTNode(data);

	//���˫�׵�ֵ������������˫�׵���ָ����ָ����
	if (pParent->_data > pCur->_data)
	{
		pParent->pLeft = pCur;
	}
	else
	{
		pParent->pRight = pCur;
	}

}

//�ݹ�
int  InseretBSTreeD(BSTNode** pRoot, DataType data)
{
	//��������Ϊ�գ�ֱ�Ӳ���
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




// ɾ��ֵΪdata�Ľ��
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
		//���ֻ�����ӻ���������
		if (NULL == pCur->pRight)
		{
			//���ʱ����������
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
		//���ֻ���Һ���
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
		//�������������
		else
		{
			pParent = pCur;
			pDel = pCur->pRight;

			//����������������ߵĽ��
			while (pDel->pLeft)
			{
				pParent = pDel;
				pDel = pDel->pLeft;
			}
			//�ҵ��ˣ��滻
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


//�ݹ�ɾ��
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
		//ֻ�����ӻ����޺���
		if (NULL == (*pRoot)->pRight)
		{
			(*pRoot) = (*pRoot)->pLeft;
			free(pDel);
			pDel = NULL;
		}
		//ֻ���Һ���
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


// �ڶ����������в���ֵΪdata�Ľ��
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

// �����������������
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


// ���ٶ���������
void DestroyBSTree(BSTNode** pRoot)
{
	if (NULL == *pRoot)
		return;
	else
	{
		//������������ڣ�����������
		if ((*pRoot)->pLeft)
		{
			DestroyBSTree(&(*pRoot)->pLeft);
		}
		//������������ڣ�����������
		if ((*pRoot)->pRight)
		{
			DestroyBSTree(&(*pRoot)->pRight);
		}
		//���ٸ����
		free((*pRoot));
		(*pRoot) = NULL;
	}
}

//�����½ڵ�
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