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
		if (preIndex < 0 || i - preIndex > nCurrentLen)				// 没出现过 || 当前位置距离之前出现位置，大于已有的长度
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
