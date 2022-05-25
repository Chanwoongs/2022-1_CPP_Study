#include <iostream>

using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int sum(int a)
{
	int total = 0;

	for (int i = 1; i <= a; i++)
	{
		total += i;
	}

	return total;
}

int main()
{
	cout << sum(1, 4) << endl;
	cout << sum(10) << endl;
}