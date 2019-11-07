#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
	BinaryTreeNode(int num):m_nValue(num){}
};

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k)
{
	BinaryTreeNode* pTarget = NULL;

	// 在左子树寻找
	if (pRoot->m_pLeft)
	{
		pTarget = KthNodeCore(pRoot->m_pLeft, k);
	}

	// 左子树没找到，此时k已经减去了左子树的节点个数
	if (!pTarget)
	{
		// 看看当前节点是不是第k个，如果是，则此时k必定为1
		if (k == 1)
		{
			pTarget = pRoot;
		}
		k--;
	}

	// 左子树，当前节点都不是，那么去右子树查找
	if (!pTarget)
	{
		if (pRoot->m_pRight)
		{
			pTarget = KthNodeCore(pRoot->m_pRight, k);
		}
	}

	return pTarget;
}


BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k)
{
	if (!pRoot || k <= 0)
	{
		return NULL;
	}

	return KthNodeCore(pRoot, k);
}

void main()
{
	BinaryTreeNode Node1(5), Node2(3), Node3(7), Node4(2), Node5(4), Node6(6), Node7(8);
	Node1.m_pLeft = &Node2;
	Node1.m_pRight = &Node3;
	Node2.m_pLeft = &Node4;
	Node2.m_pRight = &Node5;
	Node3.m_pLeft = &Node6;
	Node3.m_pRight = &Node7;

	BinaryTreeNode* pRoot = &Node1;
	
	cout << "开始中序遍历树：" << endl;
	for (int i = 1; i < 100; ++i)
	{
		BinaryTreeNode* pINode = KthNode(pRoot, i);
		if (pINode)
		{
			cout << pINode->m_nValue << " ";
		}
	}
	cout << endl;

	int k = 5;
	cout << "树的第 " << k << " 个节点是：" << endl;
	BinaryTreeNode* pFind = KthNode(pRoot, k);
	if (pFind)
	{
		cout << pFind->m_nValue << endl;
	}

}
