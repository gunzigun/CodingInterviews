#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	double m_dValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	
	BinaryTreeNode(double dNum)
	{
		m_dValue = dNum;
		m_pLeft = NULL;
		m_pRight = NULL;
	}
};

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	return false;
}

bool MainHasSub(BinaryTreeNode* Main, BinaryTreeNode* Sub)
{
	if (!Sub)
	{
		return true;
	}

	if (!Main)
	{
		return false;
	}

	if (!Equal(Main->m_dValue, Sub->m_dValue))
	{
		return false;
	}

	return MainHasSub(Main->m_pLeft, Sub->m_pLeft) && MainHasSub(Main->m_pRight, Sub->m_pRight);
}

bool hasSubTree(BinaryTreeNode* Main, BinaryTreeNode* Sub)
{
	bool result = false;

	if (Main && Sub)
	{
		if (Equal(Main->m_dValue, Sub->m_dValue))
		{
			result = MainHasSub(Main, Sub);
		}
		if (!result)
		{
			result = hasSubTree(Main->m_pLeft, Sub);
		}
		if (!result)
		{
			result = hasSubTree(Main->m_pRight, Sub);
		}
	}
	return result;
}

void main()
{
	BinaryTreeNode MainTreeNode1(8), MainTreeNode2(8), MainTreeNode3(7), MainTreeNode4(9), MainTreeNode5(2), MainTreeNode6(4), MainTreeNode7(7);
	MainTreeNode1.m_pLeft = &MainTreeNode2;
	MainTreeNode1.m_pRight = &MainTreeNode3;
	MainTreeNode2.m_pLeft = &MainTreeNode4;
	MainTreeNode2.m_pRight = &MainTreeNode5;
	MainTreeNode5.m_pLeft = &MainTreeNode6;
	MainTreeNode5.m_pRight = &MainTreeNode7;

	BinaryTreeNode SubTreeNode1(8), SubTreeNode2(9), SubTreeNode3(2);
	SubTreeNode1.m_pLeft = &SubTreeNode2;
	SubTreeNode1.m_pRight = &SubTreeNode3;

	if (hasSubTree(&MainTreeNode1, &SubTreeNode1))
	{
		cout << "сп" << endl;
	}
	else
	{
		cout << "ц╩сп" << endl;
	}
}