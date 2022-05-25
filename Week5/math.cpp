#include<iostream>

using namespace std;

class Math
{
public:
	static int sum(int a, int b);
	static int max(int a, int b);
	static int min(int a, int b);
};

int Math::sum(int a, int b)
{
	return a + b;
}

int Math::max(int a, int b)
{
	return (a > b) ? a : b;
}

int Math::min(int a, int b)
{
	return (a > b) ? b : a;
}


int main()
{
	cout << Math::sum(4, 6) << endl;
	cout << Math::max(10, 20) << endl;
	cout << Math::min(1, 100) << endl;
}