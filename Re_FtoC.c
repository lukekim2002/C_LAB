#include <stdio.h>

#define F_TO_C(temp) ((temp-32)*(float)(5.0/9.0))

int main(void)
{
	float tempF, tempC;

	printf("Enter the Fahrenwheit temperature : ");
	scanf("%f", &tempF);

	tempC = F_TO_C(tempF);

	printf("The Celcius temperature is : %.2f", tempC);
	printf("\n\n");

	return 0;
}
