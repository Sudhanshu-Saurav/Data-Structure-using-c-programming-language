#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int i,n,j;
	char CollegePreference[50],BranchPreference[50];
	char college[][20]={"NIT","IIT","IIIT","KIIT","MIT"};
	char branch[][20]={"Statistics","Computer Science","Physics","Chemistry"};
	int seats[5][4]={{8,1,2,10},{7,0,5,5},{8,3,5,8},{5,2,7,9},{4,0,0,3}};
	
	printf("\n\nThe vacent seats are displayed as follows : \n");
	printf("  \t Statistics\t Computer Science\t\t Physics\t Chemistry\n");
	
	
	for(i=0;i<5;i++)
	{
		printf("%s",college[i]);
		for(j=0;j<4;j++)
		printf("\t %i \t\t",seats[i][j]);
		printf ("\n");
	}	
		printf ("\n\nEnter your college preference from the seat matrix given below\n1.NIT\n2.IIT\n3.IIIT\n4.KIIT\n5.MIT\n");
		gets(CollegePreference);
		printf ("Enter your branch preference from the seat matrix given below\n1.Statistics\n2.Computer Science\n3.Physics\n4.Chemistry\n");
		gets(BranchPreference);
	
	for(i=0;i<5;i++)
	{
		if(strcmp(college[i],CollegePreference)==0)
		break;
	}
	for(j=0;j<4;j++)
	{
		if(strcmp(branch[j],BranchPreference)==0)
		break;
	}
	if (seats[i][j]!=0)
	{
		printf ("\n\nCongratulations! You have secured your seat of %s branch in %s college",branch[j],college[i]);
		seats[i][j]-=1;
	}
	else
		printf ("\n\nSorry! You have not secured any seat.\nBetter luck next time.\n");
		printf("\n\nThe vacent seats are displayed as follows : \n");
		printf("  \t Statistics\t Computer Science\t\t Physics\t Chemistry\n");
		
	for(i=0;i<5;i++)
	{
		printf("%s",college[i]);
		for(j=0;j<4;j++)
		printf("\t %i \t\t",seats[i][j]);
		printf ("\n");
	}
}
