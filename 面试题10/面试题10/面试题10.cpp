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
	// 无符号类型标识unsigned，就是将负数的部分范围扩充到了正数之后
	cout << "short 类型的占用字节大小：" << sizeof(short) << endl;  // short 类型的占用字节大小：2
	cout << "int 类型的占用字节大小：" << sizeof(int) << endl;		// int 类型的占用字节大小：4
	cout << "long 类型的占用字节大小：" << sizeof(long) << endl;	// long 类型的占用字节大小：4
	cout << "long long 类型的占用字节大小：" << sizeof(long long) << endl;  //long long 类型的占用字节大小：8
		
	int nNum = 10;
	cout << "Fibonacci(" << nNum << ")的值为：" << Fibonacci(nNum) << endl;
}