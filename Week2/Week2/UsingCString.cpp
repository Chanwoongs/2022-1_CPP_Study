#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char name[10] = { 'T', 'e', 'd', 'd', 'y' }; // 10ũ���� �迭�̹Ƿ�, 9���� �����ڸ� ������ �����ϴ�.
	cout << "�� �̸��� " << name << " �Դϴ�." << endl;

	char email[100] = {};
	cin >> email;
	cout << "�̸��� : " << email << endl;

	cin.ignore(100, '\n'); // �Է� ���� ����ֱ�

	cin.getline(email, 100, '\n');
	cout << "�̸��� : " << email << endl;
}


