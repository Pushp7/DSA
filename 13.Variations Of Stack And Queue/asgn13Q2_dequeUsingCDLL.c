/* Implementation of DEQUE(Double Ended Queue) using "Circular Doubly Linked List" */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int item;
    struct node *next,*prev;
};

void insertAtEmpty(struct node **h,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    *h=n;
    n->item=data;
    n->prev=*h;
    n->next=*h;
}

void insertFront(struct node **h,int data)
{
    if(*h==NULL)   //isEmpty
        insertAtEmpty(h,data);
    else    //isAtLeastOneNode
    {
        struct node *n;
        n=(struct node*)malloc(sizeof(struct node));
        n->item=data;
        n->prev=(*h)->prev;
        n->next=*h;

        (*h)->prev->next=n;
        (*h)->prev=n;
        *h=n;
    }
}

void insertRear(struct node **h,int data)
{
    if(*h==NULL)   //isEmpty
        insertAtEmpty(h,data);
    else    //isAtLeastOneNode
    {
        struct node *n;
        n=(struct node*)malloc(sizeof(struct node));
        n->item=data;
        n->prev = (*h)->prev;
        n->next = *h;

        (*h)->prev->next=n;
        (*h)->prev=n;
    }
}

void deleteFront(struct node **h)
{
    if(*h==NULL)    //isEmpty
        printf("Deque is Empty");
    else if((*h)->next==*h)  //isFirstNode
    {
        free(*h);
        *h=NULL;
    }
    else
    {
        struct node *temp;
        temp = *h;
        (*h)->next->prev=(*h)->prev;
        (*h)->prev->next=(*h)->next;
        *h=(*h)->next;
        free(temp);
    }
}

void deleteRear(struct node **h)
{
    if(*h==NULL)    //isEmpty
        printf("Deque is Empty");
    else if((*h)->next==*h)  //isFirstNode
    {
        free(*h);
        *h=NULL;
    }
    else
    {
        struct node *temp;
        temp = (*h)->prev;
        (*h)->prev->prev->next=*h;
        (*h)->prev=(*h)->prev->prev;
        free(temp);
    }
}

int peekFront(struct node *h)
{
    if(h==NULL)
        return NULL;
    else
        return h->item;
}

int peekRear(struct node *h)
{
    if(h==NULL)
        return NULL;
    else
        return h->prev->item;
}

void allDataInDeque(struct node *h)
{
    if(h==NULL)
        printf("");
    else
    {
        struct node *t;
        t=h;
        do{
            printf("%d ",t->item);
            t=t->next;
        }while(t!=h);
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
    struct node *head=NULL;
    system("color e");
    while(1)
    {
        int data;
        system("cls");
        printf("____________________________________________________\n");
        printf("Deque Logs:\n\n");
        printf("Data in Deque:- ");
        allDataInDeque(head);
        printf("\n____________________________________________________\n");
        switch(menu())
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            insertFront(&head,data);
            break;
        case 2:
            printf("Enter data\n");
            scanf("%d",&data);
            insertRear(&head,data);
            break;
        case 3:
            deleteFront(&head);
            break;
        case 4:
            deleteRear(&head);
            break;
        case 5:
            data=peekFront(head);
            if(data==NULL)
                printf("Deque is empty");
            else
                printf("%d",data);
            break;
        case 6:
            data=peekRear(head);
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
