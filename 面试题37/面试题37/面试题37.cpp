#include <iostream>
#include <fstream>
using namespace std;

struct BinaryTreeNode
{
	int					m_nValue;
	BinaryTreeNode*		m_pLeft = NULL;
	BinaryTreeNode*		m_pRight = NULL;

	BinaryTreeNode(int num)
	{
		m_nValue = num;
	}
};

void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
	if (!pRoot)
	{
		stream << "$,";
		return;
	}
	
	stream << pRoot->m_nValue << ",";
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}


bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
	{
		return false;
	}
		
	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}
	return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode(number);
		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

void main()
{
	BinaryTreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6);
	node1.m_pLeft = &node2;
	node1.m_pRight = &node3;
	node2.m_pLeft = &node4;
	node3.m_pLeft = &node5;
	node3.m_pRight = &node6;

	BinaryTreeNode* pRoot = &node1;
	
	// 序列化写入文件
	char* fileName = "./test.txt";
	ofstream fileOut;
	fileOut.open(fileName);
	Serialize(pRoot, fileOut);
	fileOut.close();

	// 输出文件内容
	ifstream fileIn1;
	char ch;
	fileIn1.open(fileName);
	while (!fileIn1.eof())
	{
		fileIn1 >> ch;
		cout << ch;
	}
	fileIn1.close();
	cout << endl;

	// 反序列化生成树
	ifstream fileIn2;
	fileIn2.open(fileName);
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);
	fileIn2.close();

	cout << "结束了" << endl;
}