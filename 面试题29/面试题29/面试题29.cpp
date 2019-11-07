#include <iostream>
using namespace std;

void PrintMarixInCircle(int** numbers, int rows, int columns, int nStart)
{
	int EndX = columns - 1 - nStart;
	int EndY = rows - 1 - nStart;
	
	// 从左到右打印一行
	for (int i = nStart; i <= EndX; ++i)
	{
		cout << numbers[nStart][i] << " ";
	}

	// 从上到下打印一列
	if (nStart < EndY)
	{
		for (int i = nStart + 1; i <= EndY; ++i)
		{
			cout << numbers[i][EndX] << " ";
		}
	}

	// 从右到左打印一行
	if (nStart < EndX && nStart < EndY)
	{
		for (int i = EndX - 1; i >= nStart; --i)
		{
			cout << numbers[EndY][i] << " ";
		}
	}

	// 从下到上打印一列
	if (nStart < EndX && nStart < EndY - 1)
	{
		for (int i = EndY - 1; i >= nStart + 1; --i)
		{
			cout << numbers[i][nStart] << " ";
		}
	}
}

void PrintMarixClockWisely(int** numbers, int rows, int columns)
{
	if (!numbers || columns <= 0 || rows <= 0)
	{
		return;
	}

	int nStart = 0;
	while (rows > nStart * 2 && columns > nStart * 2)
	{
		PrintMarixInCircle(numbers, rows, columns, nStart);
		++nStart;
	}

	cout << endl;
}

int myFunction1(int arr[][3])
{
	return arr[1][1];
}

int myFunction2(int (*arr)[3])
{
	return arr[1][1];
}

int myFunction3(int** arr)
{
	return arr[1][1];
}

void main()
{
	const int rows = 4;
	const int columns = 4;
	int array[rows][columns] = 
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 },
	};
	
	int* a[columns];
	a[0] = array[0];
	a[1] = array[1];
	a[2] = array[2];
	a[3] = array[3];
	
	PrintMarixClockWisely(a, rows, columns);


	//定义数组
	int arr[3][3] =
	{
		{ 1, 2, 3 },
		{ 2, 100, 4 },
		{ 3, 4, 5 },
	};

	// 形参为二维数组，给定第二维度长度3
	// 函数定义：myFunction1(int arr[][3])
	cout << "函数一返回的中心元素是" << myFunction1(arr) << endl;
	
	// 形参为指向数组的指针，给定数组长度3
	// 函数定义：myFunction2(int (*arr)[3])
	// int (*arr)[3] 中：*arr 表示arr是一个指针；[3]表示指针指向的对象的类型是具有3个元素的数组；int表示该数组的元素是int类型的
	cout << "函数二返回的中心元素是" << myFunction2(arr) << endl;
	
	// 形参为指针的指针，实参必须为指针，不能是数组名
	// 函数定义：myFunction3(int** arr)
	int* p[3];
	p[0] = arr[0];
	p[1] = arr[1];
	p[2] = arr[2];
	cout << "函数三返回的中心元素是" << myFunction3(p) << endl;

}