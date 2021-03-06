#include <stdio.h>
 
void magicsq(int, int [10][10]);
 
int main( )
{
    int n;
    int a[10][10];
 
    printf("Enter the n: ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("Magic square works for an odd numbered size\n");
    }
    else
    {
        magicsq(n, a);
    }
    return 0;
}
 
void magicsq(int n, int a[10][10])
{
    int sqr = n * n;
    int i = 0, j = n / 2, k;
 
    for (k = 1; k <= sqr; ++k) 
    {
        a[i][j] = k;
        i--;
        j++;
 
        if (k % n == 0) 
        { 
            i += 2; 
            --j; 
        }
        else 
        {
            if (j == n) 
            {
                j -= n;
            }
            else if (i < 0)
            {
                i += n;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
