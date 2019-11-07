#include <iostream>
using namespace std;

bool VerifySquenceOfBST(int sequence[], int nlength)
{
	if (!sequence || nlength <= 0)
	{
		return false;
	}

	int root = sequence[nlength - 1];
	
	// 搜索比根小的最后一个节点位置
	int i = 0;
	for (; i < nlength - 1; ++i)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}

	// 此刻i指向了，第一个比根大的节点，之后的节点都应该比根才行
	int j = i;
	for (; j < nlength - 1; ++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	// 执行到这里，说明可以分为左右子树了，那么，分别处理左右子树即可
	// 判断左边序列，是否成树
	bool bLeft = true;
	if (i > 0)
	{
		bLeft = VerifySquenceOfBST(sequence, i);
	}

	// 判断右边序列，是否成树
	bool bRight = true;
	if (i < nlength -1)
	{
		bRight = VerifySquenceOfBST(sequence + i, nlength - i - 1);
	}

	return bLeft && bRight;
}


void main()
{
	int array[] = { 5,7,6,9,11,10,8 };
	int nlength = sizeof(array) / sizeof(int);

	for (int i = 0; i < nlength; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;


	if (VerifySquenceOfBST(array, nlength))
	{
		cout << "是二叉搜索树的后序遍历序列" << endl;
	}
	else
	{
		cout << "不是二叉搜索树的后序遍历序列" << endl;
	}

}