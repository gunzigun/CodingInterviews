#include <iostream>
using namespace std;

void Permutation(char* pStr)
{
	if (!pStr)
	{
		return;
	}

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin=='\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			// ����ȥ
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			
			// ���ֵ�һ�����ݹ鴦�������
			Permutation(pStr, pBegin + 1);

			// ������
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}

}

void main()
{
	char a[] = "abcdf";
	Permutation(a);
}