#include <iostream>
using namespace std;


void NumofIndex(int Index)
{	
	if (Index <= 0)
	{
		return;
	}

	char chFind = '0';
	if (Index == 1)
	{
		cout << Index << "th char is " << chFind << endl;
	}

	Index--;	//ȥ��0���ڼ���

	int numOfBit = 0;
	// ȷ��ǰ���ж���λ
	int numOfBitBefore = 0;
	// ȷ���Ǽ�λ��
	int i = 1;
	for (;;++i)
	{
		numOfBitBefore = numOfBit;
		numOfBit += 9 * i * (int)pow(10.0, i - 1);
		if (Index <= numOfBit)
		{
			break;
		}
	}
	
	// �������iλ������iλ���ĵڼ�����������nDiv��
	int nDiv = (Index - numOfBitBefore) / i;
	int nLeft = (Index - numOfBitBefore) % i;
	if (nLeft != 0)
	{
		nDiv++;
	}
	// �������Indexλ�����ڵ����֣�������nNumReal��
	int nFirst = (int)pow(10.0, i - 1);
	int nNumReal = nFirst + nDiv - 1;

	// �������Indexλ�������֣�iλ�����ĵڼ�λ��������wei��
	int wei = (nLeft == 0 ? i : nLeft);
	
	char a[50];
	sprintf_s(a, "%d", nNumReal);
	cout << Index+1 << "th char is " << a[wei-1] << endl;
}


void main()
{
	NumofIndex(12);
}