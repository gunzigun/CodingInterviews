#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int nArrlength)
{
	if (string == NULL || nArrlength <= 0)
	{
		cout << "字符串为空！" << endl;
		return;
	}

	int nStringLenth = 0;
	int nNumofBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			++nNumofBlank;
		}
		++nStringLenth;
		++i;
	}

	cout << "字符串数组空间为：" << nArrlength << endl;
	cout << "一共有字符" << nStringLenth << "个，空格" << nNumofBlank << "个" << endl;

	int nNewStringLen = nStringLenth + 2 * nNumofBlank;
	if (nNewStringLen > nArrlength)
	{
		cout << "字符串数组空间不足，无法替换！" << endl;
		return;
	}

	int nIndexOrigin = nStringLenth;
	int nIndexNew = nNewStringLen;
	//while (nIndexOrigin < nIndexNew && nIndexOrigin >= 0)
	while (nIndexOrigin != nIndexNew)
	{
		char chCharofIndex = string[nIndexOrigin];
		if (chCharofIndex != ' ')
		{
			string[nIndexNew --] = chCharofIndex;
		}
		else
		{
			string[nIndexNew --] = '0';
			string[nIndexNew --] = '2';
			string[nIndexNew --] = '%';
		}
		--nIndexOrigin;
	}
}


void main()
{
	const int lenth = 50;

	char string[lenth] = "We are happy.";

	cout << "替换前的字符串为：" << string << endl;

	ReplaceBlank(string, lenth);

	cout << "替换之后的字符串为：" << string << endl;
}