#include <iostream>
#include <stack>
using namespace std;

template <typename T> 
class CQueue
{
public:
	CQueue(){};
	~CQueue(){};

	void appendTail(const T& node);
	T deleteHead();
	bool empty();

private:
	stack <T> stackIn;
	stack <T> stackOut;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stackIn.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (stackOut.empty())
	{
		while (!stackIn.empty())
		{
			T& data = stackIn.top();
			stackIn.pop();
			stackOut.push(data);
		}
	}
	if (stackOut.empty())
	{
		throw new exception("queue is empty!");
	}
	T head = stackOut.top();
	stackOut.pop();
	return head;
}

template <typename T>
bool CQueue<T>::empty()
{
	if (stackIn.empty() && stackOut.empty())
	{
		return true;
	}
	return false;
}


void main()
{
	CQueue<char> MyQueue;
	MyQueue.appendTail('a');
	MyQueue.appendTail('b');
	MyQueue.appendTail('c');

	while (!MyQueue.empty())
	{
		cout << MyQueue.deleteHead() << endl;
	}
}