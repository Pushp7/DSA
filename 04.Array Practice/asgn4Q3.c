//Print frequency of distinct elements in the array...
#include<stdio.h>
#include<conio.h>
int main()
{
    int size,*arr,i;
    printf("Enter the size of array:  ");
    scanf("%d",&size);
    arr = (int*)malloc(size * sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);  //or, (arr+i)
    system("cls");
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);  //or, *(arr+i)
        printf("\n");
    printFrequency(arr,size);

    getch();
}

void printFrequency(int A[],int size)
{
    int *UE,i,j,cap=1,k=0;
    UE = (int*)malloc(cap * sizeof(int)); //creating array for all Unique Elements(UE) dynamically.
    UE[k] = A[0];
    for(i=0;i<size;i++){
        int flag=0;
        for(j=0;j<cap;j++)
            if(A[i]!=UE[j])
                flag++;
        if(flag==cap){
            ++cap;
            UE = (int*)realloc(UE,cap*sizeof(int));
            UE[++k] = A[i];
            }
    }
//    for(i=0;i<cap;i++)
//    printf("%d ",*(UE+i)); //printing all the Unique Elements.

    for(i=0;i<cap;i++)
    {
        int count = 0;
        for(j=0;j<size;j++)
            if(UE[i]==A[j])
                count++;
        printf("\n%d occurs %d times",UE[i],count);
    }
}
