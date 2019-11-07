#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class StackWithMin
{
private:
	stack<T> m_data;
	stack<T> m_min;
public:
	void push(const T& value);
	void pop();
	const T& min() const;
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if (m_min.size() == 0 || m_min.top() > value)
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template <typename T>
void StackWithMin<T>::pop()
{
	//assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
	//assert(m_data.size() > 0 && m_min.size() > 0);

	return m_min.top();
}

int main()
{
	StackWithMin<int> a;
	a.push(3);
	cout << "当前最小元素为： " << a.min() << endl;

	a.push(4);
	cout << "当前最小元素为： " << a.min() << endl;

	a.push(2);
	cout << "当前最小元素为： " << a.min() << endl;

	a.push(1);
	cout << "当前最小元素为： " << a.min() << endl;

	a.pop();
	cout << "当前最小元素为： " << a.min() << endl;

	a.pop();
	cout << "当前最小元素为： " << a.min() << endl;

	a.push(0);
	cout << "当前最小元素为： " << a.min() << endl;
}