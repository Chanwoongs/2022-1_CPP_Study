#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(float radius);
	Circle(Circle& c); // ���� ������ ����
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

// ���� ������ ����
Circle::Circle(Circle& c)
{
	this->radius = c.radius;
	cout << "���� ������ ���� radius : " << this->radius << endl << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� ���� radius : " << radius << endl;
}

int main()
{
	Circle c(30);
	Circle cir(c);

	cout << "������ ���� : " << c.getArea() << endl;
	cout << "�纻�� ���� : " << cir.getArea() << endl;
}