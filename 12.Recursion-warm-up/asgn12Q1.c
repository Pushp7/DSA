/*Write a recursive function to print first n natural number */
#include<stdio.h>
int main()
{
    int nth;
    printf("Enter the nth number to print Natural number\n");
    scanf("%d",&nth);
    f1(nth);
}

void f1(int Nth)
{
    if(Nth>=1)
    {
        f1(Nth-1);
        printf(" %d",Nth);
    }
}
