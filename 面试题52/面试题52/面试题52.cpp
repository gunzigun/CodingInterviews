#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext = NULL;
	
	ListNode(int number)
	{
		m_nValue = number;
	}
};

unsigned int GetListLength(ListNode* pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while (pNode)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	// �õ���������ĳ���
	unsigned int nLenght1 = GetListLength(pHead1);
	unsigned int nLenght2 = GetListLength(pHead2);
	if (nLenght1 == 0 || nLenght2 == 0)
	{
		return NULL;
	}
	// �õ�ָ������ͷ��ָ�룬ָ�������ͷ��ָ��
	int nLengthDif = nLenght1 - nLenght2;
	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	if (nLenght2 > nLenght1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLenght2 - nLenght1;
	}

	// ������������nLengthDif��
	for (int i = 0; i < nLengthDif; ++i)
	{
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while (pListHeadLong && pListHeadShort && pListHeadLong != pListHeadShort)
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	// ֱ����һ����ͬ�Ľڵ㣬��ѭ���ͻ����������淵��
	ListNode* pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}

void main()
{
	ListNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5), Node6(6), Node7(7);
	
	Node1.m_pNext = &Node2;
	Node2.m_pNext = &Node3;
	Node3.m_pNext = &Node6;

	Node4.m_pNext = &Node5;
	Node5.m_pNext = &Node6;

	Node6.m_pNext = &Node7;

	ListNode* pHead1 = &Node1;
	ListNode* pHead2 = &Node4;

	cout << FindFirstCommonNode(pHead1, pHead2)->m_nValue << endl;
}