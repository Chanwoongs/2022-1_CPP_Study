#include <iostream>

using namespace std;

// forwoard declaration
class Rect;
bool equals(Rect r, Rect s);

class RectManager1
{
public:
	bool equals(Rect r, Rect s);
	//void copy(Rect& dest, Rect& src);
};

class RectManager2
{
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect
{
public:
	Rect(int width, int height)
	{
		this->width = width;
		this->height = height;
	}
	~Rect();

	friend bool equals(Rect r, Rect s); // �ܺ� �Լ��� friend�� ����
	friend bool RectManager1::equals(Rect r, Rect s); // �ٸ� Ŭ������ �Լ��� friend�� ����
	friend RectManager2; // �ٸ� Ŭ���� ��ü�� friend�� ����

	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int width;
	int height;
};

Rect::~Rect()
{
}

// 1. Ŭ���� �ܺο� �ۼ��� �Լ��� ������� ����
bool equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}

// 2. �ٸ� Ŭ������ ��� �Լ��� ������� ����
bool RectManager1::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}
/* equals �Լ��� friend �̱� ������ copy �Լ��� rect�� private ����� �������� ���Ѵ�.
void RectManager1::copy(Rect& dest, Rect& src)
{
	dest.width = src.width;
	dest.height = src.height;
}
*/

// 3. �ٸ� Ŭ���� ��ü�� ������� ����
bool RectManager2::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}
// src�� dest�� ����
void RectManager2::copy(Rect& dest, Rect& src)
{
	dest.width = src.width;
	dest.height = src.height;
}


int main()
{
	// Case 1
	cout << "Case 1" << endl;
	Rect a(3, 4), b(4, 5), c(3, 4);

	if (equals(a, b))
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	if (equals(a, c))
	{
		cout << "a == c" << endl;
	}
	else
	{
		cout << "a != c" << endl;
	}
	cout << endl;

	// Case 2
	cout << "Case 2" << endl;
	RectManager1 RM1;

	//RM1.copy(a, b);
	if (RM1.equals(a, b))
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	if (RM1.equals(a, c))
	{
		cout << "a == c" << endl;
	}
	else
	{
		cout << "a != c" << endl;
	}
	cout << endl;

	// Case 3
	cout << "Case 3" << endl;
	RectManager2 RM2;

	RM2.copy(a, b);
	if (RM2.equals(a, b))
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}
}