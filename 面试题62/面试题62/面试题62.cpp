#include <list>
#include <iostream>
using namespace std;

int LastRemainingOne(unsigned int n, unsigned int m)
{
	if (n <= 1 || m <= 1)
	{
		return -1;
	}

	// ��0��n-1��һ��n���������뵽������
	unsigned int i = 0;
	list<int> numbers;
	for (i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}

	
	list<int>::iterator current = numbers.begin();
	// ����ɾ����m��Ԫ�أ�֪������ֻʣһ��Ԫ��Ϊֹ
	while (numbers.size() > 1)
	{
		// ��һ��Ԫ�أ���������ӣ�����m-1�κ󣬾����ҵ���m��Ԫ��
		for (int i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}

		// ��ʱcurrentָ���˵�m��Ԫ�أ�nextΪ��һ��
		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}
		// ��nextʱ����ˣ�����currentҪ��һ��
		--current;

		// �Ƴ���m��Ԫ��
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

	cout << "�ⷨ1��" << LastRemainingOne(n, m) << endl;
	cout << "�ⷨ2��" << LastRemainingTwo(n, m) << endl;
}