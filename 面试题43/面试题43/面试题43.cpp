#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int NumberOf1(char* strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
	{
		return 0;
	}

	int firstcharNum = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1)
	{
		if (firstcharNum == 0)
		{
			return 0;
		}

		if (firstcharNum > 0)
		{
			return 1;   // 1-firstcharnNum ,肯定只有一个1
		}
	}
	
	// 一的个数分为以下3个部分，以21345为例子
	// ①1出现在首位的个数（1346-21345，10000-19999）：（1）首位为1，则剩下各位转整，再加1；（2）首位>1，则10^(剩下位数)
	// ②1出现在除首位的的个数（1346-21346，0'1346-0'9999，1'0000-1'9999，2'0000-2'1345）:
	// 简化一下就是：1346-9999，0000-9999，0000-1345；再简化就是：2倍的0000-9999；0000-9999中，易知：位数 * 10^(位数-1)
	// ③1-1345的个数：递归调用即可获得
	
	// ①
	int numFirstDigit = 0;
	if (firstcharNum > 1)
	{
		numFirstDigit = (int)pow(10.0, length - 1);
	}
	else if (firstcharNum == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}
	
	// ②
	int numOtherDigit = firstcharNum * (length - 1) * (int)pow(10.0, length - 2);

	// ③
	int numRecursive = NumberOf1(strN+1);

	return numFirstDigit + numOtherDigit + numRecursive;
}

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	char strN[50];
	sprintf_s(strN, "%d", n);
	
	return NumberOf1(strN);
}


int NormalNumof1(int n)
{
	int num = 0;
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		int numcopy = i;
		while (numcopy)
		{
			if (numcopy % 10 == 1)
			{
				temp++;
			}
			numcopy = numcopy / 10;
		}
		num += temp;
	}

	return num;
}

void main()
{
	int num = 201202023;
	
	cout << "-----------------------------高效解法开始---------------------------" << endl;
	cout << "高效解法的求解：" << NumberOf1Between1AndN(num) << endl;

	cout << "-----------------------------常规解法开始---------------------------" << endl;
	cout << "常规解法的求解：" << NormalNumof1(num) << endl;
	
}