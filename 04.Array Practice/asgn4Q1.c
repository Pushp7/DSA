/*Q. Write a function that rotates A[] of size n by d element(s)
 in given direction(-1 for Left dir, and +1 for Right dir). */

#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
void rotate(int A[],int n,int d,int dir)
{
    int j,i,temp;
    if(dir==1)
    {
        for(j=0;j<d;j++)
        {
            temp=A[n-1];
            for(i=n-1;i>=0;i--)
                A[i] = A[i-1];
            A[0] = temp;
        }
        printf("\nAfter rotating %d round in RIGHT direction\n",d);
        for(i=0;i<n;i++)
            printf("%d ",A[i]);
    }
    else
    {
        for(j=0;j<d;j++)
        {
            temp = A[0];
            for(i=0;i<n;i++)
                A[i]=A[i+1];
            A[n-1]=temp;
        }
        printf("\nAfter rotating %d round in LEFT direction\n",d);
        for(i=0;i<n;i++)
            printf("%d ",A[i]);
    }
}

int main()
{
    int size,*arr,i,steps,dir;
    printf("Enter the size of array: ");
    scanf("%d",&size);

    arr = (int*)malloc(size*sizeof(int));

    printf("Enter elements in array\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]); //(arr+i)

    system("cls");
    printf("Entered elements: ");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]); //*(arr+i)

    printf("\n\nEnter no. of times you want to rotate elements\n");
    scanf("%d",&steps);
    printf("Enter rotation direction(-1 for LEFT, +1 for RIGHT)\n");
    scanf("%d",&dir);

    rotate(arr,size,steps,dir);
    getch();
}
