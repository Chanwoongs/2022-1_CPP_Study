#include <iostream>

using namespace std;

float getCircleArea(float radius) 
{
	return 3.14 * radius * radius;
}

int main()
{
	float radius;

	cout << "면적을 구할 원의 반지름을 입력하세요 : ";

	cin >> radius;

	cout << "반지름이 " << radius << "인 원의 면적은 " << getCircleArea(radius) << endl;
}