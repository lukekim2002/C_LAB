#include <stdio.h>

#define BIG(temp1,temp2) ((temp1 > temp2) ? (temp1) : (temp2))
#define PRINT(temp1,temp2) (printf("1. %d 2. %d\n", temp1, temp2))

int main(void)
{
	int a, b, c;

	printf("Enter the three numbers : ");
	scanf("%d %d %d", &a, &b, &c);

	int temp1 = BIG(a, b);
	int temp2 = BIG(b, c);

	if(BIG(temp1, temp2) == temp1)
		PRINT(temp1, temp2);
	else
		PRINT(temp2, temp1);

	printf("\n\n");

	return 0;
}
