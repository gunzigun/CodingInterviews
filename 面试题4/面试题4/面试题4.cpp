#include <iostream>
using namespace std;

bool findNum(int* array, const int rows, const int columns, int number)
{
	if (array == NULL || (rows <= 0 && columns <= 0))
	{
		cout << "������û������!" << endl;
		return false;
	}
	
	int row = 0;
	int column = columns - 1;
	while (column >= 0 && row <= rows -1)
	{
		int indexnum = array[row * columns + column];
		if (indexnum == number)
		{
			cout << "�ڵ� " << row + 1 << " �У��� " << column + 1 << " �У��ҵ��˸����֣�" << endl;
			return true;
		}

		if (indexnum > number)
		{
			--column;
		}

		if (indexnum < number)
		{
			++row;
		}
	}

	return false;
}


void main()
{
	const int rows = 4;
	const int columns = 4;

	/*int* array = null;*/
	
	int array[rows*rows] = 
	{
		1, 2, 8, 9, 
		2, 4, 9, 12, 
		4, 7, 10, 13,
		6, 8, 11, 15 
	};
	

	int nFindNum = 5;
	cout << "��Ҫ���ҵ�����Ϊ " << nFindNum << endl;

	if (!findNum(array, rows, columns, nFindNum))
	{
		cout << "û���ҵ������֣�" << endl;
	}
}