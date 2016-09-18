#include <stdio.h>
#include <string.h>

int main()
{
	char string[50];

	printf("\n\n");
	printf("Enter the string : ");
	gets(string);

	int i, n;
	n = strlen(string);

	int cntVowel = 0, cntCon = 0, cntSpace = 0;
	
	for(i = 0; i < n; i++)
	{
		if( string[i] == 'a' || string[i] == 'A' ||
			string[i] == 'e' || string[i] == 'E' ||
			string[i] == 'i' || string[i] == 'I' ||
			string[i] == 'o' || string[i] == 'O' ||
			string[i] == 'u' || string[i] == 'U' )
		{
			cntVowel++;
		}
		else if(string[i] == ' ' )
		{
			cntSpace++;
		}
		else
		{
			cntCon++;
		}
	}

	printf("\n\n%s\n", string);

	printf("Vowels\t|\tConsonants\t|\tSpace\n");
	printf("%d\t|\t%d\t\t|\t%d", cntVowel, cntCon, cntSpace);

	printf("\n\n");

	return 0;
}
