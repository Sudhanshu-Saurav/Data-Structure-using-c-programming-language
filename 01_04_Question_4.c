#include <math.h>
#include <stdio.h>
int main ()
{
    double x,FinalValue;
    printf ("Enter the value of x :");
    scanf ("%lf",&x);
    FinalValue = exp(x);
    printf ("Exponential of %0.2lf = %0.4lf",x,FinalValue);
    return 0;
}
