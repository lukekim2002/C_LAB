#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Calc(char * string);

int main(void)
{
	char string[100];
	int result = 0;

	printf("Enter the expression : ");
	scanf("%s", string);

	result = Calc(string);

	printf("%s = %d", string, result);

	printf("\n\n");

	return 0;
}

int Calc(char * pstring)
{
	char *oper = "+-*/";	// group of operators that we use
	int pos;
	int n1 = 0;
	int n2 = 0;

	pos = strcspn(pstring , oper);
	n1 = atoi(pstring);
	n2 = atoi(pstring+pos+1);

	switch( *(pstring+pos) )
	{
		case '+':
			return n1 + n2;
		case '-':
			return n1 - n2;
		case '*':
			return n1 * n2;
		case '/':
			return n1 / n2;
		default:
			return 0;
	}

	return 0;
}
