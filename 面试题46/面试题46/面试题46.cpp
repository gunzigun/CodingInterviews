#include <iostream>
#include <string>
using namespace std;

int GetTranslationCount(const string& number)
{
	int length = number.length();
	int *counts = new int[length];

	for (int i = length - 1; i >= 0; --i)
	{
		int kind = 1;
		if (i < length - 1)
		{
			// [i][i+1��length-1]
			kind = counts[i + 1];

			// [i,i+1][i+2��length-1]
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			// [i,i+1]����ƴ�����Ǹ���λ������
			if (converted >= 10 && converted <= 25)
			{
				// �����Ļ���[i,i+1]���ж���һ����
				if (i < length - 2)
				{
					kind += counts[i + 2];
				}
				else
				{
					kind += 1;
				}
			}
		}
		counts[i] = kind;
	}

	int returnNum = counts[0];
	delete[] counts;

	return returnNum;
}

int GetTranslationCount(int number)
{
	if (number < 0)
	{
		return 0;
	}
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);
}


void main()
{
	int num = 12258;
	cout << "��������Ϊ�� " << num << endl;
	cout << "�䷭�뷽ʽ�� " << GetTranslationCount(num) << " ��" << endl;
}