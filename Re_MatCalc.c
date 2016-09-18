//
//  Re_MatMultiplication.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 19..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>

#define MAXROW 10
#define MAXCOL 10


void getMat(float arr[][MAXCOL], int row, int col);
void printMat(float arr[][MAXCOL], int row, int col);
void addMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col);
void subtractMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col);
void multiplyMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col, int row2);
void divideMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col, int row2);


int main()
{
    float mat1[MAXROW][MAXCOL] = {0, };
    float mat2[MAXROW][MAXCOL] = {0, };
    float mat3[MAXROW][MAXCOL] = {0, };
    
    int ROW1 = 0, COL1 = 0;
    int ROW2 = 0, COL2 = 0;
    
    char c;
    
    printf("Enter the ROW and COLUMN of first Matrix : ");
    scanf("%d %d", &ROW1, &COL1);
    printf("Enter the ROW and COLUMN of second Matrix : ");
    scanf("%d %d", &ROW2, &COL2);
    
    if (COL1 != ROW2)
    {
        printf("CANNOT Calculate.\n");
        return -1;
    }
    
    printf("Enter the values for matrix1.\n");
    getMat( mat1, ROW1, COL1);
    
    printf("Enter the values for matrix2.\n");
    getMat(mat2, ROW2, COL2);
    
    
    fflush(stdin);
    printf("\nEnter the operation : ");
    while ( (c = getchar()) != '\n' && c != EOF ) { }
    c = getchar();
    
    switch (c)
    {
        case '+':
            addMat(mat1, mat2, mat3, ROW1, COL1);
            break;
        case '-':
            subtractMat(mat1, mat2, mat3, ROW1, COL1);
            break;
        case '*':
            multiplyMat(mat1, mat2, mat3, ROW1, COL2, ROW2);
            break;
        case '/':
            divideMat(mat1, mat2, mat3, ROW1, COL1, ROW2);
            break;
        default:
            printf("Operation Error!\n");
            return -1;
    }
    
    printMat(mat1, ROW1, COL1);
    printf("\t%c\n", c);
    printMat(mat2, ROW1, COL1);
    printf("\t=\n");
    printMat(mat3, ROW1, COL1);
    
    
    printf("\n\n");
    return 0;
}

// get input from user to 2d array
void getMat(float arr[][MAXCOL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
}

// print 2d array
void printMat(float arr[][MAXCOL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%.0f\t", arr[i][j]);
        }
        printf("\n");
    }
}

// add arr1 and arr2 to arr3
void addMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// subtract arr2 from arr1 to arr3
void subtractMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr3[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

// multiply arr1 and arr2 to arr3
void multiplyMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col, int row2)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            
            for(int k = 0; k < row2; k++)
            {
				// a[0][0] * b[0][0] + a[1][0] * b[0][1]
				// col of a = row of b = k
                arr3[i][j] = arr3[i][j] + arr1[i][k]*arr2[k][j];
            }
        }
    }
}
void divideMat(float arr1[][MAXCOL], float arr2[][MAXCOL], float arr3[][MAXCOL], int row, int col, int row2)
{
    float arrtemp[MAXROW][MAXCOL];
    
    int ad=1;
    int bc=1;
    float D;
    float temp;
    
    // copy arr2 to arrtemp
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arrtemp[i][j] = arr2[i][j];
        }
    }
    
	/* This part is get inversed array to divide */


    // get Diterminent (ad-bc)
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
            {
                ad = ad * arrtemp[i][i];
            }
            else
            {
                bc = bc * arrtemp[i][j];
            }
        }
    }
    
    D = ad-bc;
    if( D == 0)
    {
        printf("Cannot Divide!\n");
        return;
    }
    
    temp = arrtemp[0][0];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
            {
                arrtemp[i][i] = arrtemp[i+1][i+1];
                
                if( i+1 == row)
                    arrtemp[i][i] = temp;
                //temp = arrtemp[i][i];
            }
            else
            {
                arrtemp[i][j] = -arrtemp[i][j];
            }
        }
    }
    
    
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arrtemp[i][j] = (1/D) * arrtemp[i][j];
        }
    }
    
	// now mulpitply
    multiplyMat(arr1, arrtemp, arr3, row, col, row2);
}















