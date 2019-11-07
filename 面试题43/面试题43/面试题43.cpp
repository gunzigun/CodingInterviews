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
			return 1;   // 1-firstcharnNum ,�϶�ֻ��һ��1
		}
	}
	
	// һ�ĸ�����Ϊ����3�����֣���21345Ϊ����
	// ��1��������λ�ĸ�����1346-21345��10000-19999������1����λΪ1����ʣ�¸�λת�����ټ�1����2����λ>1����10^(ʣ��λ��)
	// ��1�����ڳ���λ�ĵĸ�����1346-21346��0'1346-0'9999��1'0000-1'9999��2'0000-2'1345��:
	// ��һ�¾��ǣ�1346-9999��0000-9999��0000-1345���ټ򻯾��ǣ�2����0000-9999��0000-9999�У���֪��λ�� * 10^(λ��-1)
	// ��1-1345�ĸ������ݹ���ü��ɻ��
	
	// ��
	int numFirstDigit = 0;
	if (firstcharNum > 1)
	{
		numFirstDigit = (int)pow(10.0, length - 1);
	}
	else if (firstcharNum == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}
	
	// ��
	int numOtherDigit = firstcharNum * (length - 1) * (int)pow(10.0, length - 2);

	// ��
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
	
	cout << "-----------------------------��Ч�ⷨ��ʼ---------------------------" << endl;
	cout << "��Ч�ⷨ����⣺" << NumberOf1Between1AndN(num) << endl;

	cout << "-----------------------------����ⷨ��ʼ---------------------------" << endl;
	cout << "����ⷨ����⣺" << NormalNumof1(num) << endl;
	
}