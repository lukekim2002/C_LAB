#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentInfo4

{
	int rollNo;
	char Name[15];
	char Course[15];

} Student;

int main()
{
	Student *ptr;
	int i, n;
	int c;

	printf("\n\n");
	printf("Enter the number of students : ");
	scanf("%d", &n);

	if(n < 1)
	{
		printf("Number of student should be more than 1!!!\n");
		return 0;
	}
	ptr = (Student*)malloc(n * sizeof(Student));

	for(i = 0; i < n; i++)
	{
		printf("Enter roll Number, Name and Class of %dth Student.\n", i+1);
		scanf("%d %s %s", &(ptr+i)->rollNo, (ptr+i)->Name, (ptr+i)->Course );
	}

	while(1)
	{
		printf("\nEnter the operations.\n\n1.Display\n2.Insert\n3.Delete\n4.Exit\n\n");
		scanf("%d", &c);

		switch(c)
		{
			case 1:
				if(n <= 0)
				{
					printf("Number of student should be more than 1!!!\n");
					break;
				}

				for(i = 0; i < n; i++)
				{
					printf("RollNo. : %d\tName : %s\tCourse : %s\n",
							(ptr+i)->rollNo, (ptr+i)->Name, (ptr+i)->Course );
				}

				break;
			case 2:
				n++;
				ptr = realloc(ptr, n * sizeof(Student));
				
				printf("Enter roll Number, Name and Class of %dth Student.\n", n);
				scanf("%d %s %s", &(ptr+(n-1))->rollNo, (ptr+(n-1))->Name, (ptr+(n-1))->Course );
				
				break;
			case 3:
				if(n <= 0 )
				{
					printf("Number of student should be more than 1!!!\n");
					break;
				}
				n--;

				break;
			case 4:
				printf("Exit!\n\n");
				free(ptr);
				return 0;
			default:
				printf("Enter the correct input.\n");
				continue;
		}
			
	}


	return 0;
}
