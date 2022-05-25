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
	friend Power operator+(int op1, Power op2);
	friend Power operator+(Power op1, Power op2);
	friend Power operator++(Power& op);
	friend Power operator++(Power& op, int x);
	friend bool operator==(Power op1, Power op2);
	friend bool operator!(Power op1);


	void show()
	{
		cout << "kick : " << kick << " punch : " << punch << endl;
	}
private:
	int kick;
	int punch;
};

// + ���� ������ ���� + ��ü
Power operator+(int op1, Power op2)
{
	op2.kick = op1 + op2.kick;
	op2.punch = op1 + op2.punch;

	return op2;
}
// + ���� ������ ��ü + ��ü
Power operator+(Power op1, Power op2)
{
	Power temp;
	temp.kick = op1.kick + op2.kick;
	temp.punch = op1.punch + op1.punch;

	return temp;
}
// == �� ������
bool operator==(Power op1, Power op2)
{
	if (op1.kick == op2.kick && op1.punch == op2.punch)
	{
		return true;
	}
	else return false;
}

// ���� ++ ���� ������
Power operator++(Power& op)
{
	Power temp;
	op.kick++;
	op.punch++;

	return op;
}
// ���� ++ ���� ������
Power operator++(Power& op, int x)
{
	Power temp = op; // ���� ������ ��ü ���� ����
	op.kick++;
	op.punch++;

	return temp; // ���� ������ ��ü ����
}
// ���� ! ���� ������
bool operator!(Power op1)
{
	if (op1.kick == 0 && op1.punch == 0)
	{
		return true;
	}
	return false;
}


int main()
{
	Power a(3, 5), b(4, 6), c, d(3, 5), e(0, 0);

	c = a + b; // c = + (a, b)
	c.show();
	c = 2 + a; // c = + (2, a)
	c.show();

	++a; // ++ (a)
	a.show();

	b = a++; // ++ (a, 0) 0�� �ǹ� ���� ��
	a.show(); // a�� �Ŀ��� 1 ����
	b.show(); // b�� a�� �����Ǳ� ������ ���¸� ����

	Power r, t;

	if (r == t)
	{
		cout << "same" << endl;
	}

	if (!r)
	{
		cout << "r is empty" << endl;
	}
}