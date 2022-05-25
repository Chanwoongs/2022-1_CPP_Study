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

	// + ���� ������
	Power operator+(Power a)
	{
		Power temp;
		temp.kick = this->kick + a.kick;
		temp.punch = this->punch + a.punch;

		return temp;
	}
	// == �� ������
	bool operator==(Power a)
	{
		if (this->kick == a.kick && this->punch == a.punch)
			return true;
		else
			return false;
	}
	// += ���� ���� ������
	Power operator+=(Power a)
	{
		this->kick += a.kick;
		this->punch += a.punch;

		return *this; // this �ڱ� �ڽ��� ������
		// *this -> �ڱ� �ڽ� �� ��ü����
	}
	// + ���� ������
	Power operator+(int a)
	{
		Power temp;
		temp.kick = this->kick + a;
		temp.punch = this->punch + a;

		return temp;
	}

	// ���� ++ ���� ������
	Power operator++() 
	{
		this->kick++;
		this->punch++;

		return *this;
	}
	// ���� ! ���� ������
	bool operator!()
	{
		if (this->kick == 0 && this->punch == 0)
			return true;
		else
			return false;
	}
	// ���� ++ ���� ������
	Power operator++(int x)
	{
		Power temp = *this; // ���� ������ ��ü ���� ����
		this->kick++;
		this->punch++;

		return temp; // ���� ������ ��ü ����
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

	c = a + b; // �����Ϸ��� c = a.+(b) �� �����Ѵ�.
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

	b = a++; // a.++(������ ����)
	a.show(); // a�� �Ŀ��� 1 ����
	b.show(); // b�� a�� �����Ǳ� ������ ���¸� ����

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