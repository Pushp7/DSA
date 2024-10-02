#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct DynamicArray
{
    int capacity;
    int lastIndex;
    int *ptr;
};

struct DynamicArray* createArray(int size)
{
    struct DynamicArray *arr=NULL;
    arr = (struct DynamicArray*)malloc(sizeof(struct DynamicArray));
    arr->capacity = size;
    arr->lastIndex = -1;
    arr->ptr = (int*)malloc(sizeof(int) * size);
    return arr;
}

void doubleArray(struct DynamicArray *arr)
{
    arr->ptr = realloc(arr->ptr, 2*arr->capacity * sizeof(int));
    arr->capacity = 2*arr->capacity;
}

void halfArray(struct DynamicArray *arr)
{
    arr->ptr = realloc(arr->ptr, arr->capacity/2 * sizeof(int));
    arr->capacity/=2;
}

void append(struct DynamicArray *arr, int data)
{
    if(arr->lastIndex+1==arr->capacity)
        doubleArray(arr); //to avoid overflow we have doubled the size of the array..
    arr->lastIndex++;
    arr->ptr[arr->lastIndex]=data;
}

void insertValue(struct DynamicArray *arr,int index,int data)
{
    int i;
    if(index<0 || index>arr->lastIndex+1)
        printf("\nInsertion Error: Invalid Index");
    else
    {
        if(arr->lastIndex+1 == arr->capacity)
            doubleArray(arr); //to avoid overflow we have doubled the size of the array..
        for(i=arr->lastIndex;i>=index;i--)
            arr->ptr[i+1] = arr->ptr[i];
        arr->ptr[index]=data;
        arr->lastIndex++;
    }
}

void delValue(struct DynamicArray *arr, int index)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nDeletion Error: Invalid Index");
    else
    {
        int i;
        for(i=index;i<arr->lastIndex-1;i++)
            arr->ptr[i] = arr->ptr[i+1];
        arr->lastIndex-=1;
        if(arr->capacity/2==arr->lastIndex+1)
            halfArray(arr);
    }
}

void editValue(struct DynamicArray *arr,int index,int newData)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nEditing not possible: Invalid Index");
    else
        arr->ptr[index]=newData;
}

int countValues(struct DynamicArray *arr)
{
    return arr->lastIndex+1;
}

int getValue(struct DynamicArray *arr,int index)
{
    if(index<0 || index>arr->lastIndex)
        printf("\nError: Invalid Index");
    else
        return arr->ptr[index];
    return;
}

int searchValue(struct DynamicArray *arr,int data)
{
    int i;
    for(i=0;i<=arr->lastIndex;i++)
        if(arr->ptr[i]==data)
            return i;
    return -1;
}

void viewAllValues(struct DynamicArray *arr)
{
    int i;
    for(i=0;i<=arr->lastIndex;i++)
        printf("%d  ",arr->ptr[i]);
}

int menu()
{
    int choice;
    printf("\n1.Append");
    printf("\n2.Insert");
    printf("\n3.Delete");
    printf("\n4.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    struct DynamicArray *arr;
    int size,x,index;
    printf("Enter size of Array : ");
    scanf("%d",&size);
    arr = createArray(size);
    while(1)
    {
        system("cls");
        printf("Capacity: %d",arr->capacity);
        printf("\nCount Data: %d",countValues(arr));
        printf("\nData: ");
        viewAllValues(arr);
        printf("\n.......................................");
        switch(menu())
        {
        case 1:
            printf("Enter data to Append in array : ");
            scanf("%d",&x);
            append(arr,x);
            break;
        case 2:
            printf("Enter data to insert : ");
            scanf("%d",&x);
            printf("Enter index number : ");
            scanf("%d",&index);
            insertValue(arr,index,x);
            break;
        case 3:
            printf("Enter index number : ");
            scanf("%d",&index);
            delValue(arr,index);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid Choice! Retry\n");
        }
        getch();
    }
    return 0;
}
