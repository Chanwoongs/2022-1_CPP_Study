#include <iostream>

using namespace std;

class Person
{
public:
	Person();
	~Person();

	int money;
	void addMoney(int money) 
	{
		this->money += money;
	}

	// static ���
	static int sharedMoney;
	static void addSharedMoney(int money)
	{
		sharedMoney += money;
	}
};

// static ���� ���� �Ҵ�.
// �ݵ�� ���α׷��� ���� ������ ����.
int Person::sharedMoney = 0;

Person::Person()
{
	money = 0;
}

Person::~Person()
{
}

int main()
{
	// static ����� ��ü�� �����Ǳ� ������ ȣ���� �����ϴ�.
	//Person::addSharedMoney(10000);

	Person bang;
	bang.money = 100; // bang�� ���� �� 100
	bang.addSharedMoney(200); // static ��� ����. ���� = 200

	Person chan;
	chan.money = 150;
	chan.addMoney(200);
	chan.addSharedMoney(200);

	cout << "bang : " << bang.money << endl;
	cout << "chan : " << chan.money << endl;
	cout << "sharedMoney : " << bang.sharedMoney << endl;
	cout << "sharedMoney : " << chan.sharedMoney << endl;
	cout << "sharedMoney : " << Person::sharedMoney << endl;
	// ��ü �̸����� static ��� ȣ��, non-static ����� �Ұ���
	Person::addSharedMoney(1000);
	cout << "sharedMoney : " << Person::sharedMoney << endl;
}