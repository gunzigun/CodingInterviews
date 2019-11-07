#include <iostream>
using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int &pathLenth, bool* visited)
{
	if (str[pathLenth] == '\0')
	{
		return true;
	}

	bool bhasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		matrix[row * cols + col] == str[pathLenth] && !visited[row * cols + col])
	{
		++pathLenth;
		visited[row * cols + col] = true;

		bhasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLenth, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col, str, pathLenth, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1, str, pathLenth, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col, str, pathLenth, visited);

		if (!bhasPath)
		{
			--pathLenth;
			visited[row * cols + col] = false;
		}
	}

	return bhasPath;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
	{
		return false;
	}
	
	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLenth = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLenth, visited))
			{
				return true;
			}
		}
	}

	delete[] visited;
	return false;
}

void main()
{
	const int rows = 3;
	const int cols = 4;
	char matrix[rows*cols] =
	{
		'a', 'b', 't', 'g',
		'c', 'f', 'c', 's',
		'j', 'd', 'e', 'h'
	};
	
	char* str = "abfceh";

	if (hasPath(matrix, rows, cols, str))
	{
		cout << "¾ØÕóÖÐ´æÔÚ×Ö·û´®£»" << str << endl;
	}
	else
	{
		cout << "¾ØÕóÖÐ²»´æÔÚ×Ö·û´®£»" << str << endl;
	}

}