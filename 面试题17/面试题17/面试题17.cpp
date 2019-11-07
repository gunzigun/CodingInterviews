#include <iostream>
using namespace std;

bool Increment(char* number)
{
	bool isOverFlow = false;
	int nLength = strlen(number);
	int nTakeOver = 0;		//表示进位
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			++nSum;
		}

		if (nSum == 10)
		{
			if (i == 0)
			{
				isOverFlow = true;
			}
			else
			{
				nSum = 0;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverFlow;
}

void PrintNumber(char* number)
{
	bool firstNotZero = false;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; ++i)
	{
		if (!firstNotZero && number[i] != '0')
		{
			firstNotZero = true;
		}

		if (firstNotZero)
		{
			cout << number[i];
		}
	}

	cout << "\t";
}

void PrintBigNumofDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	int nCount = 0;
	while (!Increment(number))
	{
		PrintNumber(number);
		nCount += 1;

		if (nCount != 0 && nCount % 10 == 0)
		{
			cout << endl;
		}
	}

	cout << endl;

	delete []number;
}

void main()
{
	PrintBigNumofDigits(5);
}