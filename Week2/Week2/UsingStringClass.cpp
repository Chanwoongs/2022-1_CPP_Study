#include <iostream>
#include <string>
using namespace std;

int main()
{
	string song("Love Yourself");
	string bieber("Justin Bieber");
	string singer;

	cout << song << "�� �θ� ���� �Է� : ";
	getline(cin, singer);

	if (singer == bieber)
	{
		cout << "�¾ҽ��ϴ�." << endl;
	}
	else
	{
		cout << "�ƴմϴ�." << endl;
	}
}