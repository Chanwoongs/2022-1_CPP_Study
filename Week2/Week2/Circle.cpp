#include <iostream>

using namespace std;

float getCircleArea(float radius) 
{
	return 3.14 * radius * radius;
}

int main()
{
	float radius;

	cout << "������ ���� ���� �������� �Է��ϼ��� : ";

	cin >> radius;

	cout << "�������� " << radius << "�� ���� ������ " << getCircleArea(radius) << endl;
}