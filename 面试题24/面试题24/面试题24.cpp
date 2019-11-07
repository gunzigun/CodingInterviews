#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext = NULL;

	ListNode(int nunber)
	{
		this->m_nValue = nunber;
	}
};

void showAllNode(ListNode* pNode)
{
	cout << "链表的各个元素: ";
	while (pNode)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPre = NULL;

	while (pNode)
	{
		ListNode* pNext = pNode->m_pNext;

		if (!pNext)
		{
			pReverseHead = pNode;
		}

		pNode->m_pNext = pPre;
		
		pPre = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}

ListNode* ReverseListMy(ListNode* pHead)
{
	ListNode* pNode = pHead;
	ListNode* pPre = NULL;

	ListNode* pReverseHead = NULL;

	while (pNode)
	{
		ListNode* pNext = pNode->m_pNext;

		if (!pNext)
		{
			pReverseHead = pNode;
		}
		
		pNode->m_pNext = pPre;

		pPre = pNode;
		pNode = pNext;
	}
	
	return pReverseHead;
}


void main()
{
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6);
	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node3.m_pNext = &node4;
	node4.m_pNext = &node5;
	node5.m_pNext = &node6;
	showAllNode(&node1);

	ListNode* pHead = ReverseList(&node1);
	showAllNode(pHead);
	
	ListNode* pMyhead = ReverseListMy(pHead);
	showAllNode(pMyhead);
}