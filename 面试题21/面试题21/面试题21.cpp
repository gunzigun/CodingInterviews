#include <iostream>
using namespace std;

void showAllNumbers(int* pArray, int nLength)
{
	for (int i = 0; i < nLength; ++i)
	{
		cout << pArray[i] << " ";
	}
	cout << endl;
}

void ReorderOddEven(int* pArray, int nLength)
{
	if (pArray == NULL || nLength == 0)
	{
		cout << "输入数组为空，操作失败" << endl;
		return;
	}

	int* pBegin = pArray;
	int* pEnd = pArray + nLength - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			pBegin++;
		}

		while (pBegin < pEnd && (*pEnd & 0x1) == 0)
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

bool isEven(int n)
{
	return (n & 0x1) == 0;
}

void Reorder(int* pArray, int nLength, bool (*func)(int))
{
	if (pArray == NULL || nLength == 0)
	{
		cout << "输入数组为空，操作失败" << endl;
		return;
	}

	int* pBegin = pArray;
	int* pEnd = pArray + nLength - 1;

	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
		{
			pBegin++;
		}

		while (pBegin < pEnd && func(*pEnd))
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void ReorderOddEvenOther(int* pArray, int nLength)
{
	Reorder(pArray, nLength, isEven);
}

void sort(void(*func)(int))
{
	for (int i = 0; i <= 10; ++i)
	{
		func(i);
	}
}

void bubbleSort(int n)
{
	cout << n << endl;
}

void main()
{ 	
	int intArray[] = { 2 };
	int nLength = sizeof(intArray) / sizeof(int);
	
	showAllNumbers(intArray, nLength);

	//ReorderOddEven(intArray, nLength);
	ReorderOddEvenOther(intArray, nLength);

	showAllNumbers(intArray, nLength);

	//sort(bubbleSort);
}