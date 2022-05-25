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
	printLine(); // 첫번째엔 문자, 두번째엔 줄수
	cout << endl;

	printLine('%'); // 두번째엔 줄수
	cout << endl;

	printLine('@', 5);
	cout << endl;
}