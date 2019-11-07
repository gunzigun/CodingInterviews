#include <iostream>
#include <iomanip>
using namespace std;

double PowerWithUnsignedExp(double base, unsigned int exponent)
{
	double dresultNum = 1.0;
	for (int i = 1; i <= exponent; ++i)
	{
		dresultNum *= base;
	}
	return dresultNum;
}

double PowerWithUnsignedExpGood(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}

	double dresultNum = PowerWithUnsignedExpGood(base, exponent >> 1);
	dresultNum *= dresultNum;

	if ((exponent & 0x1) == 1)
	{
		dresultNum *= base;
	}

	return dresultNum;
}

bool g_bInvalidInput = false;

double Power(double base, int exponent)
{
	if (base == 0.0 && exponent < 0)
	{
		g_bInvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)exponent;
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double dresultNum = PowerWithUnsignedExpGood(base, absExponent);
	if (exponent < 0)
	{
		dresultNum = 1 / dresultNum;
	}

	return dresultNum;
}

void printFunction()
{
	int n = 141;
	//1) 分别以十六进制、十进制、八进制先后输出 n
	cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;
	
	double x = 1234567.89, y = 12.34567;
	//2)保留5位有效数字
	cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
	
	//3)保留小数点后面5位
	cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;
	
	//4)科学计数法输出，且保留小数点后面5位
	cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;
	
	//5)非负数显示正号，输出宽度为12字符，宽度不足则用 * 填补
	cout << "5)" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
	
	//6)非负数不显示正号，输出宽度为12字符，宽度不足则右边用填充字符填充
	cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;
	
	//7)输出宽度为 12 字符，宽度不足则左边用填充字符填充
	cout << "7)" << setw(12) << right << 12.1 << endl;
	
}

void main()
{
	double base = -1.110021;
	int exponent = 2;

	cout << "我的函数的输出值：" << Power(base, exponent) << endl;
	cout << "是否有异常输入的标识：" << g_bInvalidInput << endl;

	cout << "系统函数的输出值：" << pow(base, exponent) << endl;

	printFunction();
}