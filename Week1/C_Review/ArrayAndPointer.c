#include <stdio.h>

int main()
{
	// �迭 ����
	int		numArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char	chArr[10];

	// �迭 �ʱ�ȭ
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
	// ������ ���� ����
	int* ptr = &num;	// num�� ����Ǿ� �ִ� �ּҸ� ptr�� ����
	int* pptr = &ptr;	// ptr�� ����Ǿ� �ִ� �ּҸ� pptr�� ����

	// �迭�� ���
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

	// �������� ��, �ּ� ���
	printf("num = %d\n", num);
	printf("&num = %p\n", &num);
	printf("ptr = %p\n", ptr);
	printf("*ptr = %d\n", *ptr);
	printf("pptr = %p\n", pptr);
	printf("*pptr = %p\n", *pptr);
}