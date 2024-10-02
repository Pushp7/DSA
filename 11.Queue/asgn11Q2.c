/*Example of QUEUE using Dynamic Array*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Queue
{
    int capacity;
    int front,rear;
    int *array;
};

struct Queue* createQueue(int size)
{
    struct Queue *Q;
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = (int*)malloc(sizeof(int)*size);
    return Q;
}

//void doubleArray(struct Queue *q)
//{
//    q->array=(struct Queue*)realloc(q->array,2*q->capacity*sizeof(int));
//    q->capacity = 2*q->capacity;
//}
//
//void halfArray(struct Queue *q)
//{
//    q->array=(struct Queue*)realloc(q->array,q->capacity/2*sizeof(int));
//    q->capacity = q->capacity/2;
//}

void insertion(struct Queue *q,int data)
{
    if((q->front==0 && q->rear+1==q->capacity) || q->rear+1==q->front)
        printf("Queue is full, insertion can not be done.\a");
    else if(q->rear==-1 && q->front==-1)
    {
        q->front=q->rear=0;
        q->array[q->rear]=data;
    }
    else if(q->rear+1==q->capacity)
    {
        q->rear==0;
        q->array[q->rear]=data;
    }
    else
    {
        q->rear+=1;
        q->array[q->rear]=data;
    }
}

void deletion(struct Queue *q)
{
    if(q->front==-1 || q->rear==-1)
        printf("Queue is empty");
    else if(q->front==q->rear)
        q->front = q->rear = -1;
    else if(q->front+1==q->capacity)
        q->front=0;
    else
        q->front+=1;
}

int getFrontElement(struct Queue *q)
{
    if(q->front==-1)
        return NULL;
    else
        return q->array[q->front];
}

void queueLog(struct Queue *q)
{
    if(q->front==-1 || q->rear==-1)
        printf("");
    else
    {
        int i=q->front;
        while(i!=q->rear)
        {
            printf("%d ",q->array[i]);
            i=(i+1)%q->capacity;
        }
        printf("%d ",q->array[q->rear]);
    }
}

int menu()
{
    int choice;
    printf("1. Insertion");
    printf("\n2. Deletion");
    printf("\n3. Get Front Element");
    printf("\n4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    int size;
    struct Queue *q;
    printf("Enter the size of array for Queue\n");
    scanf("%d",&size);
    q=createQueue(size);
    int data;
    while(1)
    {
        system("cls");
        printf("Capacity= %d",size);
        printf("\nData in Queue: ");
        queueLog(q);
        printf("\n.....................................\n");
        switch(menu())
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            insertion(q,data);
            break;
        case 2:
            deletion(q);
            break;
        case 3:
            data = getFrontElement(q);
            if(data==NULL)
                printf("Queue is empty");
            else
                printf("%d",data);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!! retry");
        }
        getch();
    }
}

