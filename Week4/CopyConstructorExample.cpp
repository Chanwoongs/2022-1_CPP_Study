#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
	Person(int id, char* name); // �⺻ ������
	Person(Person& person); // ���� ������
	~Person();
	void changeName(char* name) // �̸� ����
	{
		if (strlen(name) > strlen(this->name))
		{
			return; // ���� name�� �Ҵ�� �޸𸮺��� �� �̸����� �ٲ� �� ����.
		}
		strcpy(this->name, name);
	}
	void show() { cout << id << ", " << name << endl; }

private:
	int id;
	char* name;
};

Person::Person(int id, char* name)
{
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(Person& person)
{
	this->id = person.id; // id �� ����
	int len = strlen(person.name); // name�� ���� ����
	this->name = new char[len + 1]; // name�� ���� ���� �Ҵ�
	strcpy(this->name, person.name); // name�� ���ڿ� ����
	cout << "���� ������ ����. ���� ��ü�� �̸� : " << this->name << endl;
}

Person::~Person()
{
	if (name)
		delete[] name;
}

int main()
{
	char name[] = "Bang";
	Person father(1, name);
	Person daughter(father);

	cout << "daughter ��ü ���� ���� ------------" << endl;
	father.show();
	daughter.show();

	char name1[] = "Chan";
	daughter.changeName(name1);

	cout << "daughter �̸��� Chan���� ������ �� ------------" << endl;	
	father.show();
	daughter.show();

	// ������ ���� ������ ��
	// 1)
	Person son = father; // ���� ������ �ڵ� ȣ��
	// Person son(father); �� ���� ��ȯ �Ѵ�.
	// Person son;
	// son = father; ���� �ٸ���.

	// 2)
	// void f(Person person){} �Ű����� person�� ������ �� ���� ������ ȣ��
	// f(father); // ���� ���� ȣ��� father ��ü ����

	// 3)
	// Person g() {
	// Person mother(2, "Jane");
	// return mother; // mother�� ���纻�� �����Ͽ� ���纻 ����, �纻�� ������� �� ���� ������ ȣ��
	// }
	// g();

}