// ��� ����
#include <stdio.h>

// ���������� (Forward Declaration)
int bigNum(int num1, int num2);

int main()
{
	// ���� ����
	// �ڷ��� ����
	int		num1 = 10, num2 = 20, empty = 0;
	double	num3 = 30.0;
	char	letter = 'A';

	// ������ ���ο� �� �ֱ�
	empty = num1 + num2;
	printf("result = %d\n", empty);

	printf("Bigger Number : %d", bigNum(num1, num2));

}

// �� ū���� ��ȯ ���ִ� �Լ�
int bigNum(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}

	else if (num2 < num1)
	{
		return num2;
	}
}

