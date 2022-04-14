#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char name[10] = { 'T', 'e', 'd', 'd', 'y' }; // 10크기의 배열이므로, 9개의 영문자만 저장이 가능하다.
	cout << "제 이름은 " << name << " 입니다." << endl;

	char email[100] = {};
	cout << "이메일 입력하세요 : ";
	cin >> email;
	cout << "이메일 : " << email << endl;

	cin.ignore(100, '\n'); // 입력 버퍼 비워주기

	cout << "이메일 입력하세요 : ";
	cin.getline(email, 100, '\n'); // 엔터 키를 누를때 까지
	cout << "이메일 : " << email << endl;
}


