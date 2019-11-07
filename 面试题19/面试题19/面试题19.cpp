#include <iostream>
using namespace std;

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
	{
		return true;
	}
	if (*str != '\0' && *pattern == '\0')
	{
		return false;
	}

	if (*(pattern+1) == '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str, pattern + 2) || matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern);
		}
		else
		{
			return matchCore(str, pattern + 2);
		}
	} 
	else
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			return matchCore(str + 1, pattern + 1);
		} 
		else
		{
			return false;
		}
	}
}

bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
	{
		return false;
	}
	return matchCore(str, pattern);
}

void main()
{
	char* str = "abdc";
	char* pattern = "a..c";

	cout << "×Ö·û´®£º" << str << endl;
	cout << "Ä£Ê½´®£º" << pattern << endl;

	bool bSame = match(str, pattern);
	if (bSame)
	{
		cout << "Æ¥Åä³É¹¦" << endl;
	} 
	else
	{
		cout << "Æ¥ÅäÊ§°Ü" << endl;
	}
}