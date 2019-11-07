#include <iostream>
using namespace std;

int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start>end)
	{
		return -1;
	}

	int midIndex = (start + end) / 2;
	int midData = data[midIndex];

	if (midData < k)
	{
		start = midIndex + 1;
	}
	else if (midData > k)
	{
		end = midIndex - 1;
	}
	else
	{
		if (midIndex == 0)
		{
			return midIndex;
		}
		
		if (midIndex > 0 && data[midIndex-1] != k)
		{
			return midIndex;
		}
		
		end = midIndex - 1;
	}

	return GetFirstK(data, length, k, start, end);
}

int GetLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int midIndex = (start + end) / 2;
	int midData = data[midIndex];

	if (midData > k)
	{
		end = midIndex - 1;
	}
	else if (midData < k)
	{
		start = midIndex + 1;
	}
	else
	{
		if (midIndex == length - 1)
		{
			return midIndex;
		}

		if (midIndex < length - 1 && data[midIndex+1] != k)
		{
			return midIndex;
		}

		start = midIndex + 1;
	}

	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int* data, int length, int k)
{
	if (!data || length <= 0)
	{
		return 0;
	}

	int number = 0;
	int first = GetFirstK(data, length, k, 0, length - 1);
	int last = GetLastK(data, length, k, 0, length - 1);
	if (first > -1 && last > -1)
	{
		number = last - first + 1;
	}

	return number;
}

int GetMissingNumber(const int* numbers, int length)
{
	if (!numbers || length <= 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (numbers[mid] != mid)
		{
			if (mid == 0 || numbers[mid-1] == mid - 1)
			{
				return mid;
			}
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
 	}

	if (left == length)
	{
		return length;
	}

	return -1;
}

int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (!numbers || length<=0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (numbers[mid] == mid)
		{
			return mid;
		}
		else if (numbers[mid] > mid)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}

void main()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };
	int length = sizeof(data) / sizeof(int);
	int k = 1;
	cout << "问题一：" << GetNumberOfK(data,length,k) << endl;

	int data2[] = { 0, 1, 2, 4, 5, 6 };
	length = sizeof(data2) / sizeof(int);
	cout << "问题二：" << GetMissingNumber(data2, length) << endl;

	int data3[] = { -3, -1, 1, 3, 5 };
	length = sizeof(data3) / sizeof(int);
	cout << "问题三：" << GetNumberSameAsIndex(data3, length) << endl;
}