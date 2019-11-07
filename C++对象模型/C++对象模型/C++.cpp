#include <iostream>
#include<windows.h>
using namespace std;

class X1 {};
class X2 {};
class M1 : public X1 {};
class M2 : public X1, public X2 {};
class I1 : public virtual X1 {};
class I2 : public virtual X1 {};
class I3 : public virtual X1 {};

class A1 : public I1, public I2, public I3 {};
class A2 : public M1, public I1, public I2, public I3{};
class A3 : public M2, public I1, public I2, public I3 {};
class A4 : public M1, public M2, public I1, public I2, public I3 {};

void Function1()
{
	cout << sizeof(X1) << endl;
	cout << sizeof(X2) << endl;
	cout << sizeof(M1) << endl;
	cout << sizeof(M2) << endl;
	cout << sizeof(I1) << endl;
	cout << sizeof(I2) << endl;
	cout << sizeof(I3) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(A3) << endl;
	cout << sizeof(A4) << endl;
}

//-----------------------------------------------------------------------------------------------
class Concrete1
{
private:
	int val;
	char bit1;
};

class Concrete2 : public Concrete1
{
private:
	char bit2;
};

class Concrete3 : public Concrete2
{
private:
	char bit3;
};

void Function2()
{
	cout << sizeof(Concrete1) << endl;
	cout << sizeof(Concrete2) << endl;
	cout << sizeof(Concrete3) << endl;
}

// -----------------------------------------------------------------------

class Point3d
{
public:
	virtual ~Point3d() {};
	void PrintData()
	{
		cout << &x << endl;
		cout << &y << endl;
		cout << &z << endl;

		printf("%p\n", &Point3d::x);
		printf("%p\n", &Point3d::y);
		printf("%p\n", &Point3d::z);
	}
protected:
	static Point3d origin;
	float x, y, z;
};

void Function3()
{
	Point3d a;
	cout << &a << endl;

	a.PrintData();
}

// ------------------------------------------------------------------------

class MyBaseClass
{
public:
	virtual void A() { cout << "MyBaseClass:A" << endl; }
	virtual void B() { cout << "MyBaseClass:B" << endl; }
};

class DeriveClass : public MyBaseClass
{
public:
	void A() { cout << "DeriveClass:A" << endl; B(); DeriveClass::B(); }
	void B() { cout << "DeriveClass:B" << endl; }
};

void Function4()
{
	DeriveClass derive;
	MyBaseClass* p_base = &derive;
	p_base->A();

	MyBaseClass base = derive;
	base.A();
}

// ---------------------------------------------------------------------------------

class Base1
{
public:
	virtual ~Base1() { cout << "Base1释放" << endl; };
	virtual void Base1Function() { cout << "one" << endl; };
	virtual void Print() { cout << "Base1::Print()" << endl; };
};

class Base2
{
public:
	virtual ~Base2() { cout << "Base2释放" << endl; };
	virtual void Base2Function() { cout << "two" << endl; };
	virtual void Print() { cout << "Base2::Print()" << endl; };
};

class MyClass : public Base1, public Base2
{
public:
	virtual ~MyClass() { cout << "MyClass释放" << endl; };
	void Print() { cout << "MyClass::Print()" << endl; };
};

void Function5()
{
	Base1* pbase1 = new MyClass;
	Base2* pbase2 = new MyClass;
	MyClass* pMy = new MyClass;

	pMy->Print();					cout << "------------" << endl;
	pMy->Base1Function();			cout << "------------" << endl;
	pMy->Base2Function();			cout << "------------" << endl;

	pbase1->Print();				cout << "------------" << endl;
	pbase1->Base1Function();		cout << "------------" << endl;
	// pbase1->Base2Function();   编译失败

	pbase2->Print();				cout << "------------" << endl;
	pbase2->Base2Function();		cout << "------------" << endl;
	// pbase2->Base1Function();   编译失败

	delete pbase1;					cout << "------------" << endl;
	delete pbase2;					cout << "------------" << endl;
	delete pMy;						cout << "------------" << endl;
}

// ---------------------------------------------------------------------

class Po2
{
public:
	virtual void print() { cout << "Po2::print" << endl; }
	virtual void mumble() { cout << "Po2::mumble" << endl; }
};

class Po3 : virtual public Po2
{
public:
	void print() { cout << "Po3::print" << endl; }
};

void Function6()
{
	Po3* pPO3 = new Po3;
	Po2* pPO2 = pPO3;
	
	pPO2->print();
	pPO2->mumble();

	pPO3->print();
	pPO3->mumble();

	delete pPO2;
	pPO2 = pPO3 = NULL;
}

// -------------------------------------------------------------------

class Example
{
public:
	virtual double show() { return m_dValue; }
	double show2() { return m_dValue+1; }
protected:
	double m_dValue = 1.2;
};

class Fuck : public Example
{
	double show() { return m_dValue; }
private:
	double m_dValue = 2.2;
};

void Function7()
{
	Example a;
	Example* pa = &a;

	double (Example::* coord)() = &Example::show;
	cout << (a.*coord)() << endl;
	cout << (pa->*coord)() << endl;

	coord = &Example::show2;
	cout << (a.*coord)() << endl;
	cout << (pa->*coord)() << endl;


	Example* b = new Fuck;
	cout << b->show() << endl;
	delete b;
	b = NULL;
}

// -------------------------------------------------------------------------

class MyList
{
public:
	float x, y, z;
};

class MyList2
{
public:
	MyList2():x(0.0),y(0.0),z(0.0){}
	void SetX(float x_value) { x = x_value; }
private:
	float x, y, z;
};

void Function8()
{
	MyList object = { 1.0, 2.0, 3.0 };
	cout << object.x << endl;

	MyList2 temp;
	MyList2 *heap = new MyList2;
	*heap = temp;
	heap->SetX(100.0);

	delete heap;
}

// ----------------------------------------------------------------------------

class ConstructorA
{
public:
	ConstructorA()
	{
		number = 0;
		cout << "ConstructorA::ConstructorA()" << endl;
	}
	ConstructorA(const ConstructorA& object)
	{
		number = object.number;
		cout << "ConstructorA::ConstructorA(const ConstructorA& object)" << endl;
	}
	ConstructorA& operator=(const ConstructorA& object)
	{
		number = object.number;
		cout << "ConstructorA& operator=(const ConstructorA& object)" << endl;
		return *this;
	}
private:
	int number;
};

class ConstructorB : public ConstructorA 
{
public:
	ConstructorB()
	{
		cout << "ConstructorB::ConstructorB()" << endl;
	}
};

void Function9()
{
	ConstructorB object;
	cout << "--------------------第一个结果--------------------" << endl;
	ConstructorA object1;
	cout << "--------------------第二个结果--------------------" << endl;
	ConstructorA object2 = object1;
	cout << "--------------------第三个结果--------------------" << endl;
	ConstructorA object3(object2);
	cout << "--------------------第四个结果--------------------" << endl;
	object3 = object1;
}

// ----------------------------------------------------------------------------

class Matrix
{
public:
	Matrix() { cout << "Matrix()" << endl; }
	Matrix(int a) : value(a) { cout << "Matrix(int a)" << endl; }
	~Matrix() { cout << "~Matrix() " << value << endl; }
	const Matrix& identity() 
	{
		static Matrix mat_identity;
		cout << "调用identity" << endl;
		return mat_identity;
	}
private:
	int value;
};

void Function10()
{
	Matrix object(10);
	object.identity();
	object.identity();
}

// -------------------------------------------------------------------------------------

class MyPoint
{
public:
	MyPoint() {};
	virtual ~MyPoint() { cout << "MyPoint::~MyPoint()" << endl; };
};

class MyPoint3d : public MyPoint
{
public:
	MyPoint3d() {};
	virtual ~MyPoint3d() { cout << "MyPoint3d::~MyPoint3d()" << endl; };
};

void Function11()
{
	int num = 5;
	MyPoint *ptr = new MyPoint3d[num];
	delete[] ptr;
}

// --------------------------------------------------------------------

void main()
{
	//Function1();
	
	//Function2();
	
	//Function3();
	
	//Function4();
	
	//Function5();
	
	//Function6();
	
	//Function7();
	
	//Function8();
	
	//Function9();
	
	//Function10();
	//Sleep(10000);

	Function11();
}




