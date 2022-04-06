// 헤더 파일
#include <stdio.h>

// 전방 선언 (Forward Declaration)
int getBiggerNum(int num1, int num2);

int main()
{
	// 변수 선언
	// 자료형 변수
	int		num1 = 10, num2 = 20, empty = 0;
	double	num3 = 30.0;
	char	letter = 'A';

	// 변수에 새로운 값 넣기
	empty = num1 + num2;
	printf("result = %d\n", empty);

	// 함수 호출
	printf("Bigger Number : %d", getBiggerNum(num1, num2));

}

// 함수 정의
int getBiggerNum(int num1, int num2)
{
	if (num1 >= num2)
	{
		return num1;
	}

	else if (num2 < num1)
	{
		return num2;
	}
}

