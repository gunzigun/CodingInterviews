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


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (!pListHead)
	{
		cout << "����Ϊ�գ�" << endl;
		return NULL;
	}

	if (!pListHead || k == 0)
	{
		cout << "�޷���ȡ������ k( = " << k << " ) ��Ԫ��" << endl;
		return NULL;
	}
	
	ListNode* pAhead = pListHead;
	ListNode* pBehind = pListHead;

	unsigned int nCount = 1;
	for (unsigned int i = 1; i < k; ++i)
	{
		if (pAhead->m_pNext)
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			cout << "��Ҫ�ҵ������� " << k << " ��Ԫ�أ�����ֻ�� " << nCount << " ��Ԫ��" << endl;
			return NULL;
		}
		++nCount;
	}

	while (pAhead->m_pNext)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	
	return pBehind;
}

void main()
{
	ListNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6);
	node1.m_pNext = &node2;
	node2.m_pNext = &node3;
	node3.m_pNext = &node4;
	node4.m_pNext = &node5;
	node5.m_pNext = &node6;

	ListNode* pTemp = &node1;
	cout << "����ĸ���Ԫ��: ";
	while (pTemp != NULL)
	{
		cout << pTemp->m_nValue << " ";
		pTemp = pTemp->m_pNext;
	}
	cout << endl;

	int k = 2;
	pTemp = FindKthToTail(&node1, k);
	if (pTemp)
	{
		cout << "����ĵ����� " << k << " ��Ԫ��Ϊ�� " << pTemp->m_nValue << endl;
	}
}