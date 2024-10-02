#include<stdio.h>
void selection_sort(int[],int);

int main()
{
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Original orders in array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    selection_sort(arr,n);
    printf("\nAfter sorting elements:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void selection_sort(int A[],int size)
{
    int i,min,minIndex,round,temp;
    for(round=1;round<size;round++)   //this loop is for doing the same activities for each round..
    {
        min = A[round-1];
        minIndex = round-1;

        //finding the most min value and its index from unarranged data..
        for(i=round;i<size-1;i++)
            if(A[i]<min)
            {
                min = A[i];
                minIndex = i;
            }

        //now swapping min value with starting index's value of each round..
        for(i=round-1;i<size;i++)
        {
            temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
}
