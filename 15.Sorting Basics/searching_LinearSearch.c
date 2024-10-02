#include<stdio.h>
int LinearSearch(int[],int,int);
int main()
{
    int n,search,i,p,arr[]={3,13,21,7,8,20,11,1,8,30};
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter a number to search in database\n");
    scanf("%d",&search);
    p=LinearSearch(arr,n,search);
    if(p>=0)
        printf("Hurrey! Data found");
    else
        printf("Oops! Data not found");
    return 0;
}

int LinearSearch(int A[],int N,int item)
{
    int i;
    for(i=0;i<N;i++)
        if(A[i]==item)
            return i;
    if(i==N)
        return -1;
}
