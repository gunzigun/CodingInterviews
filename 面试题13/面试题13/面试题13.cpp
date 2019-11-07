#include <iostream>
using namespace std;


int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += (number % 10);
		number = number / 10;
	}
	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		getDigitSum(row) + getDigitSum(col) <= threshold &&
		!visited[row * cols + col])
	{
		return true;
	}
	return false;
}

int GetMovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int nCount = 0; 
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;
		nCount = 1 + GetMovingCountCore(threshold, rows, cols, row - 1, col, visited)
				   + GetMovingCountCore(threshold, rows, cols, row, col + 1, visited)
			       + GetMovingCountCore(threshold, rows, cols, row + 1, col, visited)
			       + GetMovingCountCore(threshold, rows, cols, row, col - 1, visited);
	}
	return nCount;
}

int GetMovingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
	{
		return 0;
	}

	bool* visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);
	
	int nCount = GetMovingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;
	
	return nCount;
}

void main()
{
	int rows = 100;
	int cols = 100;
	int threshold = 18;

	int nCount1 = GetMovingCount(threshold, rows, cols);
	cout << nCount1 << endl;

	/*
	int nCount2 = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (getDigitSum(i) + getDigitSum(j) <= threshold)
			{
				++nCount2;
			}
		}
	}
	cout << nCount2 << endl;
	*/
}