#include <iostream>
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (!data || length < 1 || !num1 || !num2)
	{
		return found;
	}

	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		long long AddSum = data[left] + data[right];

		if (AddSum == sum)
		{
			*num1 = data[left];
			*num2 = data[right];
			found = true;
			break;
		}
		else if (AddSum > sum)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	return found;
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
	{
		return;
	}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;
			
			if (curSum == sum)
			{
				PrintContinuousSequence(small, big);
			}
		}

		big++;
		curSum += big;
	}
}

void main()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	int length = sizeof(data) / sizeof(int);
	int sum = 15;
	int num1(0), num2(0);
	if (FindNumbersWithSum(data, length, sum, &num1, &num2))
	{
		cout << "题目一：" << num1 << " " << num2 << endl;
	}

	cout << "--------------------------------------------------------" << endl;
	// 题目二
	FindContinuousSequence(15);
}