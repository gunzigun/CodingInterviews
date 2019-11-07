#include <iostream>
#include <cmath>
using namespace std;

#define  max(a, b)  (a > b ? a : b)

int getMaxValue_solution1(const int* values, int rows, int cols)
{
	if (!values || rows <= 0 || cols <= 0)
	{
		return 0;
	}

	int** maxValues = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		maxValues[i] = new int[cols];
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int left = 0;
			int up = 0;

			if (i > 0)
			{
				up = maxValues[i - 1][j];
			}

			if (j > 0)
			{
				left = maxValues[i][j - 1];
			}

			maxValues[i][j] = max(left, up) + values[i*cols + j];
		}
	}

	int maxValue = maxValues[rows - 1][cols - 1];
	for (int i = 0; i < rows; ++i)
	{
		delete[] maxValues[i];
	}
	delete[] maxValues;

	return maxValue;
}

void main()
{
	int array[] = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
	int rows = 4;
	int cols = 4;

	cout << "输出礼物矩阵" << endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << array[i*cols + j] << "\t";
		}
		cout << endl;
	}

	cout << "-------------------------------------------" << endl;

	cout << "能够获取到的礼物最大值" << getMaxValue_solution1(array, rows, cols) << endl;
}