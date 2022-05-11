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

void increaseRadius(Circle &c, float num)
{
	c.setRadius(c.getRadius() + num);
}

void readRadius(Circle& c)
{
	float radius;
	cout << "������ ������ �Է� : ";
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
	int& refn = n; // ���� ���� refn ����.
	// refn�� n�� ���� ����, �� ������ �����̴�.
	cout << "n = " << n << endl;
	refn = 5;
	cout << "n = " << n << endl;
	// ���� ������ ���� ������ ���� ����
	int* p = &refn;
	*p = 7;
	cout << "n = " << n << endl;

	Circle circle;
	Circle& refc = circle; // ���� ���� refc ����.
	// refc�� circle�� ���� ����, �� ������ �����̴�.
	cout << "circle�� ������ : " << circle.getRadius() << endl;
	refc.setRadius(10);
	increaseRadius(refc, 10);
	cout << "circle�� ������ : " << circle.getRadius() << endl << endl;

	// ���� �Ű������� �̿��� swap �Լ�
	int a = 10, b = 20;
	cout << "a : " << a << ", b : " << b << endl;
	swap(a, b);
	cout << "a : " << a << ", b : " << b << endl << endl;

	// ���� �Ű������� �̿��� readRadius �Լ�
	Circle cir;
	cout << "cir�� ������ : " << cir.getRadius() << endl;
	readRadius(cir);
	cout << "cir�� ������ : " << cir.getRadius() << endl << endl;

	// ���� ����
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

	// ���� ����
	char name[] = "Bang";
	cout << name << endl;
	find(name, 0) = 'P';
	cout << name << endl;
	char& refs = find(name, 1);
	refs = 'o';
	cout << name << endl;
}
