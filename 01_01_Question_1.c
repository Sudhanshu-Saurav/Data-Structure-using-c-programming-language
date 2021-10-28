#include <stdio.h>
int main()
{
    char name[20];
    int i,age,BirthYear,leap=0,nonleap=0;
    unsigned long long int seconds;

    printf ("Enter your name: ");
    scanf ("%s", &name);
    printf("Enter your age :");
    scanf ("%i", &age);
    printf("your name is : %s \n", name);
    printf("your age is : %i \n", age);

    BirthYear = 2021-age;
    printf ("Your birth yaer is : %i \n",BirthYear);

    for ( i=BirthYear ; i<2021; i++ )
    {
        if(i%4==0)
        {
            leap++;
        }
        else
        {
            nonleap++;
        }
    }
    printf ("You living year contains %i leap yaear and %i non-leap year", leap,nonleap);
    seconds = (leap*366*24*60*60)+(nonleap*365*24*60*60);
    printf ("\nYou have lived %llu", seconds);
    printf (" seconds");
    return 0;
}
