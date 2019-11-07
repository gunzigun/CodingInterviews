#include <iostream>
#include <fstream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr)
	{
		if (pData != nullptr)
		{
			delete[]m_pData;
			m_pData = nullptr;
			m_pData = new char[strlen(pData) + 1];
			strcpy(m_pData, pData);
		}
	};

	CMyString(const CMyString& str)
	{
		if (str.m_pData != nullptr)
		{
			delete[]m_pData;
			m_pData = nullptr;
			m_pData = new char[strlen(str.m_pData) + 1];
			strcpy(m_pData, str.m_pData);
		}
	};

	~CMyString() {};

	CMyString& operator =(const CMyString &str);

	char* GetStringInfo();

private:
	char* m_pData;
};

CMyString& CMyString::operator =(const CMyString &str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}

char* CMyString::GetStringInfo()
{
	return m_pData;
}

int main()
{
	CMyString str1("aaaaaaa");
	CMyString str4("bbbbbbb");
	CMyString str2, str3;

	str1 = str1;
	str4 = str3 = str2 = str1;



	cout << str4.GetStringInfo() << endl;

	return 0;
}