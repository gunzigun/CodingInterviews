#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;
	BinaryTreeNode(int num) :m_nValue(num){}
};

int TreeDeepth(BinaryTreeNode* pRoot)
{
	if (!pRoot)
	{
		return 0;
	}
	int nLeftDeepth = TreeDeepth(pRoot->m_pLeft);
	int nRightDeepth = TreeDeepth(pRoot->m_pRight);
	return (nLeftDeepth > nRightDeepth) ? (nLeftDeepth + 1) : (nRightDeepth + 1);
}

bool IsBalancedNormal(BinaryTreeNode* pRoot)
{
	if (!pRoot)
	{
		return true;
	}

	int left = TreeDeepth(pRoot->m_pLeft);
	int right = TreeDeepth(pRoot->m_pRight);
	int diff = left - right;
	if (diff < -1 || diff > 1)
	{
		return false;
	}

	return IsBalancedNormal(pRoot->m_pLeft) && IsBalancedNormal(pRoot->m_pRight);
}

bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
	if (!pRoot)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft,&left) && IsBalanced(pRoot->m_pRight,&right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}

void main()
{
	BinaryTreeNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5), Node6(6), Node7(7);
	Node1.m_pLeft = &Node2;
	Node1.m_pRight = &Node3;
	Node2.m_pLeft = &Node4;
	Node2.m_pRight = &Node5;
	Node3.m_pRight = &Node6;
	Node5.m_pLeft = &Node7;
	BinaryTreeNode* pRoot = &Node1;

	cout << "题目一：" << TreeDeepth(pRoot) << endl;

	cout << "题目二：解法1：" << IsBalancedNormal(pRoot) << endl;
	cout << "题目二：解法2：" << IsBalanced(pRoot) << endl;
}
