#include<stdio.h>
int quick(int A[],int l,int u);
void quick_sort(int A[],int l,int u);

int main()
{
    int i,arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Original orders in array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    quick_sort(arr,0,n-1);  //calling fun for sorting.
    printf("\nAfter sorting elements:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void quick_sort(int A[],int l,int u)
{
    int loc;
    loc=quick(A,l,u);
    if(l+1<loc)
        quick_sort(A,l,loc-1);
    if(u-1>loc)
        quick_sort(A,loc+1,u);
}

int quick(int A[],int l,int u)
{
    int loc,left,right,t;
    loc=l;
    left=l;
    right=u;
    while(1)
    {
        while(left<right && A[loc]<=A[right])
            right--;
        if(left==right)
            break;
        else
        {
            t=A[loc];
            A[loc]=A[right];
            A[right]=t;
            loc=right;
        }
        while(left<right && A[loc]>=A[left])
            left++;
        if(left==right)
            break;
        else
        {
           t=A[loc];
           A[loc]=A[left];
           A[left]=t;
           loc=left;
        }
    }
    return loc;
}
