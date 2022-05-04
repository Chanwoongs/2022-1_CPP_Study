#include<iostream>

using namespace std;

class Circle
{
public:
	Circle();
	Circle(int radius);
	~Circle();
	
	// �ζ��� �Լ�
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
	// this�� ����Ͽ� radius�� �̸��� ������ ��� ������ ���ڸ� ������ �� �ִ�.
	this->radius = radius;
}

// ������ (��ü ������ 1�� ����)
Circle::Circle() : radius(1)// : radius(1) <- ��� �ʱ�ȭ ����Ʈ
{
}
Circle::Circle(int radius) // : radius(radius)
{
	this->radius = radius;
}
// �Ҹ��� (��ü �Ҹ�� 1�� ����)
Circle::~Circle()
{
	cout << "radius : " << radius << " OUT" << endl;
} 

int main()
{
	Circle donut; // �Ű������� ���� ������ ȣ��
	double donutArea = donut.getArea(); // .���� ��� ����
	cout << "Dount ���� : " << donutArea << endl; 

	Circle pizza(30); // �Ű������� �ִ� ������ ȣ��
	double pizzaArea = pizza.getArea();
	cout << "Pizza ���� : " << pizzaArea << endl;

	Circle* p = new Circle; // p��� �����Ͱ� ���� ������ Circle ��ü�� ����Ŵ
	p->getArea(); // (*p). = p->

	delete p;

	Circle circleArray[3]; // �ϳ��� �迭�� 3���� Circle ��ü ����

	circleArray[0].setRadius(1);
	circleArray[1].setRadius(2);
	circleArray[2].setRadius(3);

	// �迭 Ȱ��
	for (int i = 0; i < 3; i++)
	{
		cout << i << "��° ���� ���� : " << circleArray[i].getArea() << endl;
	}

	Circle* ptr; // ������ ����
	ptr = circleArray; // p�� Circle �迭�� ���� �ּҸ� ����Ŵ

	for (int i = 0; i < 3; i++)
	{
		// 1.
		cout << i << "��° ���� ���� : " << ptr[i].getArea() << endl; // ptr�� ���ٰ���
		// 2.
		cout << i << "��° ���� ���� : " << ptr->getArea() << endl; // ptr�� ���ٰ���
		ptr++;
	}

	Circle newCircleArray[3] = { Circle(10), Circle(20), Circle() }; // Ŭ���� �迭�� ����� ���ÿ� �ʱ�ȭ

	Circle* cir = new Circle(); // Ŭ���� ���� ����
	cout << cir->getArea() << endl;
	delete cir; // ��ü ��ȯ
	cout << p << endl; // ��ȯ�Ͽ��� �����ʹ� �״�� ����Ű�� �ִ�.
	p = 0; // ������ �ʱ�ȭ
	cout << p << endl; // Ȯ��

	Circle* cirs = new Circle[3]; // Ŭ���� �迭 ���� ����
	delete[] cirs; // ��ü �迭 ��ȯ
	cirs = 0; // ������ �ʱ�ȭ
}