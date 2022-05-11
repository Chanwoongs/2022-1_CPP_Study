#include <iostream>

using namespace std;

class Accumulator
{
public:
	Accumulator(int value);
	Accumulator& add(int n);
	~Accumulator();
	int get() { return value; }
private:
	int value;
};

Accumulator::Accumulator(int value)
{
	this->value = value;
}

Accumulator& Accumulator::add(int n)
{
	this->value += n;
	return *this;
}

Accumulator::~Accumulator()
{
}

int main()
{
	Accumulator acc(10);
	acc.add(5).add(10).add(20);
	cout << "ÃÑ ÇÕÀº : " << acc.get() << endl;
}