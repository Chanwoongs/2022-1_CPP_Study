#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char name[10] = { 'T', 'e', 'd', 'd', 'y' }; // 10ũ���� �迭�̹Ƿ�, 9���� �����ڸ� ������ �����ϴ�.
	cout << "�� �̸��� " << name << " �Դϴ�." << endl;

	char email[100] = {};
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> email;
	cout << "�̸��� : " << email << endl;

	cin.ignore(100, '\n'); // �Է� ���� ����ֱ�

	cout << "�̸��� �Է��ϼ��� : ";
	cin.getline(email, 100, '\n'); // ���� Ű�� ������ ����
	cout << "�̸��� : " << email << endl;
}


