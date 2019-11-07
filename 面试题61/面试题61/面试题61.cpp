#include <stdlib.h>
#include <iostream>
using namespace std;

int compare(const void * a, const void* b)
{
	return *(int*)a - *(int*)b;
}

bool IsContinuous(int* numbers, int length)
{
	if (!numbers || length < 1)
	{
		return false;
	}

	qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	// 统计数组中0的个数
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == 0)
		{
			++numberOfZero;
		}
	}

	// 统计数组中的间隔数
	int small = numberOfZero;  //小索引指向0元素的下一个，下标就是0的个数，因为已经排序好了
	int big = small + 1;	   //大索引指向小索引的下一个
	while (big < length)	
	{
		// 两个数字相等，有对子，则不可能是顺子
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		++big;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}

void main()
{
	int numbers[] = { 0, 1, 3, 4, 5 };
	int length = sizeof(numbers) / sizeof(int);

	if (IsContinuous(numbers, length))
	{
		cout << "可以组成顺子！" << endl;
	}
	else
	{
		cout << "不可以组成顺子！" << endl;
	}

}