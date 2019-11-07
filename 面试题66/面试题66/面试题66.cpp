#include <iostream>
#include <vector>
using namespace std;

void multiply(const vector<int>& array1, vector<int>& array2)
{
	int length1 = array1.size();
	int length2 = array2.size();

	if (length1 == length2 && length2 > 1)
	{
		array2[0] = 1;
		for (int i = 1; i < length1; ++i)
		{
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		
		int Temp = 1;
		for (int i = length1 - 2; i >= 0; --i)
		{
			Temp *= array1[i + 1];
			array2[i] *= Temp;
		}
	}
}

void main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	int length = sizeof(array) / sizeof(int);
	vector<int> array1(array, array + length);
	vector<int> array2(length);

	multiply(array1,array2);

	for (int i = 0; i < length; ++i)
	{
		cout << array2[i] << " ";
	}
	cout << endl;
}