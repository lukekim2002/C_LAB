#include <stdio.h>
#include <string.h>

typedef enum
{
	false,
	true
} bool;

bool isPalindrome(int start, int end, char * string)
{
	if(string == NULL || start < 0 || end < 0)
	{
		printf("Invalid!");
		return false;
	}

	if(start >= end)
		return true;
	if(string[start] == string[end])
		return isPalindrome(start+1, end-1, string);

	return false;
}

int main(void)
{
	char string[30] = {'\0',};
	int length, start, end;

	printf("Enter the string : ");
	scanf("%s", string);

	length = strlen(string);
	start = 0; end = length - 1;

	if(isPalindrome(0, strlen(string) - 1, string) )
		printf("This string is a Palindrome.");
	else
		printf("This string is not a Palindrome.");

	printf("\n\n");

	return 0;
}
