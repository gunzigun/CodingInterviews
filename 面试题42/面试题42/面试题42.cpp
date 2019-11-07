#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(int *pData, int nLength, bool& g_InvalidInput)
{
	if (!pData || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}

	int nCurSum = 0;
	int nGreatestSum = 0;
	for (int i = 0; i < nLength; ++i)
	{
		if (nCurSum <= 0) nCurSum = pData[i];
		else nCurSum += pData[i];

		if (nCurSum > nGreatestSum) nGreatestSum = nCurSum;
	}
	return nGreatestSum;
}

void main()
{
	int array[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	bool g_InvalidInput = false;
	int num = FindGreatestSumOfSubArray(array, sizeof(array) / sizeof(int), g_InvalidInput);

	if (!g_InvalidInput)
	{
		cout << "连续子数组的最大和为：" << num << endl;
	}
}