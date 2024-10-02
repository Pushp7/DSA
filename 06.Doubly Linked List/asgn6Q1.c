/* Example of Doubly Linked List*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int item;
    struct node *next,*prev;
};
//functions' prototypes...
struct node* createNode();
void insertAtFirst(struct node**,int);
void insertAtLast(struct node **,int);
void insertAfter(struct node **,int,int);
void deleteFirst(struct node **);
void deleteLast(struct node **);
void deleteElement(struct node **,int);
struct node* find(struct node *,int);
void viewList(struct node *);
void reverseList(struct node *);
int menu();

struct node* createNode()
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return n;
}

void insertAtFirst(struct node **s,int data)
{
    struct node *n;
    n = createNode();
    n->prev=NULL;
    n->item = data;
    n->next = *s;
    if(*s==NULL)
        *s=n;
    else
    {
        (*s)->prev=n;
        *s=n;
    }
}

void insertAtLast(struct node **s,int data)
{
    struct node *n,*t;
    n = createNode();
    n->item = data;
    n->next = NULL;
    if(*s==NULL)
    {
        n->prev=NULL;
        *s=n;
    }
    else
    {
        t= *s;  // for traversing, assigning START in a new variable.
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
        n->prev = t;
    }
}

void insertAfter(struct node **s,int prevData,int data)
{
    int x,y;
    struct node *prevNode,*n;
    prevNode = find(*s,prevData);
    if(prevNode==NULL){
        system("cls");
        printf("The data you have entered did not match\nTry again...");
        printf("\n\nAfter which value you want to insert data\n");
        scanf("%d",&x);
        printf("Enter data to insert\n");
        scanf("%d",&y);
        insertAfter(s,x,y);
    }
    else
    {
        n = createNode();
        n->item = data;
        n->next = prevNode->next;
        n->prev = prevNode;
        if(prevNode->next!=NULL)
            prevNode->next->prev = n;
        prevNode->next = n;
    }
}

void deleteFirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("Sorry! No elements found.\nThe List is empty...");
    else
    {
        t= *s;
        if(t->next==NULL)
            *s=NULL;
        else
        {
            *s = t->next;
            (*s)->prev=NULL;
        }
        free(t);
    }
}

void deleteLast(struct node **s)
{
    struct node *t;
    if(*s==NULL)  //when there is no node in the list
        printf("Sorry! No elements found.\nThe List is empty...");
    else if((*s)->next==NULL)  //when there is only one node in the list
        deleteFirst(s);
    else        //when there is more than one node in the list
    {
        t = *s;
        while(t->next!=NULL)
            t=t->next;
        t->prev->next = NULL;
        free(t);
    }
}

void deleteElement(struct node **s,int delData)
{
    struct node *delNode,*t;
    delNode = find(*s,delData);
    if(*s==NULL)
        printf("Sorry! No elements found.\nThe List is empty...");
    else if(delNode==NULL)
    {
        int x;
        printf("The data you have entered did not match\nTry again...");
        printf("\n\nEnter which value you want to delete\n");
        scanf("%d",&x);
        deleteElement(s,x);
    }
    else if(*s==delNode)
        deleteFirst(s);
    else
    {
        t=*s;
        while(t->next!=delNode)
            t=t->next;
        t->next = delNode->next;
        delNode->next->prev = t;
        free(delNode);
    }
}

struct node* find(struct node *start,int data)
{
    while(start!=NULL)
    {
        if(start->item==data)
            return start;
        start=start->next;
    }
    return NULL;
}

void viewList(struct node *s)
{
    struct node *t;
    t= s;
    if(t==NULL)
        printf("Sorry! No elements found.\nThe List is empty...");
    else
    {
        while(t)
        {
            printf("%d ",t->item);
            t=t->next;
        }
    }
}

void reverseList(struct node *start)
{
//    struct node *t;
//    t= start;
//    if(start==NULL)
//        printf("Sorry! No elements found.\nThe List is empty...");
//    else
//    {
//        while(start!=NULL)
//            start=start->next;
//
//        while(start!=t)
//        {
//            printf("%d",start->item);
//            start=start->prev;
//        }
//    }
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
    printf("\n8. View All Elements");
    printf("\n9. Reverse elements in the List");
    printf("\n10. Exit");

    printf("\n\nSelect your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    struct node *start=NULL;
    int x,y,returnedV;
    while(1)
    {
        system("cls");
        switch(menu())
        {
        case 1:
            printf("Enter data to insert\n");
            scanf("%d",&x);
            insertAtFirst(&start,x);
            break;
        case 2:
            printf("Enter data to insert\n");
            scanf("%d",&x);
            insertAtLast(&start,x);
            break;
        case 3:
            printf("After which value you want to insert data\n");
            scanf("%d",&x);
            printf("Enter data to insert\n");
            scanf("%d",&y);
            insertAfter(&start,x,y);
            break;
        case 4:
            deleteFirst(&start);
            break;
        case 5:
            deleteLast(&start);
            break;
        case 6:
            printf("Enter which value you want to delete\n");
            scanf("%d",&x);
            deleteElement(&start,x);
            break;
        case 7:
            printf("Enter value\n");
            scanf("%d",&x);
            returnedV = find(start,x);
            if(returnedV==NULL)
                printf("Not found!\a");
            else
                printf("Hurray!!!Value Found!\n(at address %u)",returnedV);
            break;
        case 8:
            viewList(start);
            break;
        case 9:
            reverseList(&start);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid input!\a\nRetry");
        }
        getch();
    }
}
