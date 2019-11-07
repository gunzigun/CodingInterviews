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

bool IsSymmetricalTree(BinaryTreeNode* pNode1, BinaryTreeNode* pNode2)
{
	if (!pNode1 && !pNode2)
	{
		return true;
	}

	if (!pNode1 || !pNode2)
	{
		return false;
	}

	if (pNode1->m_nValue != pNode2->m_nValue)
	{
		return false;
	}

	return IsSymmetricalTree(pNode1->m_pLeft, pNode2->m_pRight)
		&& IsSymmetricalTree(pNode1->m_pRight, pNode2->m_pLeft);
}

bool IsSymme(BinaryTreeNode* pRoot)
{
	return IsSymmetricalTree(pRoot, pRoot);
}



void main()
{
	BinaryTreeNode Tree1Node1(8), Tree1Node2(6), Tree1Node3(9), Tree1Node4(5), Tree1Node5(7), Tree1Node6(7), Tree1Node7(5);
	Tree1Node1.m_pLeft = &Tree1Node2;
	Tree1Node1.m_pRight = &Tree1Node3;
	Tree1Node2.m_pLeft = &Tree1Node4;
	Tree1Node2.m_pRight = &Tree1Node5;
	Tree1Node3.m_pLeft = &Tree1Node6;
	Tree1Node3.m_pRight = &Tree1Node7;
	BinaryTreeNode* pRoot = &Tree1Node1;

	if (IsSymme(pRoot))
	{
		cout << "¶Ô³Æ" << endl;
	}
	else
	{
		cout << "·Ç¶Ô³Æ" << endl;
	}
}