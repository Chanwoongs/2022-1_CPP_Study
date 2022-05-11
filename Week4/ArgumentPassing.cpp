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
	cout << "������ ���� radius : " << radius << endl;
}

Circle::Circle(float radius)
{
	this->radius = radius;
	cout << "������ ���� radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� ���� radius : " << radius << endl;
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
	// call by value �Լ� ȣ��
	increaseRadius(waffle, 5.0f);
	cout << waffle.getRadius() << endl << endl;
	// call by reference �Լ� ȣ��
	increaseRadius(&waffle, 5.0f);
	cout << waffle.getRadius() << endl << endl;

	// ��ü ġȯ
	Circle c1;
	Circle c2(10);
	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl;
	c1 = c2;
	cout << c1.getRadius() << endl;
	cout << c2.getRadius() << endl << endl;

	// ��ü ����
	Circle c;
	cout << c.getRadius() << endl;
	c = getPizza();
	cout << c.getRadius() << endl << endl;
}