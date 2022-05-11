#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(float radius);
	~Circle();
	float getRadius() { return radius; }
	void setRadius(float radius) { this->radius = radius; }
	float getArea() { return 3.14 * radius * radius; }
private:
	float radius;
};

Circle::Circle()
{
	radius = 1.0f;
	cout << "생성자 실행 radius : " << radius << endl;
}

Circle::Circle(float radius)
{
	this->radius = radius;
	cout << "생성자 실행 radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius : " << radius << endl;
}

void increaseRadius(Circle &c, float num)
{
	c.setRadius(c.getRadius() + num);
}

void readRadius(Circle& c)
{
	float radius;
	cout << "설정할 반지름 입력 : ";
	cin >> radius; 
	c.setRadius(radius);
}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

char& find(char& c)
{
	return c;
}

char& find(char s[], int index)
{
	return s[index];
}

int main()
{
	int n = 2;
	int& refn = n; // 참조 변수 refn 선언.
	// refn은 n에 대한 별명, 즉 동일한 변수이다.
	cout << "n = " << n << endl;
	refn = 5;
	cout << "n = " << n << endl;
	// 참조 변수에 대한 포인터 생성 가능
	int* p = &refn;
	*p = 7;
	cout << "n = " << n << endl;

	Circle circle;
	Circle& refc = circle; // 참조 변수 refc 선언.
	// refc은 circle에 대한 별명, 즉 동일한 변수이다.
	cout << "circle의 반지름 : " << circle.getRadius() << endl;
	refc.setRadius(10);
	increaseRadius(refc, 10);
	cout << "circle의 반지름 : " << circle.getRadius() << endl << endl;

	// 참조 매개변수를 이용한 swap 함수
	int a = 10, b = 20;
	cout << "a : " << a << ", b : " << b << endl;
	swap(a, b);
	cout << "a : " << a << ", b : " << b << endl << endl;

	// 참조 매개변수를 이용한 readRadius 함수
	Circle cir;
	cout << "cir의 반지름 : " << cir.getRadius() << endl;
	readRadius(cir);
	cout << "cir의 반지름 : " << cir.getRadius() << endl << endl;

	// 참조 리턴
	char c = 'a';
	char ch = find(c);
	char& ref = find(c);
	cout << c << ch << ref << find(c) << endl;
	ch = 'b';
	cout << c << ch << ref << find(c) << endl;
	ref = 'c';
	cout << c << ch << ref << find(c) << endl;
	find(c) = 'd';
	cout << c << ch << ref << find(c) << endl << endl;

	// 참조 리턴
	char name[] = "Bang";
	cout << name << endl;
	find(name, 0) = 'P';
	cout << name << endl;
	char& refs = find(name, 1);
	refs = 'o';
	cout << name << endl;
}
