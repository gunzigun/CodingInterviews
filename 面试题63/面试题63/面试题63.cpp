#include <iostream>
using namespace std;

int MaxDiff(const int* numbers, unsigned length)
{
	if (!numbers || length < 2)
	{
		return 0;
	}

	int minNum = numbers[0];
	int MaxProfit = 0;
	for (int i = 1; i < length; ++i)
	{
		if (numbers[i] < minNum)
		{
			minNum = numbers[i];
		}
		else
		{
			int diff = numbers[i] - minNum;
			if (diff > MaxProfit)
			{
				MaxProfit = diff;
			}
		}
	}

	return MaxProfit;
};


void main()
{
	int numbers[] = {6,5,4,3,2,1 };
	int length = sizeof(numbers) / sizeof(int);

	cout << MaxDiff(numbers, length) << endl;
}