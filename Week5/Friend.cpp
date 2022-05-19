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

	friend bool equals(Rect r, Rect s); // 외부 함수를 friend로 선언
	friend bool RectManager1::equals(Rect r, Rect s); // 다른 클래스의 함수를 friend로 선언
	friend RectManager2; // 다른 클래스 전체를 friend로 선언

	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int width;
	int height;
};

Rect::~Rect()
{
}

// 1. 클래스 외부에 작성된 함수를 프렌드로 선언
bool equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}

// 2. 다른 클래스의 멤버 함수를 프렌드로 선언
bool RectManager1::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}
/* equals 함수만 friend 이기 때문에 copy 함수는 rect의 private 멤버를 참조하지 못한다.
void RectManager1::copy(Rect& dest, Rect& src)
{
	dest.width = src.width;
	dest.height = src.height;
}
*/

// 3. 다른 클래스 전체를 프렌드로 선언
bool RectManager2::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
	{
		return true;
	}
	return false;
}
// src를 dest에 복사
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