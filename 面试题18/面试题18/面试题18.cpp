#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext = NULL;
};

void PrintList(ListNode** pListHead)
{
	ListNode* pOut = *pListHead;
	while (pOut != NULL)
	{
		cout << pOut->m_nValue << '\t';
		pOut = pOut->m_pNext;
	}
	cout << endl;
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return;
	}

	if (pToBeDeleted->m_pNext != NULL)
	{
		int nValue = pToBeDeleted->m_pNext->m_nValue;
		pToBeDeleted->m_nValue = nValue;
		pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
	} 
	else if (*pListHead == pToBeDeleted)
	{
		*pListHead = NULL;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
	}
}

void DeleteDuplication(ListNode** pHead)
{
	if (!pHead || !*pHead)
	{
		return;
	}

	ListNode* pPreNode = NULL;
	ListNode* pNode = *pHead;
	while (pNode != NULL)
	{
		if (pNode->m_pNext == NULL || pNode->m_pNext->m_nValue != pNode->m_nValue)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			ListNode* pNotSame = pNode;
			int a = pNode->m_nValue;
			while (pNotSame && pNotSame->m_nValue == a)
			{
				pNotSame = pNotSame->m_pNext;
			}

			if (!pPreNode)
			{
				*pHead = pNotSame;
			}
			else
			{
				pPreNode->m_pNext = pNotSame;
			}

			pNode = pNotSame;
		}
	}

}

void main()
{
	ListNode* a = new ListNode();
	ListNode b,c,d,e,f,g;

	a->m_nValue = 1;
	b.m_nValue = 2;
	c.m_nValue = 3;
	d.m_nValue = 3;
	e.m_nValue = 4;
	f.m_nValue = 4;
	g.m_nValue = 5;

	ListNode* temp = a;
	//*
	a->m_pNext = &b;
	b.m_pNext = &c;
	c.m_pNext = &d;
	d.m_pNext = &e;
	e.m_pNext = &f;
	f.m_pNext = &g;
	//*/
	ListNode** pHead = &temp;
	
	PrintList(pHead);
	
	//DeleteNode(pHead, &f);
	DeleteDuplication(pHead);
	
	PrintList(pHead);

	delete a;
}