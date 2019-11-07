#include <list>
#include <iostream>
using namespace std;

int LastRemainingOne(unsigned int n, unsigned int m)
{
	if (n <= 1 || m <= 1)
	{
		return -1;
	}

	// 把0到n-1，一共n个数，加入到链表中
	unsigned int i = 0;
	list<int> numbers;
	for (i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}

	
	list<int>::iterator current = numbers.begin();
	// 不断删除第m个元素，知道链表只剩一个元素为止
	while (numbers.size() > 1)
	{
		// 第一个元素，不断往后加，加了m-1次后，就能找到第m个元素
		for (int i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}

		// 此时current指向了第m个元素，next为下一个
		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}
		// 找next时向后了，所以current要减一次
		--current;

		// 移除第m个元素
		numbers.erase(current);
		current = next;
	}

	return *current;
}

int LastRemainingTwo(unsigned int n, unsigned int m)
{
	if (n <= 1 || m <= 1)
	{
		return -1;
	}
	int last = 0;
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}

	return last;
}

void main()
{
	unsigned int n = 5;
	unsigned int m = 3;

	cout << "解法1：" << LastRemainingOne(n, m) << endl;
	cout << "解法2：" << LastRemainingTwo(n, m) << endl;
}