#include <iostream>
#include <string>
using namespace std;

int main()
{
	string song("Love Yourself");
	string bieber("Justin Bieber");
	string singer;

	cout << song << "을 부른 가수 입력 : ";
	getline(cin, singer);

	if (singer == bieber)
	{
		cout << "맞았습니다." << endl;
	}
	else
	{
		cout << "아닙니다." << endl;
	}
}