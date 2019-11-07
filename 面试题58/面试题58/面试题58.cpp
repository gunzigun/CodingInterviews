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
	pEnd--;		//因为此时，pEnd指向了字符串的结束符，需要减一位

	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转每个单词
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
	cout << "句子翻转：" << endl;
	cout << ReverseSentence(pData) << endl;

	cout << "------------------------------------------------------" << endl;

	char pData1[] = "abcdefg";
	cout << pData1 << endl;
	cout << "句子左旋：" << endl;
	cout << LeftRotateString(pData1,3) << endl;
}