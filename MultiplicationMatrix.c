/*
	C Programming Lab
	03-08-2016
	1BCA - B 1641121
	Dong Sung KIM

	7. Multiplication of two Matrixs
*/

#include <stdio.h>

int main(void)
{
	int mat1[10][10] = {0, };
	int mat2[10][10] = {0, };
	int mat3[10][10] = {0, };

	int ROW1 = 0, COL1 = 0;
	int ROW2 = 0, COL2 = 0;
	int i, j, k;
	int sum = 0;

	printf("Enter the number of first MAtrix ROW and COLUMN : ");
	scanf("%d %d", &ROW1, &COL1);
	printf("Enter the number of second MAtrix ROW and COLUMN : ");
	scanf("%d %d", &ROW2, &COL2);

	if (COL1 != ROW2)
	{
		printf("CANNOT MULTIPLY.\n");
		return 0;
	}

	printf("Enter the values for matrix1.\n");
	for (i = 0; i < ROW1; i++)
	{
		for (j = 0; j < COL1; j++)
		{
			scanf("%d", &mat1[i][j]);
		}
	}

	printf("Enter the values for matrix2.\n");
	for (i = 0; i < ROW2; i++)
	{
		for (j = 0; j < COL2; j++)
		{
			scanf("%d", &mat2[i][j]);
		}
	}

	/*
		[ a1 a2 ] * [ b1 b2 ] = [ (a1*b1+a2*b3) (a1*b2+a2*b4) ]
		[ a3 a4 ]   [ b3 b4 ] = [ (a3*b1+a4*b3) (a3*b2+a4*b4) ]

		f[0][0] f[0][1] * s[0][0] s[0][1] = ( f[0][0]*s[0][0]+f[0][1]*s[1][0]) (f[0][0]*s[0][1]+f[0][1]*s[1][1]) )
		f[1][0] f[1][1]   s[1][0] s[1][1]   ( f[1][0]*s[0][0]+f[1][1]*s[1][0]) (f[1][0]*s[0][1]+f[1][1]*s[1][1]) )

		We can find col of first matrix and row of second matrix is same.
		We can usevariable k for looping the row of second matrix.

		
	*/



	// Main Algorithm
	for (i = 0; i < ROW1; i++)							// i for the loop of ROW1
	{
		for (j = 0; j < COL1; j++)						// j for the loop of COL1
		{
			
			for (k = 0; k < ROW2; k++)					// k for the loop of ROW2
			{
				sum = sum + mat1[i][k] * mat2[k][j];	// get sum of each term
			}
			mat3[i][j] = sum;
			sum = 0;
		}
	}

	printf("Reslut of Multiplication is :\n");
	for (i = 0; i < ROW2; i++)
	{
		for (j = 0; j < COL2; j++)
		{
			printf("%d\t", mat3[i][j]);
		}
		printf("\n");
	}

	return 0;
}