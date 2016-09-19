//
//  Re_StdDB.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 19..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct StudentInfo
{
    int rollNO;
    char Name[30];
    char Class[30];
    int Mark1;
    int Mark2;
    int avg;
} Student;

typedef enum _state
{
    DisplayState = 1,
    InsertState = 2,
    DeleteState = 3,
    SearchState = 4,
    ExitState = 5
} State;

void Display(Student *, int n);
void Get(Student *, int n);
void Insert(Student **, int n);
void Delete(Student **, int n, int f, int no, char *);
void Search(Student *, int n, int f, int no, char *);

int main()
{
    Student *Sptr;
    int num;            // number of student
    int c;              // control the input operation
    int flag = 0;       // flag to find by number or name
    int rollNo = 0;
    char Name[30];
    
    printf("Enter the total number of student : ");
    scanf("%d", &num);
    
    Sptr = (Student *)malloc(num * sizeof(Student));
    
    Get(Sptr, num);
    
    while(1)
    {
        printf("-----------------------------------------------------------------------------------------------------------------------");
        printf("\n");
        printf("\nEnter the Operation.\n\n1.Display\n2.Insert\n3.Delete\n4.Search\n5.Exit\n\n");
        scanf("%d", &c);
        
        switch(c)
        {
            case DisplayState:
                
                Display(Sptr, num);
                break;
                
            case InsertState:
                
                Insert(&Sptr, num);
                num++;
                
                break;
                
            case DeleteState:
                
                printf("Delete by Roll Number(1) or Name(2) ? ");
                scanf("%d", &flag);
                
                if(flag != 1 && flag != 2)
                {
                    printf("Flag out of Bound!\n");
                    break;
                }
                else
                {
                    if(flag == 1)
                    {
                        printf("Enter the roll number : ");
                        scanf("%d", &rollNo);
                    }
                    else
                    {
                        printf("Enter the name : ");
                        scanf("%s", Name);
                    }
                }
                
                Delete(&Sptr, num, flag, rollNo, Name);
                num--;
                break;
                
            case SearchState:
                
                printf("Search by Roll Number(1) or Name(2) ? ");
                scanf("%d", &flag);
                
                if(flag != 1 && flag != 2)
                {
                    printf("Flag out of Bound!\n");
                    break;
                }
                else
                {
                    if(flag == 1)
                    {
                        printf("Enter the roll number : ");
                        scanf("%d", &rollNo);
                    }
                    else
                    {
                        printf("Enter the name : ");
                        scanf("%s", Name);
                    }
                }
                
                Search(Sptr, num, flag, rollNo, Name);
                
                break;
                
            case ExitState:
                
                printf("\n");
                printf("-----------------------------------------------------------------------------------------------------------------------");
                printf("\nExit!\n\n");
                
                free(Sptr);
                
                return 0;
                
            default:
                
                printf("Enter the correct operation.\n");
                continue;
        }
    }
    
    return 0;
}


// Display the member of structures
void Display(Student *ptr, int n)
{
    printf("\nDisplay\n\n");
    
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("Roll Number\t|\tName\t\t|\tCourse\t\t|\tMark1\t\t|\tMark2\t\t|\tAverage\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    
    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%d", (ptr+i)->rollNO, (ptr+i)->Name, (ptr+i)->Class, (ptr+i)->Mark1, (ptr+i)->Mark2, (ptr+i)->avg);
        printf("\n");
    }
    
    printf("\n\n");
}

// Get the member of structure from user
void Get(Student *ptr, int n)
{
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter the Roll number : ");
        scanf("%d", &(ptr+i)->rollNO);
        
        printf("Enter the Student Name : ");
        scanf("%s", (ptr+i)->Name);
        
        printf("Enter the Course : ");
        scanf("%s", (ptr+i)->Class);
        
        printf("Enter the Mark1 : ");
        scanf("%d", &(ptr+i)->Mark1);
        
        printf("Enter the Mark2 : ");
        scanf("%d", &(ptr+i)->Mark2);
        
        (ptr+i)->avg = ( (ptr+i)->Mark1 + (ptr+i)->Mark2 ) / 2;
        
        printf("\n");
    }
    printf("\n");
    
}

// insert new structure from back
void Insert(Student **ptr, int n)
{
    if(ptr == NULL)
    {
        printf("Pointer Error!\n");
        return;
    }
    
    *ptr = realloc(*ptr, (n+1) * sizeof(Student));
    
    printf("Enter the Roll number : ");
    scanf("%d", &(*ptr+n)->rollNO);
    
    printf("Enter the Student Name : ");
    scanf("%s", (*ptr+n)->Name);
    
    printf("Enter the Course : ");
    scanf("%s", (*ptr+n)->Class);
    
    printf("Enter the Mark1 : ");
    scanf("%d", &(*ptr+n)->Mark1);
    
    printf("Enter the Mark2 : ");
    scanf("%d", &(*ptr+n)->Mark2);
    
    (*ptr+n)->avg = ( (*ptr+n)->Mark1 + (*ptr+n)->Mark2 ) / 2;
    
    printf("\n");
    
}

// Delete the structure by number or name
void Delete(Student **ptr, int n, int f, int no, char *string)
{
    Student *temp;
    int p;
    
    if(f == 1)  // find by number
    {
        for(int i = 0; i < n; i++)
        {
            if( (*ptr+i)->rollNO == no)
            {
                p = i;      // get position
                printf("%d", p);
                break;
            }
            if(i == n)
            {
                printf("Cannot find.\n");
                return;
            }
        }
        
    }
    else if(f == 2)     // find by name
    {
        for(int i = 0; i < n; i++)
        {
            if( strcmp( (*ptr+i)->Name, string) == 0 )
            {
                p = i;      // get position
                printf("%d", p);
                break;
            }
            if(i == n)
            {
                printf("Cannot find.\n");
                return;
            }
        }
    }
    else
    {
        printf("Cannot Find.\n");
        return;
    }
    
    
    temp = (Student *)malloc( (n-1) * sizeof(Student));
    
    if(p != 0)
    {
        memmove(temp, *ptr, (p-1) * sizeof(Student));
    }
    if(p != (n-1) )
    {
        memmove(temp+p, *ptr+(p+1), (n-p-1) * sizeof(Student));
    }
    
    //Display(temp, n-1);
    
    *ptr = realloc(*ptr, (n-1) * sizeof(Student));
    
    //free(*ptr);
    //*ptr = temp;
    
    memcpy(*ptr, temp, (n-1) * sizeof(Student));
    
    free(temp);
}

// Search the sturcture by number or name
void Search(Student *ptr, int n, int f, int no, char *string)
{
    int p;
    
    if(f == 1)
    {
        for(int i = 0; i < n; i++)
        {
            if( (ptr+i)->rollNO == no)
            {
                p = i;
                break;
            }
            if(i == n)
            {
                printf("Cannot find.\n");
                return;
            }
        }
        
    }
    else if(f == 2)
    {
        for(int i = 0; i < n; i++)
        {
            if( strcmp( (ptr+i)->Name, string) == 0)
            {
                p = i;
                break;
            }
            if(i == n)
            {
                printf("Cannot find.\n");
                return;
            }
        }
    }
    else
    {
        printf("Cannot Find.\n");
        return;
    }
    
    
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\nSearch result is \n");
    printf("%d\t\t\t%s\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%d", (ptr+p)->rollNO, (ptr+p)->Name, (ptr+p)->Class, (ptr+p)->Mark1, (ptr+p)->Mark2, (ptr+p)->avg);
    printf("\n");
}
















