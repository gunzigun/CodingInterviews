#include <iostream>
using namespace std;


bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	return *str > before;
}


bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	return scanUnsignedInteger(str);
}


bool isNumeric(const char* str)
{
	if (str == NULL)
	{
		return false;
	}

	bool numeric = scanInteger(&str);
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}


void main()
{
	char* str = "-11.3522e-1342";
	cout << str << " ";
	
	if (isNumeric(str))
	{
		cout << "是数字" << endl;
	}
	else
	{
		cout << "不是数字" << endl;
	}
}