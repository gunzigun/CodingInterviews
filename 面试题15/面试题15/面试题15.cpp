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
	virtual void f(float x) {cout << "����::f(float)����" << x << endl;}
	virtual void f(int x, int y) {cout << "����::f(int, int)����" << x << "," << y << endl;}
	virtual void f1(float x) {cout << "����::f1(float)����" << x << endl;}
	void g(float x) {cout << "����::g(float)����" << x << endl;}
	void g(int x, int y) {cout << "����::g(int, int)����" << x << "," << y << endl;}
	void h(float x) {cout << "����::h(float)����" << x << endl;}
	static void my(float x) {cout << "����::my(float)����" << x << endl;}
};

class Derived : public Base
{
public:
	virtual void f(float x) {cout << "����::f(float)����" << x << endl;}
	virtual void f1(int x) {cout << "����::f1(int)����" << x << endl;}
	void g(int x) {cout << "����::g(int)����" << x << endl;}
	void h(float x) {cout << "����::h(float)����" << x << endl;}
	static void my(float x) {cout << "����::my(float)����" << x << endl;}
};


void main()
{
	int n = 100;
	cout << "����\"" << n << "\"�Ķ���������" << NumberOf1(n) << "������1" << endl;
	cout << "����\"" << n << "\"�Ķ���������" << Good_NumberOf1(n) << "������1" << endl;

	int a = 0xFFAC;
	int b = 0xFFBA;
	cout << "����\"" << a << "\"������\"" << b << "\"���� " << DiffBit(a,b) << " ����ͬλ��" << endl;

	
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