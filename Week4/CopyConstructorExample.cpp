#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
	Person(int id, char* name); // 기본 생성자
	Person(Person& person); // 복사 생성자
	~Person();
	void changeName(char* name) // 이름 변경
	{
		if (strlen(name) > strlen(this->name))
		{
			return; // 현재 name에 할당된 메모리보다 긴 이름으로 바꿀 수 없다.
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
	this->id = person.id; // id 값 복사
	int len = strlen(person.name); // name의 문자 개수
	this->name = new char[len + 1]; // name을 위한 공간 할당
	strcpy(this->name, person.name); // name의 문자열 복사
	cout << "복사 생성자 실행. 원본 객체의 이름 : " << this->name << endl;
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

	cout << "daughter 객체 생성 직후 ------------" << endl;
	father.show();
	daughter.show();

	char name1[] = "Chan";
	daughter.changeName(name1);

	cout << "daughter 이름을 Chan으로 변경한 후 ------------" << endl;	
	father.show();
	daughter.show();

	// 묵시적 복사 생성의 예
	// 1)
	Person son = father; // 복사 생성자 자동 호출
	// Person son(father); 과 같이 변환 한다.
	// Person son;
	// son = father; 과는 다르다.

	// 2)
	// void f(Person person){} 매개변수 person이 생성될 때 복사 생성자 호출
	// f(father); // 값에 의한 호출로 father 객체 전달

	// 3)
	// Person g() {
	// Person mother(2, "Jane");
	// return mother; // mother의 복사본을 생성하여 복사본 리턴, 사본이 만들어질 때 복사 생성자 호출
	// }
	// g();

}