/* Implementation of DEQUE(Double Ended Queue) using Array */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct deque
{
    int capacity;
    int front,rear;
    int *arr;
};

struct deque* createDeque(int size)
{
    struct deque *d;
    d = (struct deque*)malloc(sizeof(struct deque));
    d->capacity=size;
    d->front = -1;
    d->rear = -1;
    d->arr = (int*)malloc(sizeof(int)*size);
    return d;
}

int isEmpty(struct deque *d)
{
    if(d->front==-1 || d->rear==-1)
        return 1;
    else
        return 0;
}

int isFull(struct deque *d)
{
    if((d->front==0 && d->rear+1==d->capacity) || d->rear+1==d->front)
        return 1;
    else
        return 0;
}

void insertFront(struct deque *d,int data)     //pushThroughFront
{
    if(isFull(d))
        printf("Deque is full\a");
    else if(d->front==-1&&d->rear==-1)
    {
        d->front=0;
        d->rear=0;
        d->arr[d->front]=data;
    }
    else if(d->front==0)
    {
        d->front=d->capacity-1;
        d->arr[d->front]=data;
    }
    else
    {
        d->front-=1;
        d->arr[d->front]=data;
    }
}

void insertRear(struct deque *d,int data)       //pushThroughRear
{
    if(isFull(d))
        printf("Deque is full\a");
    else if(d->rear==-1&&d->front==-1)
    {
        d->rear=0;
        d->front=0;
        d->arr[d->rear]=data;
    }
    else if(d->rear+1==d->capacity)
    {
        d->rear=0;
        d->arr[d->rear]=data;
    }
    else
    {
        d->rear++;
        d->arr[d->rear]=data;
    }
}

void deleteFront(struct deque *d)           //popThroughFront
{
    if(isEmpty(d))
        printf("Deque is empty");
    else if(d->front==d->rear)
    {
        d->front=-1;
        d->rear=-1;
    }
    else if(d->front+1==d->capacity)
        d->front=0;
    else
        d->front++;
}

void deleteRear(struct deque *d)            //popThroughRear
{
    if(isEmpty(d))
        printf("Deque is empty");
    else if(d->front==d->rear)
    {
        d->front=-1;
        d->rear=-1;
    }
    else if(d->rear==0)
        d->rear=d->capacity-1;
    else
        d->rear--;
}

int peekFront(struct deque *d)
{
    if(isEmpty(d))
        return NULL;
    else
        return d->arr[d->front];
}

int peekRear(struct deque *d)
{
    if(isEmpty(d))
        return NULL;
    else
        return d->arr[d->rear];
}

void dequeLog(struct deque *d)
{
    if(isEmpty(d))
        printf("");
    else
    {
        int i=d->front;
        while(i!=d->rear)
        {
            printf("%d ",d->arr[i]);
            i=(i+1)%d->capacity;
        }
        printf("%d ",d->arr[d->rear]);
    }
}

int menu()
{
    int choice;
    printf("1. Push Through Front");
    printf("\n2. Push Through Rear");
    printf("\n3. Pop Through Front");
    printf("\n4. Pop Through Rear");
    printf("\n5. Peek From Front");
    printf("\n6. Peek From Rear");
    printf("\n7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    int data;
    struct deque *dq;
    dq = createDeque(6);
    while(1)
    {
        system("cls");
        printf("____________________________________________________\n");
        printf("Deque Logs:\n\n");
        printf("Data in Deque:- ");
        dequeLog(dq);
        printf("\n____________________________________________________\n");
        switch(menu())
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            insertFront(dq,data);
            break;
        case 2:
            printf("Enter data\n");
            scanf("%d",&data);
            insertRear(dq,data);
            break;
        case 3:
            deleteFront(dq);
            break;
        case 4:
            deleteRear(dq);
            break;
        case 5:
            data=peekFront(dq);
            if(data==NULL)
                printf("Deque is empty");
            else
                printf("%d",data);
            break;
        case 6:
            data=peekRear(dq);
            if(data==NULL)
                printf("Deque is empty");
            else
                printf("%d",data);
            break;
        case 7:
            exit(0);
        default :
            printf("Invalid choice! Retry");
        }
        getch();
    }
}
