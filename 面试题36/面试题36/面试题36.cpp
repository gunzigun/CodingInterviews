#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft = NULL;
	BinaryTreeNode*		m_pRight = NULL;

	BinaryTreeNode(int num)
	{
		m_nValue = num;
	}
};


void ConvertNode(BinaryTreeNode *pNode, BinaryTreeNode** pLastNode)
{
	if (!pNode)
	{
		return;
	}

	BinaryTreeNode* pCurrent = pNode;
	if (pCurrent->m_pLeft)
	{
		ConvertNode(pNode->m_pLeft, pLastNode);
	}

	pCurrent->m_pLeft = *pLastNode;
	if (*pLastNode)
	{
		(*pLastNode)->m_pRight = pCurrent;
	}

	*pLastNode = pCurrent;
	
	if (pCurrent->m_pRight)
	{
		ConvertNode(pCurrent->m_pRight, pLastNode);
	}
}


void main()
{
	BinaryTreeNode node1(10), node2(6), node3(14), node4(4), node5(8), node6(12), node7(16);
	node1.m_pLeft = &node2;
	node1.m_pRight = &node3;
	node2.m_pLeft = &node4;
	node2.m_pRight = &node5;
	node3.m_pLeft = &node6;
	node3.m_pRight = &node7;

	BinaryTreeNode* pRootOfTree = &node1;

	BinaryTreeNode* pLastNode = NULL;
	ConvertNode(pRootOfTree, &pLastNode);

	BinaryTreeNode* pNodeHead = pLastNode;
	while (pNodeHead && pNodeHead->m_pLeft)
	{
		pNodeHead = pNodeHead->m_pLeft;
	}


	// 从头到尾输出
	while (pNodeHead)
	{
		cout << pNodeHead->m_nValue << " ";
		pNodeHead = pNodeHead->m_pRight;
	}
	cout << endl;


	// 从尾到头输出
	BinaryTreeNode* pNodeTail = pLastNode;
	while (pNodeTail)
	{
		cout << pNodeTail->m_nValue << " ";
		pNodeTail = pNodeTail->m_pLeft;
	}
	cout << endl;

	
}