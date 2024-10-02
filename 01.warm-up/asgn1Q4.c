#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int newDMAarray(int,int);
int main()
{
    int n1,n2,*ptr1,*ptr2,i,*p,k;
    printf("Enter number of elements in first array\n");
    scanf("%d",&n1);
    ptr1 = (int*)malloc(n1 * sizeof(int));
    printf("Enter elements now:\n");
    for(i=0;i<n1;i++)
        scanf("%d",(ptr1+i));

    printf("Now enter number of elements in second array\n");
    scanf("%d",&n2);
    ptr2 = (int*)malloc(n2 * sizeof(int));
    printf("Enter element now:\n");
    for(i=0;i<n2;i++)
        scanf("%d",(ptr2+i));

    p = newDMAarray(n1,n2);
    k=n1;
    for(i=0;i<n1;i++)
        if(i<n1)
            *(p+i) = *(ptr1+i);
    for(i=0;i<n2;i++)
        if(i<=n2){
            *(p+k) = *(ptr2+i);
            k++; }

    for(i=0;i<n1+n2;i++)
        printf("%d ",*(p+i));
}

int newDMAarray(int a,int b)
{
    int *ptr;
    ptr = (int*)malloc((a+b) * sizeof(int));
    return ptr;
}
