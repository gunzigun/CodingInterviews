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


ListNode* MeetingNode(ListNode* pHead)
{
	if (!pHead)
	{
		return NULL;
	}

	ListNode* pSlow = pHead;
	ListNode* pFast = pSlow->m_pNext;

	while (pSlow && pFast && pSlow->m_pNext && pFast->m_pNext)
	{
		if (pFast == pSlow)
		{
			return pFast;
		}

		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext->m_pNext;
	}

	return NULL;
}


ListNode* EntryNodeOfLoop(ListNode* pHead, int& nNumOfLoop)
{
	ListNode* pNode = MeetingNode(pHead);
	if (!pNode)
	{
		return NULL;
	}

	ListNode* pCount = pNode;
	while (pCount && pCount->m_pNext != pNode)
	{
		pCount = pCount->m_pNext;
		++nNumOfLoop;
	}

	ListNode* p1 = pHead;
	ListNode* p2 = pHead;
	for (int i = 1; i <= nNumOfLoop; ++i)
	{
		if (p1)
		{
			p1 = p1->m_pNext;
		} 
		else
		{
			return NULL;
		}
	}

	while (p1 && p2 && p1 != p2)
	{
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}

	return p1;
}


void main()
{
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6);
	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node3.m_pNext = &node4;
	node4.m_pNext = &node5;
	node5.m_pNext = &node6;
	node6.m_pNext = &node1;

	int nCount = 1;
	ListNode* pNode = EntryNodeOfLoop(&node1, nCount);
	if (pNode)
	{
		cout << "链表中存在环，环中有 " << nCount << " 个节点！" << endl;
		cout << "环中开始节点的值为：" << pNode->m_nValue << endl;
	}
	else
	{
		cout << "链表中不存在环!" << endl;
	}
}