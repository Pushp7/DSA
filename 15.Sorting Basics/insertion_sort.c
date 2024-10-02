#include<stdio.h>
void insertion_sort(int a[],int n);

int main()
{
    int arr[]={64,34,25,12,22,90,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Original orders in array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    insertion_sort(arr,n);
    printf("\nAfter sorting elements:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void insertion_sort(int a[],int n)
{
    int round,i,temp;
    for(round=1;round<n;round++)
    {
        for(i=round;i>0;i--)
        {
            if(a[i]<a[i-1])
            {
                temp = a[i-1];
                a[i-1] = a[i];
                a[i]=temp;
            }
            else
                break;
        }
    }
}
