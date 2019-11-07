#include <iostream>
using namespace std;

bool Duplicate1(int inputarray[], int length, int *dupnum)
{
	if (inputarray == NULL || length <= 0)
	{
		return false;
	}

	for (int i = 0; i < length; ++i)
	{
		if (inputarray[i] < 0 || inputarray[i] > length-1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; ++i)
	{
		while (inputarray[i] != i)
		{
			int numnow = inputarray[i];
			if (numnow == inputarray[numnow])
			{
				*dupnum = numnow;
				return true;
			}

			// ��������
			int temp = inputarray[i];
			inputarray[i] = inputarray[temp];
			inputarray[temp] = temp;
		}
	}
}


// ���������з�Χ�����ָ���
int countNumRange(const int* array, int lenth, int strat_num, int end_num)
{
	int nCount = 0;
	if (array == NULL)
	{
		return nCount;
	}

	for (int i = 0; i < lenth; ++i)
	{
		if (array[i] >= strat_num && array[i] <= end_num)
		{
			++nCount;
		}
	}
	
	return nCount;
}


bool Duplicate2(const int* inputarray, int lenth, int* dupnum)
{
	if (inputarray == NULL || lenth <= 0)
	{
		cout << "�����в��������ݣ��������" << endl;
		return false;
	}

	int start_num = 1;
	int end_num = lenth - 1;
	for (int i = 0; i < lenth; ++i)
	{
		if (inputarray[i] < start_num || inputarray[i] > end_num)
		{
			cout << "���������Ӧ���ڡ�" << start_num << "-" << end_num << "����Χ�ڣ�" << endl;
			return false;
		}
	}

	while (end_num >= start_num)
	{
		int mid_num = (int)((end_num - start_num) / 2 + start_num);
		int nCount = countNumRange(inputarray, lenth, start_num, mid_num);

		// ѭ�������������ҵ����ظ�������
		if (start_num == end_num)
		{
			if (nCount > 1)
			{
				*dupnum = start_num;
				return true;
			}
			else
			{
				break;
			}
		}
		
		// ͳ���������ǲ������ַ�Χ�е����ֶ�
		if (nCount > (mid_num - start_num + 1))
		{
			end_num = mid_num;
		}
		else
		{
			start_num = mid_num + 1;
		}
	}
	
	return false;
}


void main1()
{
	
	//int * array = NULL;
	int array[] = { 0, 1, 2, 2, 2, 1, 3 };

	int length = 0;
	if (array != NULL)
	{
		length = sizeof(array) / sizeof(int);
	}	

	int dupnum = -1;
	bool isDuplicate = Duplicate1(array, length, &dupnum);

	if (isDuplicate)
	{
		cout << "�����ظ������֣�" << endl;
		cout << "�ظ�����Ϊ��" << dupnum << endl;
	}
	else
	{
		cout << "�������ظ������֣�" << endl;
	}
}

void main()
{
	//int* array = NULL;
	int array[] = { 2, 1, 5, 4, 3, 2, 6, 7 };
	int lenth = 0;
	if (array != NULL)
	{
		lenth = sizeof(array) / sizeof(int);
	}

	int ndupnum = -1;
	bool bDuplicate = Duplicate2(array, lenth, &ndupnum);
	if (bDuplicate)
	{
		cout << "�����ظ����֣��ظ�����Ϊ��" << ndupnum << endl;
	} 
	else
	{
		cout << "�������ظ����֣����������쳣��" << endl;
	}

	system("pause");
}
