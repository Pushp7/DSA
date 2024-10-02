#include<stdio.h>
int BinarySearch(int*,int,int);
void modified_bubble_sort(int[],int);
int main()
{
    int search,index,n;
    int arr[]={3,13,21,7,8,20,11,1,8,30};
    n=sizeof(arr)/sizeof(arr[0]);
    printf("Enter a number to search in database\n");
    scanf("%d",&search);
    index=BinarySearch(arr,n,search);
    if(index>=0)
        printf("Hurrey! Data found");
    else
        printf("Oops! Data not found");
    return 0;
}

int BinarySearch(int A[],int N,int item)
{
    modified_bubble_sort(A,N);      //first sorted or arranged in increasing order.
    int l=0,u=N-1,m;
    while(l<=u)
    {
        m=(l+u)/2;
        if(item==A[m])
            return m;
        else if(item>A[m])
            l=m+1;
        else
            u=m-1;
    }
    return -1;
}

void modified_bubble_sort(int Arr[],int N)
{
    int round,i,temp,swaps;
    for(round=1;round<N-1;round++)
    {
        swaps=0;
        for(i=0;i<N-1-round;i++)
        {
            if(Arr[i]>Arr[i+1])
            {
                temp=Arr[i];
                Arr[i]=Arr[i+1];
                Arr[i+1]=temp;
                swaps++;
            }
        }
        if(swaps==0)
            break;
    }
}
