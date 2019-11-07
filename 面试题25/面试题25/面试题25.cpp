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
	while (pNode)
	{
		cout << pNode->m_nValue << " ";
		pNode = pNode->m_pNext;
	}
	cout << endl;
}


ListNode* MergeTwoSortList(ListNode* p1, ListNode* p2)
{
	if (!p1)
	{
		return p2;
	}

	if (!p2)
	{
		return p1;
	}

	ListNode* pNew = NULL;

	if (p1->m_nValue < p2->m_nValue)
	{
		pNew = p1;
		pNew->m_pNext = MergeTwoSortList(p1->m_pNext, p2);
	}
	else
	{
		pNew = p2;
		pNew->m_pNext = MergeTwoSortList(p1, p2->m_pNext);
	}

	return pNew;
}

void main()
{
	ListNode ListOneNode1(1), ListOneNode2(3), ListOneNode3(5), ListOneNode4(7);
	ListOneNode1.m_pNext = &ListOneNode2;
	ListOneNode2.m_pNext = &ListOneNode3;
	ListOneNode3.m_pNext = &ListOneNode4;
	cout << "输出链表L1：";
	showAllNode(&ListOneNode1);

	ListNode ListTwoNode1(2), ListTwoNode2(4), ListTwoNode3(6), ListTwoNode4(8);
	ListTwoNode1.m_pNext = &ListTwoNode2;
	ListTwoNode2.m_pNext = &ListTwoNode3;
	ListTwoNode3.m_pNext = &ListTwoNode4;
	cout << "输出链表L2：";
	showAllNode(&ListTwoNode1);

	ListNode* pNew = MergeTwoSortList(&ListOneNode1, &ListTwoNode1);
	cout << "输出合并之后的链表：";
	showAllNode(pNew);
}