#include<iostream>

using namespace std;

int sum(int a, int b, int c)
{
	return a + b + c;
}

double sum(double a, double b)
{
	return a + b;
}

int sum(int a, int b)
{
	return a + b;
}

/*
���� sum �Լ��� ���� Ÿ���� �ٸ����� �Ű������� ���� ������ �����Ϸ��� �������� ���Ѵ�.
double sum(int a, int b)
{
	return (double)(a + b);
}
*/

// function overloading���� ��� Ȯ��
void greet()
{
	cout << "Hello" << endl;
}

void greet(string name)
{
	cout << "Hello " << name << endl;
}

void greet(string name, int id)
{
	cout << "Hello " << name << " your id number is " << id << endl;
}

// default parameter ���
void msg(string text = "Good Morning!")
{
	cout << text << endl;
}

class Circle
{
public:
	Circle();
	Circle(int radius);
	// ���� �� �����ڸ� ��ģ ������
	// Circle(int radius = 1);
	~Circle();

private:
	int radius;
};

Circle::Circle()
{
	radius = 1;
}

Circle::Circle(int radius)
{
	this->radius = radius;
}

/* ���� �� �����ڸ� ��ģ ������
Circle::Circle(int radius = 1)
{
	this->radius = radius;
}
*/

Circle::~Circle()
{
}

int main()
{
	cout << "sum() �Լ�" << endl;
	// function overloading�� sum �Լ� ȣ�� (�����Ϸ��� ����)
	cout << sum(1, 2, 3) << sum(1.1, 2.2) << sum(1, 2) << endl << endl;

	cout << "greet() �Լ�" << endl;
	greet();
	greet("Chanwoong");
	greet("Chanwoong", 123);
	cout << endl;

	cout << "default parameter msg() �Լ�" << endl;
	msg();
	msg("Good Night!");

	Circle c1 = Circle();
	Circle c2 = Circle(10);
}