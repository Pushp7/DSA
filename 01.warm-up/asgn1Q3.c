#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[20],n,i;
    printf("---Calculate Sum---\n\n");
    printf("How many integers you want to input\n");
    scanf("%d",&n);
    printf("Enter now : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
        printf("%d  ",arr[i]);
    printf("\nSum of all the integers = %d",sum(arr,n));
    getch();
}

int sum(int A[],int size)
{
    int i,sum = 0;
    for(i=0;i<size;i++)
        sum = sum + A[i];
    return sum;
}

