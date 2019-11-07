#include <iostream>
using namespace std;


int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int mid = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + mid);
	int right = InversePairsCore(copy, data, start + mid + 1, end);

	// 左半段的最后元素
	int leftLast = start + mid;
	// 右半段的最后元素
	int rightLast = end;
	// 将数据依次放入copy数组中，使得copy从小到大排序
	int CopyIndex = end;
	// 用于统计逆序对个数
	int count = 0;
	while (leftLast >= start && rightLast >= start + mid + 1)
	{
		if (data[leftLast] > data[rightLast])
		{
			copy[CopyIndex--] = data[leftLast--];
			// [start+mid+1,righrLast]之间的数字个数 (rightLast - (start + mid + 1) + 1)
			int k = rightLast - start - mid;
			count += k;
		}
		else
		{
			copy[CopyIndex--] = data[rightLast--];
		}
	}

	for (; leftLast >= start; --leftLast)
	{
		copy[CopyIndex--] = data[leftLast];
	}

	for (; rightLast >= start + mid + 1; --rightLast)
	{
		copy[CopyIndex--] = data[rightLast];
	}

	return count + left + right;
}

int InversePairs(int* data, int length)
{
	if (!data || length <= 0)
	{
		return 0;
	}

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = data[i];
	}

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

void main()
{
	int array[] = { 7, 5, 6, 4 };
	int length = sizeof(array) / sizeof(int);
	cout << InversePairs(array, length) << endl;
}