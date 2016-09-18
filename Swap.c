#include <stdio.h>

void Swap(int *x, int *y);

int main(void)
{
	int x, y;

	printf("Enter two numbers : ");
	scanf("%d %d", &x, &y);

	printf("Before Swap,\tx : %d\ty : %d\n", x, y);

	Swap(&x, &y);

	printf("After Swap,\tx : %d\ty : %d\n", x, y);

	return 0;
}

void Swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
