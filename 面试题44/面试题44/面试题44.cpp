#include <iostream>
using namespace std;


void NumofIndex(int Index)
{	
	if (Index <= 0)
	{
		return;
	}

	char chFind = '0';
	if (Index == 1)
	{
		cout << Index << "th char is " << chFind << endl;
	}

	Index--;	//去掉0便于计算

	int numOfBit = 0;
	// 确定前面有多少位
	int numOfBitBefore = 0;
	// 确定是几位数
	int i = 1;
	for (;;++i)
	{
		numOfBitBefore = numOfBit;
		numOfBit += 9 * i * (int)pow(10.0, i - 1);
		if (Index <= numOfBit)
		{
			break;
		}
	}
	
	// 计算这个i位数，是i位数的第几个，保存在nDiv中
	int nDiv = (Index - numOfBitBefore) / i;
	int nLeft = (Index - numOfBitBefore) % i;
	if (nLeft != 0)
	{
		nDiv++;
	}
	// 计算出第Index位，所在的数字，保存在nNumReal中
	int nFirst = (int)pow(10.0, i - 1);
	int nNumReal = nFirst + nDiv - 1;

	// 计算出第Index位，是数字（i位数）的第几位，保存在wei中
	int wei = (nLeft == 0 ? i : nLeft);
	
	char a[50];
	sprintf_s(a, "%d", nNumReal);
	cout << Index+1 << "th char is " << a[wei-1] << endl;
}


void main()
{
	NumofIndex(12);
}