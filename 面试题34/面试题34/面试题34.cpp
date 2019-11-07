#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft = NULL;
	BinaryTreeNode* m_pRight = NULL;

	BinaryTreeNode(int num)
	{
		m_nValue = num;
	}
};

void FindPathCore(BinaryTreeNode* pRoot, int nExceptSum, vector<int>& path, int nCurrentSum)
{
	if (!pRoot)
	{
		return;
	}

	int nNum = pRoot->m_nValue;
	nCurrentSum += nNum;
	path.push_back(nNum);

	// 如果这个节点是叶子节点
	if (!pRoot->m_pLeft && !pRoot->m_pRight)
	{
		if (nExceptSum == nCurrentSum)
		{
			cout << "找到了一条路径：";
			for (vector<int>::iterator iter = path.begin(); iter != path.end(); ++iter)
			{
				cout << *iter << " ";
			}
			cout << endl;
		}
	}
	// 否则，继续监测
	else
	{
		if (pRoot->m_pLeft)
		{
			FindPathCore(pRoot->m_pLeft, nExceptSum, path, nCurrentSum);
		}
		if (pRoot->m_pRight)
		{
			FindPathCore(pRoot->m_pRight, nExceptSum, path, nCurrentSum);
		}
	}

	// 在返回父节点时，回溯之前，需要删除当前节点
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int nExceptSum)
{
	if (!pRoot)
	{
		return;
	}

	vector<int> path;
	int nCurrentSun = 0;
	FindPathCore(pRoot, nExceptSum, path, nCurrentSun);
}

void main()
{
	BinaryTreeNode node1(10), node2(5), node3(12), node4(4), node5(7);

	node1.m_pLeft = &node2;
	node1.m_pRight = &node3;
	node2.m_pLeft = &node4;
	node2.m_pRight = &node5;

	FindPath(&node1, 22);

}
