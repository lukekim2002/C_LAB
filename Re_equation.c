//
//  main.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 18..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>
#include <math.h>


typedef struct _root
{
    float realNum;
    float iNum;
} Root;


Root x1;
Root x2;

typedef enum RootState
{
    RealRoot,
    MultipleRoot,
    ImaginaryRoot
} State;

float getD(float a, float b, float c);
void getRealRoot(float D, float a, float b, float c);
void getMultipleRoot(float D, float a, float b, float c);
void getImaginaryRoot(float D, float a, float b, float c);

int main()
{
    float x = 0, y = 0, z = 0;
    float D = 0;                    // Discrement
    State chk;                    // Check the state of Root (real, multiple, imaginary)
    
    printf("enter the constant of the variables : ");
    scanf("%f %f %f", &x, &y, &z);
    
    if(x == 0) { printf("Constant a out of bound!\n\n"); return -1;}
    
    D = getD(x, y, z);
    
    if(D > 0)
    {
        chk = RealRoot;
    }
    else if(D == 0)
    {
        chk = MultipleRoot;
    }
    else
    {
        chk = ImaginaryRoot;
    }
    
    printf("\n");
    switch(chk)
    {
        case RealRoot:
            getRealRoot(D, x, y, z);
            printf("x1 = %.1f\n", x1.realNum);
            printf("x2 = %.1f\n", x2.realNum);
            break;
            
        case MultipleRoot:
            getMultipleRoot(D, x, y, z);
            printf("x1 = x2 = %.1f\n", x1.realNum);
            break;
            
        case ImaginaryRoot:
            getImaginaryRoot(D, x, y, z);
            printf("x1 = %.1f + %.1fi\n", x1.realNum, x1.iNum);
            printf("x2 = %.1f + %.1fi\n", x2.realNum, x2.iNum);
            break;
            
        default:
            printf("Error!\n");
            return -1;
            
    }
    
    printf("\n\n");
    
    return 0;
}


float getD(float a, float b, float c)
{
    return ( b*b - (4*a*c) );
}


void getRealRoot(float D, float a, float b, float c)
{
    x1.realNum = (-b + sqrt(D)) / (2*a);
    x2.realNum = (-b - sqrt(D)) / (2*a);
    x1.iNum = x2.iNum = 0;
}

void getMultipleRoot(float D, float a, float b, float c)
{
    x1.realNum = x2.realNum = (-b) / (2*a);
    x1.iNum = x2.iNum = 0;
}

void getImaginaryRoot(float D, float a, float b, float c)
{
    x1.realNum = x2.realNum = (-b) / (2*a);
    x1.iNum = sqrt(-D) / (2*a);
    x2.iNum = -sqrt(-D) / (2*a);
}


