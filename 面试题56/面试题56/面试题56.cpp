#include <iostream>
using namespace std;


// ��һ����num�ĵ�indexBitλ�Ƿ�Ϊ1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

// �ҵ�һ������һ��Ϊ1��λ
unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

void FindNumsAppearsOnce(int data[], int length, int* num1, int* num2)
{
	if (!data || length < 2)
	{
		return;
	}

	int resultXOR = 0;
	for (int i = 0; i < length; ++i)
	{
		resultXOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultXOR);

	*num1 = *num2 = 0;
	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
		{
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}
}

int FindNumberAppearingOnce(int numbers[], int length)
{
	if (!numbers || length < 0)
	{
		throw new exception("Invalid input.");
	}

	int bitSum[32] = {0};
	for (int i = 0; i < length; ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = numbers[i] & bitMask;
			if (bit != 0)
			{
				bitSum[j] += 1;
			}
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}

void main()
{
	int num1, num2;
	int array[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int length = sizeof(array) / sizeof(int);

	cout << "������飺" << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	FindNumsAppearsOnce(array, length, &num1, &num2);

	cout << "��һ����:" << num1 << endl;
	cout << "�ڶ�����:" << num2 << endl;

	cout << "---------------------------------------------------------" << endl;

	int data[] = { 1, 2, 3, 2, 3, 2, 5, 3, 5, 5, 1, 1, 11};
	length = sizeof(data) / sizeof(int);
	cout << "������飺" << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	cout << "ֻ����һ�ε�����" << FindNumberAppearingOnce(data, length) << endl;
}