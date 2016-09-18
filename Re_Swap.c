//
//  Re_Swap.c
//  CLab
//
//  Created by 김동성 on 2016. 9. 19..
//  Copyright © 2016년 김동성. All rights reserved.
//

#include <stdio.h>

void swap(int *a, int *b);
void BubbleSort(int [], int);

int main()
{
    int n;
    
    printf("Enter the size of array : ");
    scanf("%d", &n);
    
    int array[n];
    
    for(int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    printf("\nBefore Sort :\n");
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
    
    BubbleSort(array, n);
    
    printf("\nAfter Sort :\n");
    for(int i = 0; i < n; i++)
        printf("%d ", array[i]);
    
    printf("\n\n");
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int arr[], int n)
{
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}