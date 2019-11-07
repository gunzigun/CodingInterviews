#include <iostream>
using namespace std;

bool MoreThanHalfNum(int* numbers, int nLength, int& result)
{
	if (!numbers || nLength <= 0)
	{
		return false;
	}

	result = numbers[0];
	int times = 1;
	for (int i = 0; i < nLength; ++i)
	{
		if (times==0)
		{
			result = numbers[i];
			times = 1;
		}
		else
		{
			if (numbers[i]==result)
			{
				times++;
			}
			else
			{
				times--;
			}
		}
	}

	// 检测数字合法性
	int nCount = 0;
	for (int j = 0; j < nLength; ++j)
	{
		if (numbers[j]==result)
		{
			nCount++;
		}
	}

	if (nCount*2 <= nLength)
	{
		return false;
	}

	return true;
}

void main()
{
	int numbers[] = { 1, 2, 3, 2, 3, 2, 3, 3, 3 };
	int nLength = sizeof(numbers) / sizeof(int);
	int nResult;
	
	if (MoreThanHalfNum(numbers, nLength, nResult))
	{
		cout << "存在出现次数超过数组长度一半的数字，该数字为：" << nResult << endl;
	}
	else
	{
		cout << "不存在出现次数超过数组长度一半的数字" << endl;
	}
}
