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

void increaseRadius(Circle c, float num)
{
	c.setRadius(c.getRadius() + num);
}

void increaseRadius(Circle* c, float num)
{
	c->setRadius(c->getRadius() + num);
}

Circle getPizza()
{
	Circle pizza(50);
	return pizza;
}

int main()
{
	Circle waffle(30);
	// call by value 함수 호출
	increaseRadius(waffle, 5.0f);
	cout << waffle.getRadius() << endl << endl;
	// call by reference 함수 호출
	increaseRadius(&waffle, 5.0f);
	cout << waffle.getRadius() << endl << endl;

	// 객체 치환
	Circle c1;
	Circle c2(10);
	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl;
	c1 = c2;
	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl << endl;

	// 객체 리턴
	Circle c;
	cout << c.getRadius() << endl;
	c = getPizza();
	cout << c.getRadius() << endl << endl;
}