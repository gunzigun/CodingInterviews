#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int nArrlength)
{
	if (string == NULL || nArrlength <= 0)
	{
		cout << "�ַ���Ϊ�գ�" << endl;
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

	cout << "�ַ�������ռ�Ϊ��" << nArrlength << endl;
	cout << "һ�����ַ�" << nStringLenth << "�����ո�" << nNumofBlank << "��" << endl;

	int nNewStringLen = nStringLenth + 2 * nNumofBlank;
	if (nNewStringLen > nArrlength)
	{
		cout << "�ַ�������ռ䲻�㣬�޷��滻��" << endl;
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

	cout << "�滻ǰ���ַ���Ϊ��" << string << endl;

	ReplaceBlank(string, lenth);

	cout << "�滻֮����ַ���Ϊ��" << string << endl;
}