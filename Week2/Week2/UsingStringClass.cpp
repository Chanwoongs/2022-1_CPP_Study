#include <iostream>
#include <string>
using namespace std;

int main()
{
	string song("Love Yourself");
	string bieber("Justin Bieber");
	string singer;

	cout << "가수 입력 : ";
	getline(cin, singer);

	cout << song << "을 부른 가수는 " << singer;
}