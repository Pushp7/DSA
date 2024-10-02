#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ArrayADT
{
    int capacity;
    int lastIndex;
    int *ptr;
};

struct ArrayADT* createArray(int size)
{
    struct ArrayADT *arr = NULL;
    arr = (struct ArrayADT*)malloc(sizeof(struct ArrayADT));
    arr->capacity = size;
    arr->lastIndex = -1;
    arr->ptr = (int*)malloc(size * sizeof(int));
    return arr;
}

void append(struct ArrayADT *arr, int data)
{
    if(arr->lastIndex+1 == arr->capacity)
        printf("Array is full !");
    else
    {
        arr->lastIndex+=1;
        arr->ptr[arr->lastIndex] = data;
    }
}

void insertValue(struct ArrayADT *arr,int index,int data)
{
    if(index<0 || index>arr->lastIndex+1)
        printf("Insertion Error: Invalid Index");
    else if(arr->lastIndex==arr->capacity-1)
        printf("Insertion Error: Overflow");
    else
    {
        int i;
        for(i=arr->lastIndex;i>=index;i--)
            arr->ptr[i+1]=arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastIndex+=1;
    }
}

void delValue(struct ArrayADT *arr, int index)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nDeletion Error: Invalid Index");
    else
    {
        int i;
        for(i=index;i<=arr->lastIndex-1;i++)
            arr->ptr[i]=arr->ptr[i+1];
        arr->lastIndex--;
    }
}

void editValue(struct ArrayADT *arr,int index,int newData)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nEditing not possible: Invalid Index");
    else
        arr->ptr[index]=newData;
}

int countValues(struct ArrayADT *arr)
{
    return arr->lastIndex+1;
}

int searchValue(struct ArrayADT *arr,int data)
{
    int i;
    for(i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==data)
            return i;
    return -1;
}

int getValue(struct ArrayADT *arr,int index)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nError: Invalid Index");
    else
        return arr->ptr[index];
    return;
}

void viewAllValues(struct ArrayADT *arr)
{
    int i;
    for(i=0;i<=arr->lastIndex;i++)
        printf("%d  ",*(arr->ptr+i));
}

int main()
{
    int arrSize;
    struct ArrayADT *arr;
    printf("Enter size of array\n");
    scanf("%d",&arrSize);
    arr = createArray(arrSize);
    append(arr,20);

    getch();
    return 0;
}
