#include <stdio.h>

int factorial(int n)
{
	if(n >= 1)
		return n * factorial(n-1);
	else
		return 1;
}

int main(void)
{
	int num;

	printf("Enter the number to get factorial : ");
	scanf("%d", &num);

	printf("%d Factorial is %d\n", num, factorial(num));

	printf("\n\n\n");

	return 0;
}
