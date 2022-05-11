#include <iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(float radius);
	Circle(Circle& c); // 복사 생성자 정의
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

// 복사 생성자 구현
Circle::Circle(Circle& c)
{
	this->radius = c.radius;
	cout << "복사 생성자 실행 radius : " << this->radius << endl << endl;
}

Circle::~Circle()
{
	cout << "소멸자 실행 radius : " << radius << endl;
}

int main()
{
	Circle c(30);
	Circle cir(c);

	cout << "원본의 면적 : " << c.getArea() << endl;
	cout << "사본의 면적 : " << cir.getArea() << endl;
}