#include<stdio.h>
#include<conio.h>
int maxValue(int A[],int size);
int main()
{
    int values[20],n,i;
    printf("How many number you want to input\n");
    scanf("%d",&n);
    printf("Now enter : \n");
    for(i=0;i<n;i++)
        scanf("%d",&values[i]);
    for(i=0;i<n;i++)
        printf("%d  ",values[i]);
    printf("\nGreatest number in all = %d",maxValue(values,n));

    getch();
}

int maxValue(int A[],int size)
{
    int i, max = A[0];
    for(i=1;i<size;i++)
        if(max < A[i])
            max = A[i];
    return max;
}
