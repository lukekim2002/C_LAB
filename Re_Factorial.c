//
//  Re_Factorial.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 18..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>

unsigned long combination(int n, int r);
unsigned long factorial(int n);

int main()
{
    int num1 = 0, num2 = 0;
    
    printf("Enter the total number of objects : ");
    scanf("%d", &num1);
    printf("Enter the possible number of combination of objects : ");
    scanf("%d", &num2);
    
    printf("%dC%d is %lu", num1, num2, combination(num1, num2));
    
    printf("\n\n");
    
    return 0;
}

unsigned long factorial(int n)
{
    if(n >= 1)
        return n * factorial(n-1);
    else
        return 1;
}

unsigned long combination(int n, int r)
{
    return factorial(n) / (factorial(r)*factorial(n-r));
}