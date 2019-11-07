#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;

	BinaryTreeNode(int nNum)
	{
		m_nValue = nNum;
	}
};

void PreOrder(BinaryTreeNode* pNode)
{
	if (!pNode)
	{
		return;
	}

	cout << pNode->m_nValue << " ";
	PreOrder(pNode->m_pLeft);
	PreOrder(pNode->m_pRight);
}

void InOrder(BinaryTreeNode* pNode)
{
	if (!pNode)
	{
		return;
	}
	
	InOrder(pNode->m_pLeft);
	cout << pNode->m_nValue << " ";
	InOrder(pNode->m_pRight);
}

void MirrorTree(BinaryTreeNode* pNode)
{
	if (!pNode)
	{
		return;
	}
	if (!pNode->m_pLeft && !pNode->m_pRight)
	{
		return;
	}

	BinaryTreeNode* pTemp = pNode->m_pRight;
	pNode->m_pRight = pNode->m_pLeft;
	pNode->m_pLeft = pTemp;

	MirrorTree(pNode->m_pLeft);
	MirrorTree(pNode->m_pRight);
}

void main()
{
	BinaryTreeNode node1(8), node2(6), node3(10), node4(5), node5(7), node6(9), node7(11);
	node1.m_pLeft = &node2;
	node1.m_pRight = &node3;
	node2.m_pLeft = &node4;
	node2.m_pRight = &node5;
	node3.m_pLeft = &node6;
	node3.m_pRight = &node7;

	BinaryTreeNode* pRoot = &node1;

	cout << "前序遍历结果：" << endl;
	PreOrder(pRoot);
	cout << endl;

	cout << "中序遍历结果：" << endl;
	InOrder(pRoot);
	cout << endl;

	MirrorTree(pRoot);
	cout << "-------------------------------------" << endl;

	cout << "前序遍历结果：" << endl;
	PreOrder(pRoot);
	cout << endl;

	cout << "中序遍历结果：" << endl;
	InOrder(pRoot);
	cout << endl;
}