#include <iostream>
using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
	if (!pBegin || !pEnd)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (!pData)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0')
	{
		pEnd++;
	}
	pEnd--;		//��Ϊ��ʱ��pEndָ�����ַ����Ľ���������Ҫ��һλ

	// ��ת��������
	Reverse(pBegin, pEnd);

	// ��תÿ������
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

char* LeftRotateString(char* pStr, int n)
{
	if (pStr)
	{
		int nLength = static_cast<int>(strlen(pStr));
		//cout << nLength << endl;
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondStart, pSecondEnd);
			Reverse(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}


void main()
{
	char pData[] = "I am a student.";
	cout << pData << endl;
	cout << "���ӷ�ת��" << endl;
	cout << ReverseSentence(pData) << endl;

	cout << "------------------------------------------------------" << endl;

	char pData1[] = "abcdefg";
	cout << pData1 << endl;
	cout << "����������" << endl;
	cout << LeftRotateString(pData1,3) << endl;
}