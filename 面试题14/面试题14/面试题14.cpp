#include <iostream>
using namespace std;

long long  maxProductAfterCutting_Dynamic(int nLength)
{
	if (nLength <= 3)
	{
		return nLength > 0 ? nLength - 1 : 0;
	}

	long long* products = new long long[nLength + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	long long max = 0;
	for (int i = 4; i <= nLength; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			long long nTemp = products[j] * products[i - j];
			if (nTemp > max)
			{
				max = nTemp;
			}
			products[i] = max;
		}
	}

	max = products[nLength];
	delete[] products;
	
	return max;
}

long long maxProductAfterCutting_Greedy(int nLength)
{
	if (nLength <= 3)
	{
		return nLength > 0 ? nLength - 1 : 0;
	}

	// 尽可能多的将绳子减成长度为3, 然后乘以剩余的2
	int timesOf3 = nLength / 3;

	// 如果全部取3，之后结余1，那么，这段应该改成2*2，方能更优
	if (nLength - timesOf3 * 3 == 1)
	{
		timesOf3 -= 1;
	}

	int timesOf2 = (nLength - timesOf3 * 3) / 2;

	return (long long)pow(3, timesOf3) * (long long)pow(2, timesOf2);
}

void main()
{
	int nLength = 100;

	cout << "动态规划算法得出的结果：" << maxProductAfterCutting_Dynamic(nLength) << endl;
	
	cout << "贪心算法得出的结果：" << maxProductAfterCutting_Greedy(nLength) << endl;


}