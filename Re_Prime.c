#include <stdio.h>

typedef enum
{
	false,
	true
} bool;

int main(void)
{
	int interval1, interval2;
	bool isPrime;

	int i, j;

	printf("\n\n");
	scanf("%d %d", &interval1, &interval2);

	printf("Prime numbers between %d to %d are : ", interval1, interval2);

	for( i = interval1; i <= interval2; i++)
	{
		if(i == 1)
			continue;

		isPrime = true;

		for(j = 2; j <= i/2; j++)
		{
			if(i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if(isPrime)
			printf("%d ", i);
	}

	printf("\n\n");

	return 0;
}
