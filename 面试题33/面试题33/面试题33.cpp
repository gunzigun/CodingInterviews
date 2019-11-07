#include <iostream>
using namespace std;

bool VerifySquenceOfBST(int sequence[], int nlength)
{
	if (!sequence || nlength <= 0)
	{
		return false;
	}

	int root = sequence[nlength - 1];
	
	// �����ȸ�С�����һ���ڵ�λ��
	int i = 0;
	for (; i < nlength - 1; ++i)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}

	// �˿�iָ���ˣ���һ���ȸ���Ľڵ㣬֮��Ľڵ㶼Ӧ�ñȸ�����
	int j = i;
	for (; j < nlength - 1; ++j)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	// ִ�е����˵�����Է�Ϊ���������ˣ���ô���ֱ���������������
	// �ж�������У��Ƿ����
	bool bLeft = true;
	if (i > 0)
	{
		bLeft = VerifySquenceOfBST(sequence, i);
	}

	// �ж��ұ����У��Ƿ����
	bool bRight = true;
	if (i < nlength -1)
	{
		bRight = VerifySquenceOfBST(sequence + i, nlength - i - 1);
	}

	return bLeft && bRight;
}


void main()
{
	int array[] = { 5,7,6,9,11,10,8 };
	int nlength = sizeof(array) / sizeof(int);

	for (int i = 0; i < nlength; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;


	if (VerifySquenceOfBST(array, nlength))
	{
		cout << "�Ƕ����������ĺ����������" << endl;
	}
	else
	{
		cout << "���Ƕ����������ĺ����������" << endl;
	}

}