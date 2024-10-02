//Find second lagest element in the array...

#include<stdio.h>
#include<conio.h>
 int secondLargest(int A[],int size)
 {
    int max,sMax,j;
    max = A[0];
    sMax = A[0];
    for(j=1;j<size;j++)
        if(A[j]>max)
            max = A[j];
    for(j=1;j<size;j++)
        if(A[j]>sMax && A[j]<max)
            sMax = A[j];
    return sMax;
 }

 int main()
 {
    int i,size,*arr,x;
    printf("Enter: Size of array: ");
    scanf("%d",&size);
    arr = (int*)malloc(size * sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<size;i++)
        scanf("%d",(arr+i));  //or, &arr[i]
    for(i=0;i<size;i++)
        printf("%d ",*(arr+i));  //or, arr[i]
    x = secondLargest(arr,size);
    printf("\nSecond largest value = %d",x);
    getch();
 }
