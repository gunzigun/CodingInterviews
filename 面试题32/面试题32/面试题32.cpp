#include <iostream>
#include <queue>
#include <stack>
using namespace std;


struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft=NULL;
	BinaryTreeNode* m_pRight=NULL;

	BinaryTreeNode(int num)
	{
		m_nValue = num;
	}
};


void PrintFromTopToButton(BinaryTreeNode* pRoot)
{
	if (!pRoot)
	{
		return;
	}

	queue<BinaryTreeNode*> myQueue;

	myQueue.push(pRoot);

	while (!myQueue.empty())
	{
		BinaryTreeNode* pNode = myQueue.front();
		myQueue.pop();
		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft)
		{
			myQueue.push(pNode->m_pLeft);
		}

		if (pNode->m_pRight)
		{
			myQueue.push(pNode->m_pRight);
		}
	}
	cout << endl;
}

void PrintFromTopToButtonDiffLine(BinaryTreeNode* pRoot)
{
	if (!pRoot)
	{
		return;
	}

	queue<BinaryTreeNode*> myQueue;
	myQueue.push(pRoot);
	int ToBePrint = 1;
	int NextLevel = 0;
	
	while (!myQueue.empty())
	{
		BinaryTreeNode* pNode = myQueue.front();
		myQueue.pop();
		cout << pNode->m_nValue << " ";

		--ToBePrint;

		if (pNode->m_pLeft)
		{
			myQueue.push(pNode->m_pLeft);
			++NextLevel;
		}

		if (pNode->m_pRight)
		{
			myQueue.push(pNode->m_pRight);
			++NextLevel;
		}

		if (ToBePrint==0)
		{
			cout << endl;
			ToBePrint = NextLevel;
			NextLevel = 0;
		}
	}
}


void PrintFromTopToButtonDiffLineZ(BinaryTreeNode* pRoot)
{
	if (!pRoot)
	{
		return;
	}

	queue<BinaryTreeNode*> myQueue;
	stack<BinaryTreeNode*> myStack;
	myQueue.push(pRoot);
	int ToBePrint = 1;
	int NextLevel = 0;
	bool bReverse = false;
	while (!myQueue.empty())
	{
		BinaryTreeNode* pNode = myQueue.front();
		myQueue.pop();

		--ToBePrint;

		if (pNode->m_pLeft)
		{
			myQueue.push(pNode->m_pLeft);
			++NextLevel;
		}

		if (pNode->m_pRight)
		{
			myQueue.push(pNode->m_pRight);
			++NextLevel;
		}

		
		if (!bReverse)
		{
			cout << pNode->m_nValue << " ";
		}
		else
		{
			myStack.push(pNode);
		}

		if (ToBePrint == 0)
		{
			while (bReverse && !myStack.empty())
			{
				BinaryTreeNode* pTemp = myStack.top();
				cout << pTemp->m_nValue << " ";
				myStack.pop();
			}

			cout << endl;
			ToBePrint = NextLevel;
			NextLevel = 0;
			bReverse = !bReverse;
		}
	}
}

void main()
{
	BinaryTreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7),
		node8(8), node9(9), node10(10), node11(11), node12(12), node13(13), node14(14), node15(15);

	node1.m_pLeft = &node2;
	node1.m_pRight = &node3;
	node2.m_pLeft = &node4;
	node2.m_pRight = &node5;
	node3.m_pLeft = &node6;
	node3.m_pRight = &node7;
	node4.m_pLeft = &node8;
	node4.m_pRight = &node9;
	node5.m_pLeft = &node10;
	node5.m_pRight = &node11;
	node6.m_pLeft = &node12;
	node6.m_pRight = &node13;
	node7.m_pLeft = &node14;
	node7.m_pRight = &node15;

	cout << "不分行从上到下打印二叉树" << endl;
	PrintFromTopToButton(&node1);
	
	cout << "-----------------------------------------------------------------" << endl;

	cout << "分行从上到下打印二叉树" << endl;
	PrintFromTopToButtonDiffLine(&node1);

	cout << "-----------------------------------------------------------------" << endl;

	cout << "之字形从上到下打印二叉树" << endl;
	PrintFromTopToButtonDiffLineZ(&node1);
}