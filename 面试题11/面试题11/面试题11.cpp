#include <iostream>
using namespace std;

void Swap(int* start, int* end)
{
	int temp = *start;
	*start = *end;
	*end = temp;
}

void QuickSort(int* array, int nlength, int start, int end)
{
	if (array == NULL || nlength <= 0 || start < 0 || end >= start + nlength || start > end)
	{
		cout << "传入参数错误！" << nlength << " " << start << " " << end << endl;
		return;
	}
	
	int* pChangelow = array + start;
	int* pChangehigh = array + end;
	int* pMidNum = pChangelow;
	bool bChangeFlag = true;
	while (pChangelow < pChangehigh)
	{
		if (bChangeFlag)
		{
			if (*pMidNum < *pChangehigh)
			{
				pChangehigh -= 1;
			}
			else
			{
				Swap(pMidNum, pChangehigh);
				pMidNum = pChangehigh;
				pChangelow += 1;
				bChangeFlag = false;
			}
		}
		else
		{
			if (*pMidNum > *pChangelow)
			{
				pChangelow += 1;
			}
			else
			{
				Swap(pMidNum, pChangelow);
				pMidNum = pChangelow;
				pChangehigh -= 1;
				bChangeFlag = true;
			}
		}
	}

	int LeftLength = pMidNum - array - start;
	if (LeftLength > 0)
	{
		int LeftStart = start;
		int LeftEnd = LeftStart + LeftLength - 1;
		QuickSort(array, LeftLength, LeftStart, LeftEnd);
	}

	int RightLength = array + end - pMidNum;
	if (RightLength > 0)
	{
		int RightEnd = end;
		int RightStart = RightEnd - RightLength + 1;
		QuickSort(array, RightLength, RightStart, RightEnd);
	}
}

void ShowArray(int* array, int nlength)
{
	for (int i = 0; i < nlength; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void SortAges(int* ages, int nLength)
{
	if (ages == NULL || nLength <= 0)
	{
		return;
	}

	const int oldestAge = 99;
	int timesofAge[oldestAge + 1];
	memset(timesofAge, 0, sizeof(timesofAge));

	for (int i = 0; i < nLength; ++i)
	{
		int nAge = ages[i];
		if (nAge < 0 || nAge > oldestAge)
		{

			cout << "错误的年龄" << nAge << ",需要在" << 0 << "-" << oldestAge << "范围之内！" << endl;
			continue;
		}
		++timesofAge[nAge];
	}

	int index = 0;
	for (int i = 0; i <= oldestAge; ++i)
	{
		for (int j = 0; j < timesofAge[i]; ++j,++index)
		{
			ages[index] = i;
		}
	}
}

int Min(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		throw new exception("无效参数！");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2-index1 == 1)
		{
			return numbers[index2];
		}
		indexMid = (index1 + index2) / 2;

		
		//特殊情况只能顺序查找了(101111)
		if (numbers[indexMid] == numbers[index1] && numbers[indexMid] == numbers[index2])
		{
			int minNum = numbers[index1];
			for (int i = index1 + 1; i <= index2; ++i)
			{
				if (minNum > numbers[i])
				{
					minNum = numbers[i];
				}
			}
			return minNum;
		}

		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}


void main()
{
	int array[] = { 50, 111, 30, 3, 2, 12, 45, 8 };
	int nlength = sizeof(array) / sizeof(int);

	ShowArray(array, nlength);
	QuickSort(array, nlength, 0, nlength - 1);
	ShowArray(array, nlength);

	int ages[] = { 20, 30, 25, 22, 25, 27, 50, 20, 30, 50 };
	int nAgelen = sizeof(ages) / sizeof(int);
	ShowArray(ages, nAgelen);
	SortAges(ages, nAgelen);
	ShowArray(ages, nAgelen);

	int numbers[] = {3,4,5,22,1,2};
	int numLen = sizeof(numbers) / sizeof(int);
	int minNum = Min(numbers, numLen);
	cout << minNum;
}