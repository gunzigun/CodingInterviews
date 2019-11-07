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
			// 换过去
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			
			// 保持第一个，递归处理后续的
			Permutation(pStr, pBegin + 1);

			// 换回来
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