#include <iostream>
using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext = NULL;
	ComplexListNode* m_pSibling = NULL;

	ComplexListNode(int num)
	{
		m_nValue = num;
	}
};

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode)
	{
		ComplexListNode* pClone = new ComplexListNode(pNode->m_nValue);
		pClone->m_pNext = pNode->m_pNext;
		pNode->m_pNext = pClone;
		
		pNode = pClone->m_pNext;
	}
}

void CloneSibling(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;

	while (pNode)
	{
		ComplexListNode* pClone = pNode->m_pNext;
		if (pNode->m_pSibling)
		{
			pClone->m_pSibling = pNode->m_pSibling->m_pNext;
		}

		pNode = pClone->m_pNext;
	}
}

ComplexListNode* DivideNode(ComplexListNode* pHead)
{

	if (!pHead)
	{
		return NULL;
	}
	ComplexListNode* pCloneHead = pHead->m_pNext;
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneNode = pCloneHead;

	pNode->m_pNext = pCloneNode->m_pNext;
	pNode = pNode->m_pNext;
	
	while (pNode)
	{
		pCloneNode->m_pNext = pNode->m_pNext;
		pCloneNode = pCloneNode->m_pNext;
		pNode->m_pNext = pCloneNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pCloneHead;
}

void main()
{
	ComplexListNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5);
	Node1.m_pNext = &Node2;
	Node1.m_pSibling = &Node3;
	Node2.m_pNext = &Node3;
	Node2.m_pSibling = &Node5;
	Node3.m_pNext = &Node4;
	Node4.m_pNext = &Node5;
	Node4.m_pSibling = &Node2;

	ComplexListNode* pHead = &Node1;

	// 第一步 A->B->C->D->E 变成 A->A'->B->B'->C->C'->D->D'->E->E'
	CloneNodes(pHead);
	// 第二步 为A'到E'建立Sibling指针
	CloneSibling(pHead);
	// 第三步 将链表拆分成两个
	ComplexListNode* pCloneHead = DivideNode(pHead);

	cout << "一切结束啦！" << endl;

}