#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> maxVector;
	if (num.size() > size && size > 1)
	{
		deque<int> index;

		// 先处理最前面的size个元素
		for (unsigned int i = 0; i < size; ++i)
		{
			while (!index.empty() && num[i] >= num[index.back()])
			{
				index.pop_back();
			}
			index.push_back(i);
		}

		// 处理后续元素
		for (unsigned int i = size; i < num.size(); ++i)
		{
			maxVector.push_back(num[index.front()]);

			while (!index.empty() && num[i] >= num[index.back()])
			{
				index.pop_back();
			}
			// 处理窗口滑动
			if (!index.empty() && index.front() <= (int)(i-size))
			{
				index.pop_front(); // 之前窗口的元素，需要剔除掉
			}
			index.push_back(i);
		}
		maxVector.push_back(num[index.front()]);
	}
	return maxVector;
}

template<typename T>
class QueueWithMax
{
public:
	QueueWithMax():currentIndex(0) {}
	void push_back(T number)
	{
		while (!maximums.empty() && number > maximums.back().number)
		{
			maximums.pop_back();
		}

		InternalData internalData = { number, currentIndex };
		data.push_back(internalData);
		maximums.push_back(internalData);

		++currentIndex;
	}

	void pop_front()
	{
		if (maximums.empty())
		{
			throw new exception("queue is empty");
		}

		if (maximums.front().index == data.front().index)
		{
			maximums.pop_front();
		}
		
		data.pop_front();
	}

	T getMax() const
	{
		if (maximums.empty())
		{
			throw new exception("queue is empty");
		}

		return maximums.front().number;
	}


private:
	struct InternalData
	{
		T number;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maximums;
	int currentIndex;
};


void main()
{
	int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> num(array, array + sizeof(array) / sizeof(int));
	vector<int> maxVector = maxInWindows(num,3);
	for (vector<int>::iterator iter = maxVector.begin(); iter != maxVector.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "----------------------------------------------------------------" << endl;

	QueueWithMax<int> myQueue;
	myQueue.push_back(1);
	myQueue.push_back(5);
	myQueue.push_back(3);
	cout << "最大元素" << myQueue.getMax() << endl;

	myQueue.pop_front();
	myQueue.pop_front();
	cout << "最大元素" << myQueue.getMax() << endl;

	myQueue.push_back(2);
	myQueue.push_back(4);
	cout << "最大元素" << myQueue.getMax() << endl;
	
}
