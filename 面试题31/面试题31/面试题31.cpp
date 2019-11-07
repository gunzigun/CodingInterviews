#include <iostream>
#include <stack>
using namespace std;

bool IsPopOrder(const int* pPush,const int* pPop, int nLength)
{
	bool bPossible = false;

	if (pPush && pPop && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		stack<int> stackData;

		while (pNextPop-pPop < nLength)
		{
			int value = *pNextPop;
			while (stackData.empty() || stackData.top() != value)
			{
				if (pNextPush-pPush == nLength)
				{
					break;
				}

				stackData.push(*pNextPush);
				pNextPush++;
			}

			if (stackData.top() != value)
			{
				break;
			}

			stackData.pop();
			pNextPop++;
		}

		if (stackData.empty() && pNextPop-pPop==nLength)
		{
			bPossible = true;
		}	
	}
	return bPossible;
}

void main()
{
	const int nLength = 5;
	int PushArray[nLength] = { 1, 2, 3, 4, 5 };
	int PopArray[nLength] = { 4, 3, 5, 1, 2 };
	
	const int *pPush = PushArray;
	const int *pPop = PopArray;

	if (IsPopOrder(pPush, pPop, nLength))
	{
		cout << "是一个出栈序列！";
	}
	else
	{
		cout << "不是一个出栈序列！";
	}
}