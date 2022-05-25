#include<iostream>

using namespace std;

class Power
{
public:
	Power(int kick = 0, int punch = 0)
	{
		this->kick = kick;
		this->punch = punch;
	}

	// + 이항 연산자
	Power operator+(Power a)
	{
		Power temp;
		temp.kick = this->kick + a.kick;
		temp.punch = this->punch + a.punch;

		return temp;
	}
	// == 비교 연산자
	bool operator==(Power a)
	{
		if (this->kick == a.kick && this->punch == a.punch)
			return true;
		else
			return false;
	}
	// += 복합 대입 연산자
	Power operator+=(Power a)
	{
		this->kick += a.kick;
		this->punch += a.punch;

		return *this; // this 자기 자신의 포인터
		// *this -> 자기 자신 즉 객체본인
	}
	// + 이항 연산자
	Power operator+(int a)
	{
		Power temp;
		temp.kick = this->kick + a;
		temp.punch = this->punch + a;

		return temp;
	}

	// 전위 ++ 단항 연산자
	Power operator++() 
	{
		this->kick++;
		this->punch++;

		return *this;
	}
	// 전위 ! 단항 연산자
	bool operator!()
	{
		if (this->kick == 0 && this->punch == 0)
			return true;
		else
			return false;
	}
	// 후위 ++ 단항 연산자
	Power operator++(int x)
	{
		Power temp = *this; // 증가 이전의 객체 상태 저장
		this->kick++;
		this->punch++;

		return temp; // 증가 이전의 객체 리턴
	}

	void show()
	{
		cout << "kick : " << kick << " punch : " << punch << endl;
	}
private:
	int kick;
	int punch;
};

int main()
{
	Power a(3, 5), b(4, 6), c, d(3, 5), e(0, 0);

	c = a + b; // 컴파일러는 c = a.+(b) 로 변형한다.
	c.show();

	if (a == d) // a.==(d)
		cout << "same" << endl;
	else
		cout << "not same" << endl;

	if (a == c)
		cout << "same" << endl;
	else
		cout << "not same" << endl;

	++a; // a.++()
	a.show();

	if (!e) // a.!()
		cout << "e is emtpy" << endl;

	b = a++; // a.++(임의의 정수)
	a.show(); // a의 파워는 1 증가
	b.show(); // b는 a가 증가되기 이전의 상태를 가짐

	Power f(1, 1), g(2, 2);

	cout << endl;

	f += g;
	f.show();
	a = f += g;
	a.show();

	Power h(10, 10);
	a = h + 5; // h.+(5)
	a.show();
}