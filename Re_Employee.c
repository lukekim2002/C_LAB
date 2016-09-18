//
//  Re_Employee.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 19..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

typedef struct employee
{
    int empNo;
    char empName[30];
    char empDept[30];
    float salary;
} emp;


void getInfo(emp *, int n);
void PrintInfo(emp *, int n);

int main()
{
    emp *empPtr;
    int num;
    
    endl;endl;
    printf("Enter the number of employee : ");
    scanf("%d", &num);
    
    empPtr = (emp *)malloc(num * sizeof(emp));
    
    getInfo(empPtr, num);
    
    endl;endl;
    
    PrintInfo(empPtr, num);
    
    free(empPtr);
    
    endl;
    return 0;
}

void getInfo(emp *ptr, int n)
{
	endl;
    for(int i = 0; i < n; i++)
    {
        printf("Enter number : ");
        scanf("%d", &(ptr + i)->empNo);
        
        printf("Enter name : ");
        scanf("%s", (ptr + i)->empName);
        
        printf("Enter department : ");
        scanf("%s", (ptr + i)->empDept);
        
        printf("Enter salary : ");
        scanf("%f", &(ptr + i)->salary);
        
        printf("-----");
		endl;
	}
}

void PrintInfo(emp *ptr, int n)
{
    endl;
    printf("Number\t\t|\tName\t\t|\tDepartment\t|\tSalary");
    endl;
	printf("--------------------------------------------------------------------------------");
	endl;
    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t|\t%s\t\t|\t%s\t\t|\t%.1f", (ptr+i)->empNo, (ptr+i)->empName, (ptr+i)->empDept, (ptr+i)->salary);
        endl;
    }
    
    endl;
}


