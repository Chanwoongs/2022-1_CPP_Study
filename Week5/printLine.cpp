#include<iostream>

using namespace std;

void printLine(char let = '-', int size = 1)
{
	for (int i = 0; i < size; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << let;
		}
		cout << endl;
	}
}

int main()
{
	printLine(); // ù��°�� ����, �ι�°�� �ټ�
	cout << endl;

	printLine('%'); // �ι�°�� �ټ�
	cout << endl;

	printLine('@', 5);
	cout << endl;
}