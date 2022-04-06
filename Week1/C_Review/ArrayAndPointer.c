#include <stdio.h>

int main()
{
	// 배열 선언
	int		numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char	chArr[10];

	// 배열 초기화
	chArr[0] = 'a';
	chArr[1] = 'b';
	chArr[2] = 'c';
	chArr[3] = 'd';
	chArr[4] = 'e';
	chArr[5] = 'f';
	chArr[6] = 'g';
	chArr[7] = 'h';
	chArr[8] = 'i';

	int num = 10;
	// 포인터 변수 선언
	int* ptr = &num;	// num이 저장되어 있는 주소를 ptr에 저장
	int* pptr = &ptr;	// ptr이 저장되어 있는 주소를 pptr에 저장

	// 배열의 출력
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", numArr[i]);
	}
	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", chArr[i]);
	}
	printf("\n\n");

	// 포인터의 값, 주소 출력
	printf("num = %d\n", num);
	printf("&num = %p\n", &num);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %d\n", *ptr);
	printf("pptr = %p\n", pptr);
	printf("*pptr = %p\n", *pptr);
}