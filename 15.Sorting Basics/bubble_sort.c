#include<stdio.h>
void bubble_sort(int*,int);

int main()
{
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Original orders in array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    bubble_sort(arr,n);
    printf("\nAfter sorting elements:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}

void bubble_sort(int Arr[],int N)
{
    int round,i,temp;
    for(round=1;round<N-1;round++)
    {
        for(i=0;i<N-1-round;i++)
        {
            if(Arr[i]>Arr[i+1])
            {
                temp=Arr[i];
                Arr[i]=Arr[i+1];
                Arr[i+1]=temp;
            }
        }
    }
}
