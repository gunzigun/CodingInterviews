#include <iostream>
using namespace std;

char FirstNotRepeating(char* pString)
{
	if (!pString)
	{
		return '\0';
	}

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
	{
		hashTable[i] = 0;
	}

	char* pHashKey = pString;
	while (*pHashKey != '\0')
	{
		hashTable[*(pHashKey++)]++;
	}

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
		{
			return *pHashKey;
		}
		pHashKey++;
	}

	return '\0';
}



void main()
{
	char a[] = "abdwcssADAS";
	cout << FirstNotRepeating(a) << endl;
}