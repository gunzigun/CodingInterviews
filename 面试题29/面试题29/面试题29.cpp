#include <iostream>
using namespace std;

void PrintMarixInCircle(int** numbers, int rows, int columns, int nStart)
{
	int EndX = columns - 1 - nStart;
	int EndY = rows - 1 - nStart;
	
	// �����Ҵ�ӡһ��
	for (int i = nStart; i <= EndX; ++i)
	{
		cout << numbers[nStart][i] << " ";
	}

	// ���ϵ��´�ӡһ��
	if (nStart < EndY)
	{
		for (int i = nStart + 1; i <= EndY; ++i)
		{
			cout << numbers[i][EndX] << " ";
		}
	}

	// ���ҵ����ӡһ��
	if (nStart < EndX && nStart < EndY)
	{
		for (int i = EndX - 1; i >= nStart; --i)
		{
			cout << numbers[EndY][i] << " ";
		}
	}

	// ���µ��ϴ�ӡһ��
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


	//��������
	int arr[3][3] =
	{
		{ 1, 2, 3 },
		{ 2, 100, 4 },
		{ 3, 4, 5 },
	};

	// �β�Ϊ��ά���飬�����ڶ�ά�ȳ���3
	// �������壺myFunction1(int arr[][3])
	cout << "����һ���ص�����Ԫ����" << myFunction1(arr) << endl;
	
	// �β�Ϊָ�������ָ�룬�������鳤��3
	// �������壺myFunction2(int (*arr)[3])
	// int (*arr)[3] �У�*arr ��ʾarr��һ��ָ�룻[3]��ʾָ��ָ��Ķ���������Ǿ���3��Ԫ�ص����飻int��ʾ�������Ԫ����int���͵�
	cout << "���������ص�����Ԫ����" << myFunction2(arr) << endl;
	
	// �β�Ϊָ���ָ�룬ʵ�α���Ϊָ�룬������������
	// �������壺myFunction3(int** arr)
	int* p[3];
	p[0] = arr[0];
	p[1] = arr[1];
	p[2] = arr[2];
	cout << "���������ص�����Ԫ����" << myFunction3(p) << endl;

}