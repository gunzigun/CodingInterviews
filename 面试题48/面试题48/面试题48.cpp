#include <iostream>
#include <string>
using namespace std;

int longestSubstringWithoutDuplication(const string& str)
{
	int nCurrentLen = 0;
	int nMaxLen = 0;

	int* position = new int[26];
	for (int i = 0; i < 26; ++i)
	{
		position[i] = -1;
	}

	for (int i = 0; i < str.length(); ++i)
	{
		int preIndex = position[str[i] - 'a'];
		if (preIndex < 0 || i - preIndex > nCurrentLen)				// û���ֹ� || ��ǰλ�þ���֮ǰ����λ�ã��������еĳ���
		{
			++nCurrentLen;
		}
		else
		{
			if (nCurrentLen > nMaxLen)
			{
				nMaxLen = nCurrentLen;
			}
			nCurrentLen = i - preIndex;
		}
		position[str[i] - 'a'] = i;
	}

	if (nCurrentLen > nMaxLen)
	{
		nMaxLen = nCurrentLen;
	}

	delete[] position;
	return nMaxLen;
}

void main()
{
	string str = "arabcacfr";
	int a = longestSubstringWithoutDuplication(str);
	cout << a << endl;
}
