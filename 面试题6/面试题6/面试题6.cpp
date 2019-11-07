#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value)
{
	if (pHead == NULL)
	{
		return;
	}

	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
	{
		*pHead = pNew;
	}

	ListNode* pNode = *pHead;
	while (pNode->m_pNext != NULL)
	{
		pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pNew;
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL) 
	{
		return;
	}

	if (*pHead == NULL)
	{
		return;
	}

	ListNode* pDel = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pDel = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pDel = pNode->m_pNext;
			pNode->m_pNext = pDel->m_pNext;
		}
	}
	if (pDel != NULL)
	{
		delete pDel;
		pDel = NULL;
	}
}

void PrintList(ListNode** pHead)
{
	if (pHead == NULL)
	{
		cout << "��ͷָ��Ϊ��" << endl;
		return;
	}

	if (*pHead == NULL)
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	ListNode* pNode = *pHead;
	int num = 1;
	while (pNode != NULL)
	{
		cout << "��" << num << "������Ԫ��Ϊ��" << pNode->m_nValue << endl;
		pNode = pNode->m_pNext;
		++num;
	}
}

void ReversPrintList(ListNode** pHead)
{
	if (pHead == NULL)
	{
		cout << "��ͷָ��Ϊ��" << endl;
		return;
	}

	if (*pHead == NULL)
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	stack<ListNode*> nodes;

	ListNode* pNode = *pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	int num = 1;
	while (!nodes.empty())
	{
		cout << "��������" << num << "������Ԫ��Ϊ��" << nodes.top()->m_nValue << endl;
		++num;
		nodes.pop();
	}
}


void ReversPrintList_DiGui(ListNode* pHead)
{
	if (pHead != NULL)
	{
		ReversPrintList_DiGui(pHead->m_pNext);
		cout << "�������Ԫ�أ�" << pHead->m_nValue << endl;
	}
}



void main()
{
	ListNode* pNode = new ListNode();
	pNode->m_pNext = NULL;
	pNode->m_nValue = 0;

	ListNode** pHead = &pNode;
	AddToTail(pHead, 100);
	AddToTail(pHead, 200);

	//PrintList(pHead);

	//ReversPrintList(pHead);

	ReversPrintList_DiGui(*pHead);
}