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

	// ������ֺϷ���
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
		cout << "���ڳ��ִ����������鳤��һ������֣�������Ϊ��" << nResult << endl;
	}
	else
	{
		cout << "�����ڳ��ִ����������鳤��һ�������" << endl;
	}
}
