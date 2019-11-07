#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template<typename T>
class DynamicArray
{
public:
	void Insert(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);								// max加入一个元素
				push_heap(max.begin(), max.end(), less<T>());	// 从大到小重排元素

				num = max[0];									// 保存最大元素的值

				pop_heap(max.begin(), max.end(), less<T>());	// 将堆定元素和最后元素对调
				max.pop_back();									// 移除最大元素
			}

			min.push_back(num);									// 将大根堆的最大元素加入小根堆
			push_heap(min.begin(), min.end(), greater<T>());	// 重新将小根堆排序
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);								// min加入一个元素
				push_heap(min.begin(), min.end(), greater<T>());// 从小到大重排元素

				num = min[0];									// 保存最小元素的值

				pop_heap(min.begin(), min.end(), greater<T>()); // 将堆定元素和最后元素对调
				min.pop_back();									// 移除最小元素
			}

			max.push_back(num);									// 将小根堆的最小元素加入大根堆
			push_heap(max.begin(), max.end(), less<T>());		// 重新将大根堆排序
		}
	}

	T GetMedian()
	{
		T median = 0;
		int size = min.size() + max.size();
		if (size == 0)
		{
			return median;
		}

		if ((size & 1) == 1)
		{
			median = min[0];
		}
		else
		{
			median = (min[0] + max[0]) / 2;
		}
		return median;
	}

private:
	vector<T> min;
	vector<T> max;
};


void main()
{
	DynamicArray<int> myArray;
	myArray.Insert(3);
	myArray.Insert(1);
	myArray.Insert(2);
	myArray.Insert(4);
	myArray.Insert(7);
	myArray.Insert(8);
	myArray.Insert(6);
	myArray.Insert(5);

	cout << "中位数是：" << myArray.GetMedian() << endl;
}