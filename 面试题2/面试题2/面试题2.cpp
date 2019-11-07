#include <iostream>
#include <mutex>
using namespace std;

// 单线程中实现单例模式（饿汉式、懒汉式）
class Singleton1
{
private:
	static Singleton1* instance;
	// 阻止外部创建和拷贝
	Singleton1(){};
	Singleton1(const Singleton1& singleton){};
	Singleton1& operator=(const Singleton1&){};

public:
	int a = 0;
	static Singleton1* GetInstance()
	{
		if (instance == NULL) 
		{
			cout << "还没有实例，所以要创建！" << endl;
			instance = new Singleton1();
		}

		cout << "输出单例指针的地址：" << instance << endl;
		return instance;
	}
	
	~Singleton1()
	{
		cout << "现在得释放掉了！" << endl;
	}
};
Singleton1* Singleton1::instance = new Singleton1(); // = NULL;


// 多线程中实现单例模式
class Singleton2
{
private:
	static Singleton2* instance;
	static mutex mutex_;

	// 阻止外部创建和拷贝
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
				cout << "还没有实例，所以要创建！" << endl;
				instance = new Singleton2();
			}
		}

		cout << "输出单例指针的地址：" << instance << endl;
		return instance;
	}

	~Singleton2()
	{
		cout << "现在得释放掉了！" << endl;
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