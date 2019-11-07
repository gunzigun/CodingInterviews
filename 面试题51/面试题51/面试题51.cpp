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

	// ���ε����Ԫ��
	int leftLast = start + mid;
	// �Ұ�ε����Ԫ��
	int rightLast = end;
	// ���������η���copy�����У�ʹ��copy��С��������
	int CopyIndex = end;
	// ����ͳ������Ը���
	int count = 0;
	while (leftLast >= start && rightLast >= start + mid + 1)
	{
		if (data[leftLast] > data[rightLast])
		{
			copy[CopyIndex--] = data[leftLast--];
			// [start+mid+1,righrLast]֮������ָ��� (rightLast - (start + mid + 1) + 1)
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