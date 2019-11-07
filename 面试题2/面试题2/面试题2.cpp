#include <iostream>
#include <mutex>
using namespace std;

// ���߳���ʵ�ֵ���ģʽ������ʽ������ʽ��
class Singleton1
{
private:
	static Singleton1* instance;
	// ��ֹ�ⲿ�����Ϳ���
	Singleton1(){};
	Singleton1(const Singleton1& singleton){};
	Singleton1& operator=(const Singleton1&){};

public:
	int a = 0;
	static Singleton1* GetInstance()
	{
		if (instance == NULL) 
		{
			cout << "��û��ʵ��������Ҫ������" << endl;
			instance = new Singleton1();
		}

		cout << "�������ָ��ĵ�ַ��" << instance << endl;
		return instance;
	}
	
	~Singleton1()
	{
		cout << "���ڵ��ͷŵ��ˣ�" << endl;
	}
};
Singleton1* Singleton1::instance = new Singleton1(); // = NULL;


// ���߳���ʵ�ֵ���ģʽ
class Singleton2
{
private:
	static Singleton2* instance;
	static mutex mutex_;

	// ��ֹ�ⲿ�����Ϳ���
	Singleton2(){};
	Singleton2(const Singleton2& singleton){};
	Singleton2& operator=(const Singleton2&){};

public:
	int a = 0;
	static Singleton2* GetInstance()
	{
		if (instance == NULL)
		{
			lock_guard<mutex> lock(mutex_);
			if (instance == NULL) 
			{
				cout << "��û��ʵ��������Ҫ������" << endl;
				instance = new Singleton2();
			}
		}

		cout << "�������ָ��ĵ�ַ��" << instance << endl;
		return instance;
	}

	~Singleton2()
	{
		cout << "���ڵ��ͷŵ��ˣ�" << endl;
	}
};
Singleton2* Singleton2::instance;//= NULL;
mutex Singleton2::mutex_;

void main()
{	
	/*
	Singleton1* first = Singleton1::GetInstance();
	Singleton1* second = Singleton1::GetInstance();
	first->a = 100;
	cout << second->a << endl;
	*/

	Singleton2* first = Singleton2::GetInstance();
	Singleton2* second = Singleton2::GetInstance();
	first->a = 100;
	cout << second->a << endl;
}