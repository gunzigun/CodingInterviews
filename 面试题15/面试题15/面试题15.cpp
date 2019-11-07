#include <iostream>
using namespace std;


int NumberOf1(int n)
{
	int nCount = 0; 
	unsigned int nFlag = 1;
	while (nFlag)
	{
		if (n & nFlag)
		{
			++nCount;
		}
		nFlag = nFlag << 1;
	}
	return nCount;
}

int Good_NumberOf1(int n)
{
	int nCount = 0;
	while (n)
	{
		++nCount;
		n = (n - 1) & n;
	}
	return nCount;
}

int DiffBit(int a, int b)
{
	return Good_NumberOf1(a^b);
}


class Base
{
public:
	virtual void f(float x) {cout << "基类::f(float)函数" << x << endl;}
	virtual void f(int x, int y) {cout << "基类::f(int, int)函数" << x << "," << y << endl;}
	virtual void f1(float x) {cout << "基类::f1(float)函数" << x << endl;}
	void g(float x) {cout << "基类::g(float)函数" << x << endl;}
	void g(int x, int y) {cout << "基类::g(int, int)函数" << x << "," << y << endl;}
	void h(float x) {cout << "基类::h(float)函数" << x << endl;}
	static void my(float x) {cout << "基类::my(float)函数" << x << endl;}
};

class Derived : public Base
{
public:
	virtual void f(float x) {cout << "子类::f(float)函数" << x << endl;}
	virtual void f1(int x) {cout << "子类::f1(int)函数" << x << endl;}
	void g(int x) {cout << "子类::g(int)函数" << x << endl;}
	void h(float x) {cout << "子类::h(float)函数" << x << endl;}
	static void my(float x) {cout << "子类::my(float)函数" << x << endl;}
};


void main()
{
	int n = 100;
	cout << "数字\"" << n << "\"的二进制中有" << NumberOf1(n) << "个数字1" << endl;
	cout << "数字\"" << n << "\"的二进制中有" << Good_NumberOf1(n) << "个数字1" << endl;

	int a = 0xFFAC;
	int b = 0xFFBA;
	cout << "数字\"" << a << "\"和数字\"" << b << "\"中有 " << DiffBit(a,b) << " 个不同位！" << endl;

	
	Derived oDerived;
	Base *pBase = &oDerived;
	Derived *pDerived = &oDerived;

	pBase->f(3.14f);
	pDerived->f(3.14f);

	pBase->f(1, 2);
	//pDerived->f(1, 2);  // to be removed

	pBase->f1(3.14f);
	pDerived->f1(3.14f);

	// hide
	pBase->g(3.14f);
	pDerived->g(3.14f);

	pBase->g(1, 2);
	//pDerived->g(1, 2);  // to be removed

	// hide
	pBase->h(3.14f);
	pDerived->h(3.14f);

	pBase->my(3.14f);
	pDerived->my(3.14f);
}