#include<iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(int radius);
	~Circle();
	
	// 인라인 함수
	int getRadius()
	{
		return radius;
	}
	void setRadius(int radius);
	double getArea()
	{
		return radius * radius * 3.14f;
	}

private:
	int radius;
	//const int area;
};

void Circle::setRadius(int radius)
{
	// this를 사용하여 radius란 이름은 같지만 멤버 변수와 인자를 구분할 수 있다.
	this->radius = radius;
}

// 생성자 (객체 생성시 1번 실행)
Circle::Circle() : radius(1)// : radius(1) <- 멤버 초기화 리스트
{
}
Circle::Circle(int radius) // : radius(radius)
{
	this->radius = radius;
}
// 소멸자 (객체 소멸시 1번 실행)
Circle::~Circle()
{
	cout << "radius : " << radius << " OUT" << endl;
} 

int main()
{
	Circle donut; // 매개변수가 없는 생성자 호출
	double donutArea = donut.getArea(); // .으로 멤버 접근
	cout << "Dount 면적 : " << donutArea << endl; 

	Circle pizza(30); // 매개변수가 있는 생성자 호출
	double pizzaArea = pizza.getArea();
	cout << "Pizza 면적 : " << pizzaArea << endl;

	Circle* p = new Circle; // p라는 포인터가 새로 생성된 Circle 객체를 가리킴
	p->getArea(); // (*p). = p->

	delete p;

	Circle circleArray[3]; // 하나의 배열에 3개의 Circle 객체 생성

	circleArray[0].setRadius(1);
	circleArray[1].setRadius(2);
	circleArray[2].setRadius(3);

	// 배열 활용
	for (int i = 0; i < 3; i++)
	{
		cout << i << "번째 원의 면적 : " << circleArray[i].getArea() << endl;
	}

	Circle* ptr; // 포인터 선언
	ptr = circleArray; // p가 Circle 배열의 시작 주소를 가리킴

	for (int i = 0; i < 3; i++)
	{
		// 1.
		cout << i << "번째 원의 면적 : " << ptr[i].getArea() << endl; // ptr로 접근가능
		// 2.
		cout << i << "번째 원의 면적 : " << ptr->getArea() << endl; // ptr로 접근가능
		ptr++;
	}

	Circle newCircleArray[3] = { Circle(10), Circle(20), Circle() }; // 클래스 배열의 선언과 동시에 초기화

	Circle* cir = new Circle(); // 클래스 동적 생성
	cout << cir->getArea() << endl;
	delete cir; // 객체 반환
	cout << p << endl; // 반환하여도 포인터는 그대로 가리키고 있다.
	p = 0; // 포인터 초기화
	cout << p << endl; // 확인

	Circle* cirs = new Circle[3]; // 클래스 배열 동적 생성
	delete[] cirs; // 객체 배열 반환
	cirs = 0; // 포인터 초기화
}