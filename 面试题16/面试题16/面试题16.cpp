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
	//1) �ֱ���ʮ�����ơ�ʮ���ơ��˽����Ⱥ���� n
	cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;
	
	double x = 1234567.89, y = 12.34567;
	//2)����5λ��Ч����
	cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
	
	//3)����С�������5λ
	cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;
	
	//4)��ѧ������������ұ���С�������5λ
	cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;
	
	//5)�Ǹ�����ʾ���ţ�������Ϊ12�ַ�����Ȳ������� * �
	cout << "5)" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
	
	//6)�Ǹ�������ʾ���ţ�������Ϊ12�ַ�����Ȳ������ұ�������ַ����
	cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;
	
	//7)������Ϊ 12 �ַ�����Ȳ��������������ַ����
	cout << "7)" << setw(12) << right << 12.1 << endl;
	
}

void main()
{
	double base = -1.110021;
	int exponent = 2;

	cout << "�ҵĺ��������ֵ��" << Power(base, exponent) << endl;
	cout << "�Ƿ����쳣����ı�ʶ��" << g_bInvalidInput << endl;

	cout << "ϵͳ���������ֵ��" << pow(base, exponent) << endl;

	printFunction();
}