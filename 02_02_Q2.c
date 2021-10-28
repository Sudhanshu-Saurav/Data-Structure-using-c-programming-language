#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	int ID;
	char name[20];
	char sex[6];
	float Q1,Q2,mid,final,total;
};

static int n;
void accept(struct student[]);
void add(struct student[]);
void erase(struct student[],int);
void update(struct student[],int);
void display(struct student[]);
int avg(struct student[],int);
void max(struct student[],int);
void min(struct student[],int);
int search(struct student[],int);

int main()
{
	struct student data[20];
	int choice;
    printf("\n\n\t\t\t\t\xB2\xB2\xB2 Student database system \xB2\xB2\xB2\n\n");
    printf("\n\n\t\t\tNumber of students records you want to enter : ");
    scanf("%d", &n);
    accept(data);
    
    do
    {
		system("cls");
    	system("color A");
    	line10:
        printf("\n\xB2\xB2\xB2Student database system Menu\xB2\xB2\xB2\n\n");
        printf("Press 1 to add new records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to update a record.\n");
        printf("Press 4 to delete a record.\n");
        printf("Press 5 to display all the record.\n");
        printf("Press 6 to calculate average of all the marks.\n");
        printf("Press 7 to know the student who got maximum marks.\n");
        printf("Press 8 to know the student who got minimum marks.\n");
		printf("Press 0 to exit\n");
        printf("\nEnter choice(0-9) : ");
        scanf("%d", &choice);
        switch (choice)
        {
        	
            case 1:
            	 //accept(data);
            	add(data);
            	goto line10;
            case 2:
            	search(data,n);
            	goto line10;
            case 3:
                update(data,n);
                goto line10;
            case 4:
            	erase(data,n);
            	goto line10;            
			case 5:
            	display(data);
            	goto line10;
            case 6:
            	avg(data,n);
            	goto line10;
            case 7:
            	max(data,n);
            	goto line10;
            case 8:
            	min(data,n);
            	goto line10;
            
            case 0:
            	exit(0);
            	break;
            default:
            	printf ("\n\nInvalid Choice\n\n");
            	goto line10;
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct student list[80])
{
//	printf("\n\n\t\t\tNumber of students records you want to enter : ");
//    scanf("%d", &n);
	int i;
	for (i=0;i<n;i++)
	{
		printf("\nEnter data for student No : %d\n\n\n", i + 1);
	
		printf("Enter the student ID : ");
		scanf ("%i",&list[i].ID);
		
		printf ("Enter student name : ");
		fflush(stdin);
		gets(list[i].name);
		
		printf ("Enter Gender (Male/Female) : ");
		gets(list[i].sex);
				
		Quiz1:
		printf ("Enter Your Scores of Quiz 1 (Out of 10) : ");
		scanf ("%f",&list[i].Q1);
		if (list[i].Q1>10)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto Quiz1;
		}
		
		Quiz2:
		printf ("Enter Your Scores of Quiz 2 (Out of 10) : ");
		scanf ("%f",&list[i].Q2);
		if (list[i].Q2>10)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto Quiz2;
		}
	
		midterm:	
		printf ("Enter Your Scores of Mid Term Score (Out of 30) : ");
		scanf ("%f",&list[i].mid);
		if (list[i].mid>30)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto midterm;
		}
		
		final:
		printf ("Enter Your Scores of Final Score (Out of 50) : ");
		scanf ("%f",&list[i].final);
		if (list[i].final>50)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto final;
		}
		
		printf ("Your Scores of Total Score Out of 100 is %0.2f\n\n\n",list[i].total=(list[i].Q1+list[i].Q2+list[i].mid+list[i].final));
	
	}
	system("pause");
}

void add(struct student list[80])
{
	int num,i;
	printf("\nHow many students do you want to add : ");
	scanf("%d",&num);
	for (i=n;i<(n+num);i++)
	{
		printf("\nEnter data for student No : %d\n\n\n", i + 1);
	
		printf("Enter the student ID : ");
		scanf ("%i",&list[i].ID);
		
		printf ("Enter student name : ");
		fflush(stdin);
		gets(list[i].name);
		
		printf ("Enter Gender (Male/Female) : ");
		gets(list[i].sex);
				
		Quiz1:
		printf ("Enter Your Scores of Quiz 1 (Out of 10) : ");
		scanf ("%f",&list[i].Q1);
		if (list[i].Q1>10)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto Quiz1;
		}
		
		Quiz2:
		printf ("Enter Your Scores of Quiz 2 (Out of 10) : ");
		scanf ("%f",&list[i].Q2);
		if (list[i].Q2>10)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto Quiz2;
		}
	
		midterm:	
		printf ("Enter Your Scores of Mid Term Score (Out of 30) : ");
		scanf ("%f",&list[i].mid);
		if (list[i].mid>30)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto midterm;
		}
		
		final:
		printf ("Enter Your Scores of Final Score (Out of 50) : ");
		scanf ("%f",&list[i].final);
		if (list[i].final>50)
		{
			printf ("\nInvalid marks! Please enter valid marks\n\n");
			goto final;
		}
		
		printf ("Your Scores of Total Score Out of 100 is %0.2f\n\n\n",list[i].total=(list[i].Q1+list[i].Q2+list[i].mid+list[i].final));	
	}
	n=n+num;
	system("pause");
}

int search(struct student list[80],int s)
{
	int i,k,count=0;
	printf("\nEnter the id of the student : ");
	scanf("%d",&k);
	for(i=0;i<s;i++)
	{  
		if(list[i].ID==k)
		{	count++;
			printf("\n\n ID \t Name \t Gender \t Total\n");
			printf("\n %i \t %s \t %s \t\t %0.2f \n\n",list[i].ID,list[i].name,list[i].sex,list[i].total);
		}
	}
	if (count==0)
	{
		printf("\n Wrong Choice \n");
		system("pause");
	}
	
}


void update(struct student list[80],int s)
{
	int i,k,count=0;
	printf(" \nEnter the id of the student whose records need to be updated : ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(list[i].ID==k)
		{
			count++;
			printf("\nEnter the updated ID : ");
			scanf("%i",&list[i].ID);
			printf("\nEnter the updated Name : ");
			scanf("%s",&list[i].name);
			printf("\nEnter the updated Gender (Male/Female) : ");
			scanf("%s",&list[i].sex);			
			
			Quiz1:
			printf ("Enter Your Scores of Quiz 1 (Out of 10) : ");
			scanf ("%f",&list[i].Q1);
			if (list[i].Q1>10)
			{
				printf ("\nInvalid marks! Please enter valid marks\n\n");
				goto Quiz1;
			}
			
			Quiz2:
			printf ("Enter Your Scores of Quiz 2 (Out of 10) : ");
			scanf ("%f",&list[i].Q2);
			if (list[i].Q2>10)
			{
				printf ("\nInvalid marks! Please enter valid marks\n\n");
				goto Quiz2;
			}
		
			midterm:	
			printf ("Enter Your Scores of Mid Term Score (Out of 30) : ");
			scanf ("%f",&list[i].mid);
			if (list[i].mid>30)
			{
				printf ("\nInvalid marks! Please enter valid marks\n\n");
				goto midterm;
			}
			
			final:
			printf ("Enter Your Scores of Final Score (Out of 50) : ");
			scanf ("%f",&list[i].final);
			if (list[i].final>50)
			{
				printf ("\nInvalid marks! Please enter valid marks\n\n");
				goto final;
			}
			
			
			list[i].total=list[i].mid+list[i].final+list[i].Q1+list[i].Q2;
			printf("\nRecord updated successfully \n\n");
			system("pause");
		}
	}
	if(count==0)
	{
		printf("\n Wrong id!!!");
		system("pause");
	}
	
}

void erase(struct student list[80],int s)
{
	int k,i,count=0,j;
	printf("\nEnter the id of the student whose record needs to be deleted : ");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(list[i].ID==k)
		{	count++;
			--n;
			for(j=i;j<n;j++)
			{
				list[j].ID=list[j+1].ID;
				strcpy(list[j].name,list[j+1].name);
				strcpy(list[j].sex,list[j+1].sex);
				list[j].Q1=list[j+1].Q1;
				list[j].Q2=list[j+1].Q2;
				list[j].mid=list[j+1].mid;
				list[j].final=list[j+1].final;
				list[j].total=list[j+1].total;
			}
			printf("\nRecord deleted successfully \n\n");
			system("pause");
		}
	}
	if(count==0)
	{
		printf("\n Wrong id!!! ");
		system("pause");
	}
		
}

void display(struct student list[80])
{
	int i;
	printf("\n\nID\tName\t\tGender\t\tQuiz-1\t\tQuiz-2\t\tMid-Term\tFinal\tTotal\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t%s\t\t%s\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\t%0.2f\n\n",list[i].ID,
		list[i].name,list[i].sex,list[i].Q1,list[i].Q2,list[i].mid,list[i].final,list[i].total);
	}
	system("pause");
}
int avg(struct student list[80],int s)
{
	int i,k,count=0;
	float avg;
	printf(" \nEnter the student id : ");
	scanf("%d",&k);
	for(i=0;i<s;i++)
	{	
		if(list[i].ID==k)
		{	
			count++;
			avg=(list[i].total)/4;
			printf("\nThe average marks of the student is %.2f \n\n",avg);
		}
	}
	if(count==0)
	{
		printf("\n Wrong id!!!\n\n");
	}
	system("pause");

}
void max(struct student list[80],int s)
{
	int i,j,count=0;
	float max;
	max=list[0].total;
	for(i=1;i<s;i++)
	{
		if(list[i].total>max)
		{
			max=list[i].total;
			j=i;
			count++;
		}
	}
		if(count==0)
		{
			j=0;
		}
	printf(" \nThe student who got the max marks is ");
	printf("\nID \t Name \t Gender \t Total");
	printf("\n%d \t %s \t %s \t %0.2f \n\n",list[j].ID,list[j].name,list[j].sex,list[j].total);
	system("pause");
}
void min(struct student list[80],int s)
{
	int i,j,count=0;
	float min;
	min=list[0].total;
	for(i=1;i<s;i++)
	{
		if(list[i].total<min)
		{
			min=list[i].total;
			j=i;
			count++;
		}
	}
		if(count==0)
		{
			j=0;
		}
	printf("\nThe student who got the min marks is ");
	printf("\nID \t Name \t Gender \t Total");
	printf("\n%d \t %s \t %s \t %0.2f \n\n",list[j].ID,list[j].name,list[j].sex,list[j].total);
	system("pause");;
}


