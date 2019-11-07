#include <iostream>
using namespace std;

long long Fibonacci(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}
	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusOne = fibNMinusTwo;
		fibNMinusTwo = fibN;
	}
	return fibN;
}

void main()
{
	// �޷������ͱ�ʶunsigned�����ǽ������Ĳ��ַ�Χ���䵽������֮��
	cout << "short ���͵�ռ���ֽڴ�С��" << sizeof(short) << endl;  // short ���͵�ռ���ֽڴ�С��2
	cout << "int ���͵�ռ���ֽڴ�С��" << sizeof(int) << endl;		// int ���͵�ռ���ֽڴ�С��4
	cout << "long ���͵�ռ���ֽڴ�С��" << sizeof(long) << endl;	// long ���͵�ռ���ֽڴ�С��4
	cout << "long long ���͵�ռ���ֽڴ�С��" << sizeof(long long) << endl;  //long long ���͵�ռ���ֽڴ�С��8
		
	int nNum = 10;
	cout << "Fibonacci(" << nNum << ")��ֵΪ��" << Fibonacci(nNum) << endl;
}