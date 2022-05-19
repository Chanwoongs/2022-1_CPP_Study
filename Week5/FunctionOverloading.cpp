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
위의 sum 함수와 리턴 타입은 다르지만 매개변수가 같기 때문에 컴파일러가 구분하지 못한다.
double sum(int a, int b)
{
	return (double)(a + b);
}
*/

// function overloading으로 기능 확장
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

// default parameter 사용
void msg(string text = "Good Morning!")
{
	cout << text << endl;
}

class Circle
{
public:
	Circle();
	Circle(int radius);
	// 위의 두 생성자를 합친 생성자
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

/* 위의 두 생성자를 합친 생성자
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
	cout << "sum() 함수" << endl;
	// function overloading된 sum 함수 호출 (컴파일러가 구분)
	cout << sum(1, 2, 3) << sum(1.1, 2.2) << sum(1, 2) << endl << endl;

	cout << "greet() 함수" << endl;
	greet();
	greet("Chanwoong");
	greet("Chanwoong", 123);
	cout << endl;

	cout << "default parameter msg() 함수" << endl;
	msg();
	msg("Good Night!");

	Circle c1 = Circle();
	Circle c2 = Circle(10);
}