#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	char m_chValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* Construct(char* preorder, char* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}

	char chValue = preorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_chValue = chValue;
	root->m_pLeft = root->m_pRight = root->m_pParent = NULL;

	int nIndex = 0;
	for (int i = 0; i < length; ++i)
	{
		if (chValue == inorder[i])
		{
			nIndex = i;
		}
	}
	root->m_pLeft = Construct(preorder + 1, inorder, nIndex);
	root->m_pRight = Construct(preorder + nIndex + 1, inorder + nIndex + 1, length - nIndex - 1);
	
	if (root->m_pLeft != NULL)
	{
		root->m_pLeft->m_pParent = root;
	}

	if (root->m_pRight != NULL)
	{
		root->m_pRight->m_pParent = root;
	}
	
	return root;
}

BinaryTreeNode* GetInOrderNext(BinaryTreeNode* pNode)
{
	if (pNode==NULL)
	{
		return NULL;
	}

	BinaryTreeNode* pNext = NULL;
	if (pNode->m_pRight != NULL)
	{
		BinaryTreeNode* p_Right = pNode->m_pRight;
		while (p_Right->m_pLeft != NULL)
		{
			p_Right = p_Right->m_pLeft;
		}
		pNext = p_Right;
	}
	else if (pNode->m_pParent != NULL)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != NULL && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pCurrent->m_pParent;
		}
		pNext = pParent;
	}

	return pNext;
}

void main()
{
	char preorder_array[] = {'a', 'b', 'd', 'e', 'h', 'i', 'c', 'f', 'g' };
	char inorder_array[] = {'d', 'b', 'h', 'e', 'i', 'a', 'f', 'c', 'g'};

	int length = sizeof(preorder_array) / sizeof(char);

	BinaryTreeNode* root = Construct(preorder_array, inorder_array, length);
	cout << "������������ϣ�" << endl;

	BinaryTreeNode* pNode = root;
	if (pNode != NULL)
	{
		cout << "��ǰ�ڵ�Ϊ��" << pNode->m_chValue << endl;
	}
	else
	{
		cout << "��ǰ�ڵ�Ϊ��NULL" << endl;
	}

	BinaryTreeNode* pNext = GetInOrderNext(pNode);
	if (pNext != NULL)
	{
		cout << "���������һ���ڵ�Ϊ��" << pNext->m_chValue << endl;
	}
	else
	{
		cout << "���������һ���ڵ�Ϊ��NULL" << endl;
	}
}