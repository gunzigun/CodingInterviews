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

	// ͳ��������0�ĸ���
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == 0)
		{
			++numberOfZero;
		}
	}

	// ͳ�������еļ����
	int small = numberOfZero;  //С����ָ��0Ԫ�ص���һ�����±����0�ĸ�������Ϊ�Ѿ��������
	int big = small + 1;	   //������ָ��С��������һ��
	while (big < length)	
	{
		// ����������ȣ��ж��ӣ��򲻿�����˳��
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
		cout << "�������˳�ӣ�" << endl;
	}
	else
	{
		cout << "���������˳�ӣ�" << endl;
	}

}