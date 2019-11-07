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
				max.push_back(num);								// max����һ��Ԫ��
				push_heap(max.begin(), max.end(), less<T>());	// �Ӵ�С����Ԫ��

				num = max[0];									// �������Ԫ�ص�ֵ

				pop_heap(max.begin(), max.end(), less<T>());	// ���Ѷ�Ԫ�غ����Ԫ�ضԵ�
				max.pop_back();									// �Ƴ����Ԫ��
			}

			min.push_back(num);									// ������ѵ����Ԫ�ؼ���С����
			push_heap(min.begin(), min.end(), greater<T>());	// ���½�С��������
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);								// min����һ��Ԫ��
				push_heap(min.begin(), min.end(), greater<T>());// ��С��������Ԫ��

				num = min[0];									// ������СԪ�ص�ֵ

				pop_heap(min.begin(), min.end(), greater<T>()); // ���Ѷ�Ԫ�غ����Ԫ�ضԵ�
				min.pop_back();									// �Ƴ���СԪ��
			}

			max.push_back(num);									// ��С���ѵ���СԪ�ؼ�������
			push_heap(max.begin(), max.end(), less<T>());		// ���½����������
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

	cout << "��λ���ǣ�" << myArray.GetMedian() << endl;
}