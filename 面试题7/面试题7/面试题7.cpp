#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}

	int nValue = preorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = nValue;
	root->m_pLeft = root->m_pRight = NULL;

	int nIndex = 0;
	for (int i = 0; i < length; ++i)
	{
		if (nValue == inorder[i])
		{
			nIndex = i;
		}
	}
	root->m_pLeft = Construct(preorder + 1, inorder, nIndex);
	root->m_pRight = Construct(preorder + nIndex + 1, inorder + nIndex + 1, length - nIndex - 1);
	return root;
}

void PreOrder(BinaryTreeNode* root)
{
	if (root!=NULL)
	{
		cout << root->m_nValue;
		PreOrder(root->m_pLeft);
		PreOrder(root->m_pRight);
	}
}

void PreOrder_NoCycle(BinaryTreeNode* root)
{
	stack <BinaryTreeNode*> MyStack;

	MyStack.push(root);

	while (!MyStack.empty())
	{
		BinaryTreeNode* pNode = MyStack.top();
		BinaryTreeNode* pLeft = pNode->m_pLeft;
		BinaryTreeNode* pRight = pNode->m_pRight;
		cout << pNode->m_nValue; 
		MyStack.pop();
		if (pRight != NULL)
		{
			MyStack.push(pRight);
		}
		if (pLeft != NULL)
		{
			MyStack.push(pLeft);
		}
	}
}

void InOrder(BinaryTreeNode* root)
{
	if (root!=NULL)
	{
		InOrder(root->m_pLeft);
		cout << root->m_nValue;
		InOrder(root->m_pRight);
	}
}

void InOrder_NoCycle(BinaryTreeNode* root)
{
	stack <BinaryTreeNode*> MyStack;
	
	BinaryTreeNode* pNode = root;
	while (pNode || !MyStack.empty())
	{
		while (pNode)
		{
			MyStack.push(pNode);
			pNode = pNode->m_pLeft;
		}

		if (!MyStack.empty())
		{
			pNode = MyStack.top();
			MyStack.pop();
			cout << pNode->m_nValue;
			pNode = pNode->m_pRight;
			
		}
	}
}

void AfterOrder(BinaryTreeNode* root)
{
	if (root != NULL)
	{
		AfterOrder(root->m_pLeft);
		AfterOrder(root->m_pRight);
		cout << root->m_nValue;
	}
}

void AfterOrder_NoCycle(BinaryTreeNode* root)
{
	stack <BinaryTreeNode*> MyStack;
	stack <BinaryTreeNode*> ShowStack;

	BinaryTreeNode* pNode = root;
	while (pNode || !MyStack.empty())
	{
		while (pNode)
		{
			MyStack.push(pNode);
			ShowStack.push(pNode);
			pNode = pNode->m_pRight;
		}

		if (!MyStack.empty())
		{
			pNode = MyStack.top();
			MyStack.pop();
			pNode = pNode->m_pLeft;
		}
	}

	while (!ShowStack.empty())
	{
		cout << ShowStack.top()->m_nValue;
		ShowStack.pop();
	}
}

void main()
{
	int preorder_array[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder_array[] = {4, 7, 2, 1, 5, 3, 8, 6};
	int length = sizeof(preorder_array) / sizeof(int);
	
	BinaryTreeNode* root = Construct(preorder_array, inorder_array, length);
	cout << "二叉树构建完毕！" << endl;

	cout << "开始前序输出二叉树！" << endl;
	PreOrder(root); cout << endl;
	PreOrder_NoCycle(root); cout << endl;
	
	cout << "开始中序输出二叉树！" << endl;
	InOrder(root); cout << endl;
	InOrder_NoCycle(root); cout << endl;
	
	cout << "开始后序输出二叉树！" << endl;
	AfterOrder(root); cout << endl;
	AfterOrder_NoCycle(root); cout << endl;
}