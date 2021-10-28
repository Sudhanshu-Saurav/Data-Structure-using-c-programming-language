#include <math.h>
#include <stdio.h>
int main()
{
	int i;
    printf ("The numbers which are multiple of 3 from N=0 to N< 100 are :\n");
	for( i=0 ; i<100; i++)
    {
        if (i%3==0)
        {
           printf("\t %i",i);
        }
    }
    printf("\nNow the number that are divisible by 3 and also divisible by 5 are :\n");
    int sum=0;
    for( i=0 ; i<100; i++)
    {
        if (i%3==0 && i%5==0)
        {
           printf("\t %i",i);
           sum=sum+i;
        }
    }
 printf ("\nSum of the numbers divisible by both 3 and 5 is : %i", sum);
 return 0;
}
