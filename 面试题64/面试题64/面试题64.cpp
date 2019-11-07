#include <iostream>
using namespace std;

//---------------------------------------------------------------------------------------------

class Temp
{
public:
	Temp()
	{
		++N;
		Sum += N;
	}

	static void Reset()
	{
		N = 0;
		Sum = 0;
	}

	static unsigned int GetSum()
	{
		return Sum;
	}

private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int SumFunction1(unsigned int n)
{
	Temp::Reset();
	Temp* a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

//---------------------------------------------------------------------------------------------

class A;
A* Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B : public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

unsigned int SumFunction2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}

//---------------------------------------------------------------------------------------------

typedef unsigned int(*fun)(unsigned int n);

unsigned int SumFunction3_End(unsigned int n)
{
	return 0;
}

unsigned int SumFunction3(unsigned int n)
{
	static fun f[2] = { SumFunction3_End, SumFunction3 };
	return f[!!n](n - 1) + n;
}

//---------------------------------------------------------------------------------------------

template <unsigned int n>
struct SumFunction4
{
	enum Value
	{
		N = SumFunction4<n - 1>::N + n
	};
};

template <> struct SumFunction4 <1>
{
	enum Value
	{
		N = 1
	};
};

void main()
{
	unsigned n = 10;
	cout << "解法1：" << SumFunction1(n) << endl;
	cout << "解法2：" << SumFunction2(n) << endl;
	cout << "解法3：" << SumFunction3(n) << endl;
	cout << "解法4：" << SumFunction4<10>::N << endl;
}