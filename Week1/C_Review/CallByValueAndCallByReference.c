#include <stdio.h>

void swapValue(int num1, int num2);
void swapReference(int *num1, int *num2);

int main()
{
	int a = 10, b = 20;

	swapValue(a, b);

	printf("num1 = %d, num2 = %d\n\n", a, b);

	swapReference(&a, &b);

	printf("num1 = %d, num2 = %d\n\n", a, b);
}

// Call by Value 
void swapValue(int num1, int num2) // 값을 인자로 전달
{
	int temp;

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("num1 = %d, num2 = %d\n\n", num1, num2);
}

// Call by Reference
void swapReference(int *num1, int *num2) // 포인터 값을 인자로 전달
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;

	printf("num1 = %d, num2 = %d\n\n", *num1, *num2);
}