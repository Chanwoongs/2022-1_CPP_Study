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

	// static 멤버
	static int sharedMoney;
	static void addSharedMoney(int money)
	{
		sharedMoney += money;
	}
};

// static 변수 공간 할당.
// 반드시 프로그램의 전역 공간에 선언.
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
	// static 멤버는 객체가 생성되기 전에도 호출이 가능하다.
	//Person::addSharedMoney(10000);

	Person bang;
	bang.money = 100; // bang의 개인 돈 100
	bang.addSharedMoney(200); // static 멤버 접근. 공금 = 200

	Person chan;
	chan.money = 150;
	chan.addMoney(200);
	chan.addSharedMoney(200);

	cout << "bang : " << bang.money << endl;
	cout << "chan : " << chan.money << endl;
	cout << "sharedMoney : " << bang.sharedMoney << endl;
	cout << "sharedMoney : " << chan.sharedMoney << endl;
	cout << "sharedMoney : " << Person::sharedMoney << endl;
	// 객체 이름으로 static 멤버 호출, non-static 멤버는 불가능
	Person::addSharedMoney(1000);
	cout << "sharedMoney : " << Person::sharedMoney << endl;
}