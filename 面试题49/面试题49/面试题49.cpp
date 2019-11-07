#include <iostream>
#include <time.h>
using namespace std;

bool IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
	while (number % 3 == 0)
	{
		number /= 3;
	}
	while (number % 5 == 0)
	{
		number /= 5;
	}

	return (number == 1) ? true : false;
}

int GetIndexUglyNum(int nIndex)
{
	if (nIndex <= 0)
	{
		return 0;
	}

	int number = 0;
	int UglyCount = 0;
	while (UglyCount < nIndex)
	{
		++number;
		
		if (IsUgly(number))
		{
			UglyCount++;
		}
	}
	return number;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;

	return min;
}

int GetIndexUglyNum_Better(int nIndex)
{
	if (nIndex <= 0)
	{
		return 0;
	}

	int *pUglyNumbers = new int[nIndex];
	pUglyNumbers[0] = 1;
	int nextIndex = 1;

	int nMaxNum = 1;
	while (nextIndex < nIndex)
	{
		int M2 = 0;
		int M3 = 0;
		int M5 = 0;
		for (int i = 0; i < nextIndex && M2 <= nMaxNum; ++i)
		{
			M2 = 2 * pUglyNumbers[i];
		}

		for (int i = 0; i < nextIndex && M3 <= nMaxNum; ++i)
		{
			M3 = 3 * pUglyNumbers[i];
		}

		for (int i = 0; i < nextIndex && M5 <= nMaxNum; ++i)
		{
			M5 = 5 * pUglyNumbers[i];
		}

		int min = Min(M2, M3, M5);
		pUglyNumbers[nextIndex] = min;
		nMaxNum = min;

		++nextIndex;
	}

	int ugly = pUglyNumbers[nIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

void main()
{
	int nIndex = 1500;
	
	clock_t start, finish;
	double totaltime;

	cout << "-------------------------------常规解法-----------------------------" << endl;
	start = clock();
	cout << "第 " << nIndex << " 个丑数是：" << GetIndexUglyNum(nIndex) << endl;
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;

	cout << "-------------------------------高效解法-----------------------------" << endl;
	start = clock();
	cout << "第 " << nIndex << " 个丑数是：" << GetIndexUglyNum_Better(nIndex) << endl;
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;
}