#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
	int empNo;
	char empName[15];
	char Dept[15];
	float salary;
} emp;

int main()
{
	emp *ptr;
	int i, n;

	printf("\n\nEnter the number of employees : ");
	scanf("%d", &n);

	ptr = (emp *)malloc(n * sizeof(emp) );

	for(i = 0; i < n; i++)
	{
		printf("Enter empNo, empName, depName, Salary of %dth employee.\n", i+1);
		scanf("%d %s %s %f", &(ptr+i)->empNo, (ptr+i)->empName, (ptr+i)->Dept, &(ptr+i)->salary);
	}

	printf("\nDisplay : \n\n");

	for(i = 0; i < n; i++)
	{
		printf("No : %d\tName : %s\tDepartment : %s\tSalary : %.1f\n",
				(ptr+i)->empNo, (ptr+i)->empName, (ptr+i)->Dept, (ptr+i)->salary );
	}

	free(ptr);

	printf("\n\n\n\n\n");

	return 0;
}
