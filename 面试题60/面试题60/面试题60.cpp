#include <iostream>
using namespace std;

int g_maxValue = 6;

void Probability(int number, int* pProbability);

void PrintProbability(int number)
{
	if (number < 1)
	{
		return;
	}

	int maxSum = g_maxValue * number;
	int minSum = number;
	int nSumKind = maxSum - minSum + 1;
	int *pProbability = new int[nSumKind];
	for (int i = 0; i < nSumKind; ++i)
	{
		pProbability[i] = 0;
	}

	Probability(number, pProbability);
	
	int nKind = pow((double)g_maxValue, number);
	int nlineNum = 0;
	double sum = 0;
	for (int i = 0; i < nSumKind; ++i)
	{
		double ratio = (double)pProbability[i] / nKind;
		cout << "P(" << number + i << "): " << ratio << " \t";
		sum += ratio;
		nlineNum++;

		if (nlineNum % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << "总概率：" << sum << endl;
}

void Probability(int original, int current, int sum, int* pProbability);

void Probability(int number, int* pProbability)
{
	for (int i = 1; i <= g_maxValue; ++i)
	{
		Probability(number, number, i, pProbability);
	}
}


void Probability(int original, int current, int sum, int* pProbability)
{
	if (current == 1)
	{
		pProbability[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbability);
		}
	}
}

void PrintProbabilityGood(int number)
{
	if (number < 1)
	{
		return;
	}

	int* pProbability[2];
	pProbability[0] = new int[g_maxValue*number + 1];
	pProbability[1] = new int[g_maxValue*number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i)
	{
		pProbability[0][i] = 0;
		pProbability[1][i] = 0;
	}

	int flag = 0;
	// 先把一个骰子的结果加入数组
	for (int i = 1; i <= g_maxValue; ++i)
	{
		pProbability[flag][i] = 1;
	}
	
	// k 表示骰子个数，从第二个开始加
	for (int k = 2; k <= number; ++k)
	{
		// 先把另一个数组清空
		for (int i = 0; i < k; ++i)
		{
			pProbability[1 - flag][i] = 0;
		}

		// 往另一个数组加入结果
		for (int i = k; i <= g_maxValue * k; ++i)
		{
			pProbability[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
			{
				pProbability[1 - flag][i] += pProbability[flag][i - j];
			}
		}

		flag = 1 - flag;
	}

	int nKind = pow((double)g_maxValue, number);
	int nlineNum = 0;
	double sum = 0;
	for (int i = number; i <= g_maxValue*number; ++i)
	{
		double ratio = (double)pProbability[flag][i] / nKind;
		cout << "P(" << i << "): " << ratio << " \t";
		sum += ratio;
		nlineNum++;

		if (nlineNum % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	cout << "总概率：" << sum << endl;

	delete[] pProbability[0];
	delete[] pProbability[1];

}

void main()
{
	int n = 20;
	cout << "一共有 " << n << "个骰子" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	PrintProbability(n);
	cout << "-------------------------------------------------------------------" << endl;
	PrintProbabilityGood(n);
}