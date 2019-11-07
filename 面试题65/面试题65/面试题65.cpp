#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum, carry;
	do 
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} 
	while (carry != 0);

	return num1;
}

void main()
{
	cout << Add(5, 17) << endl;
}