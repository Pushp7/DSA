//Example of Circular Linked List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

struct node* find(struct node *last,int data);

struct node* createNode()
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void addToEmpty(struct node **last,int data)
{
    struct node *n;
    n=createNode();
    *last = n;
    n->item = data;
    (*last)->next = *last;
}

void insertAtFirst(struct node **l,int data)
{
    if(*l==NULL)
        addToEmpty(l,data);
    else
    {
        struct node *n;
        n = createNode();
        n->item = data;
        n->next = (*l)->next;
        (*l)->next = n;
    }
}

void insertAtLast(struct node **l,int data)
{
    if(*l==NULL)
        addToEmpty(l,data);
    else
    {
        struct node *n;
        n = createNode();
        n->item = data;
        n->next = (*l)->next;
        (*l)->next = n;
        *l=n;
    }
}

void insertAfter(struct node **last,int pData,int data)
{
    struct node *t;
    t=(*last)->next;
    do{
        if(t->item==pData)
        {
            struct node *n;
            n=createNode();
            n->item = data;
            n->next = t->next;
            t->next = n;
            if(t==*last)
                *last=n;
            break;
        }
        t=t->next;
    }while(t!=(*last)->next);
    if(t==(*last)->next)
        printf("The value you have entered [i.e %d] is not in the list\nTry again...",pData);
}

void deleteFirst(struct node **l)
{
    if(*l==NULL)
        printf("Sorry!!!List is empty");
    else if((*l)->next==*l)
    {
        free(*l);
        *l = NULL;
    }
    else
    {
        struct node *t;
        t = (*l)->next;
        (*l)->next = (*l)->next->next;
        free(t);
    }
}

void deleteLast(struct node **l)
{
    if(*l==NULL)
        printf("List is empty for now");
    else if((*l)->next==*l)
        deleteFirst(l);
    else
    {
        struct node *t,*temp;
        temp = *l;
        t=(*l)->next;
        while(t->next!=*l)
            t=t->next;
        t->next = (*l)->next;
        *l = t;
        free(temp);
    }
}

void deleteElement(struct node **l,int data)
{
    if(*l==NULL)
        printf("Sorry, the list is empty");
    else if((*l)->next==*l)
        deleteFirst(l);
    else
    {
        struct node *delNode,*t;
        delNode = find(*l,data);
        t=(*l)->next;
        while(t->next!=delNode)
            t=t->next;
        t->next=delNode->next;
        free(delNode);
    }
}

struct node* find(struct node *last,int data)
{
    if(last==NULL)
    {
        printf("List is empty");
        return -1;
    }
    else
    {
        struct node *t;
        t = last->next;
        do{
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=last->next);
        return NULL;
    }
}

void viewList(struct node *last)
{
    if(last==NULL)
        printf("Sorry!!! The List is empty...");
    else
    {
        struct node *t;
        t=last->next;
        do{
            printf("%d ",t->item);
            t=t->next;
        }while(t!=last->next);
    }
}

int menu()
{
    int choice;
    printf("1. Insert Element At First");
    printf("\n2. Insert Element At Last");
    printf("\n3. Insert After An Element");
    printf("\n4. Delete First Element");
    printf("\n5. Delete Last Element");
    printf("\n6. Delete Any Particular Element");
    printf("\n7. Find");
    printf("\n8. View List");
    printf("\n9. Exit");

    printf("\n\nSelect your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    struct node *last=NULL;
    while(1)
    {
        int x,y,returnedV;
        system("cls");
        switch(menu())
        {
        case 1:
            printf("Enter data to insert\n");
            scanf("%d",&x);
            insertAtFirst(&last,x);
            break;
        case 2:
            printf("Enter data to insert\n");
            scanf("%d",&x);
            insertAtLast(&last,x);
            break;
        case 3:
            printf("After which value you want to insert data\n");
            scanf("%d",&x);
            printf("Enter data to insert\n");
            scanf("%d",&y);
            insertAfter(&last,x,y);
            break;
        case 4:
            deleteFirst(&last);
            break;
        case 5:
            deleteLast(&last);
            break;
        case 6:
            printf("Enter which value you want to delete\n");
            scanf("%d",&x);
            deleteElement(&last,x);
            break;
        case 7:
            printf("Enter value\n");
            scanf("%d",&x);
            returnedV = find(last,x);
            if(returnedV==NULL)
                printf("Not found!\a");
            else if(returnedV>0)
                printf("Hurray!!!Value Found!\n(at address %u)",returnedV);
            break;
        case 8:
            viewList(last);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice!\a\nRetry");
        }
        getch();
    }
}
