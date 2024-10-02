#include<stdio.h>
void modified_bubble_sort(int*,int);

int main()
{
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Original orders in array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    modified_bubble_sort(arr,n);
    printf("\nAfter sorting elements:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
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
        if(swaps==0)    //checking on each round if swapping has been performed or not.
            break;
    }
}
