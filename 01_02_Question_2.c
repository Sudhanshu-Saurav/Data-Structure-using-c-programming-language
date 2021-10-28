
//This programs gives the multiple of 7 as output and then print the sum of those numbers

#include <stdio.h>
int main()
{
int sum,n,i;
printf ("Enter the value upto which you want to print the multiple of 7 : ");
scanf ("%i",&n);
for( i=1 ; i<=n ; i++)
{
    if (i%7==0)
    {
        printf (" %i",i);
        sum+=i;
    }
}
   printf ("\nSum of these numbers is: %i", sum);
   return 0;
}
