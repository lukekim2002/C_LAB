#include <stdio.h>

#define SIZE(x) sizeof(x)*8

void pSigned(int);
void pUnsigned(int);

int main(void)
{
	printf("\nRange of int");
	pSigned(SIZE(int));

	printf("\nRange of unsigned int");
	pUnsigned(SIZE(unsigned int));

	printf("\nRange of char");
	pSigned(SIZE(char));

	printf("\nRange of unsigned char");
	pUnsigned(SIZE(unsigned char));

	printf("\nRange of short");
	pSigned(SIZE(short));

	printf("\nRange of unsigned short");
	pUnsigned(SIZE(unsigned short));

	printf("\nRange of float");
	pSigned(SIZE(float));

	printf("\nRange of unsigned long");
	pUnsigned(SIZE(unsigned long));

	printf("\n\n");

	return 0;
}

// print Signed range
void pSigned(int count)
{
	int min, max, pro;
	pro = 1;

	while(count != 1)
	{
		pro = pro << 1;
		count--;
	}

	min = ~pro;
	min = min + 1;
	max = pro - 1;

	printf("\n%d to %d", min, max);
}

// print Unsigned range
void pUnsigned(int count)
{
	unsigned int min, max, pro = 1;

	while(count != 0)
	{
		pro = pro << 1;
		count--;
	}

	min = 0;
	max = pro -1;

	printf("\n%u to %u", min, max);
}
