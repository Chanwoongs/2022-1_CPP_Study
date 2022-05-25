#include <iostream>

using namespace std;

int big(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int big(int a[], int size)
{
	int temp = a[0];
	for (int i = 1; i < size; i++)
	{
		if (temp < a[i]) temp = a[i];
	}
	return temp;
}

int main()
{
	int array[5] = { 1, 2, 3, 4, 5 };
	cout << big(3, 5) << endl;
	cout << big(array, 5) << endl;
}