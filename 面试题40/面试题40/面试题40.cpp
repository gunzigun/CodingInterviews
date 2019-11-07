#include <set>
#include <iostream>
#include <vector>
using namespace std;

#include<functional>
typedef multiset<int, less<int>> intSet;
typedef multiset<int, less<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k)
	{
		return;
	}

	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter)
	{
		if (leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
		else
		{
			setIterator iterGreat = leastNumbers.end();
			if (*iter < *(--iterGreat))
			{
				leastNumbers.erase(iterGreat);
				leastNumbers.insert(*iter);
			}
		}
	}

}


void main()
{
	int array[] = {4,5,1,6,2,7,3,8};
	vector<int> data(array, array+sizeof(array)/sizeof(int));
	
	intSet leastNumbers;
	int k = 5;
	
	GetLeastNumbers(data, leastNumbers, k);

	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++ iter)
	{
		cout << *iter << " ";
	}
}
