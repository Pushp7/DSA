//Example of Circular Doubly Linked List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *prev,*next;
};

struct node* createNode();
void addToEmpty(struct node **s,int data);
void insertAtFirst(struct node **s,int data);
void insertAtLast(struct node **s,int data);
void insertAfter(struct node **start,int pData,int data);
void deleteFirst(struct node **s);
void deleteLast(struct node **s);
void deleteElement(struct node **start,int delData);
void deleteAllElements(struct node **s);
struct node* find(struct node *start,int data);
void viewList(struct node *s);
int menu();

struct node* createNode()
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    return n;
}

void addToEmpty(struct node **s,int data)
{
    struct node *n;
    n = createNode();

    *s=n;
    n->item = data;
    n->next = *s;
    n->prev = *s;
}

void insertAtFirst(struct node **s,int data)
{
    if(*s==NULL)
        addToEmpty(s,data);
    else
    {
        struct node *n;
        n = createNode();

        n->item = data;
        n->next = *s;
        n->prev = (*s)->prev;

        (*s)->prev->next = n;
        (*s)->prev = n;
        *s = n;
    }
}

void insertAtLast(struct node **s,int data)
{
    if(*s==NULL)  //if list is fully empty..
        addToEmpty(s,data);
    else   //if list is not empty..
    {
        struct node *n;
        n=createNode();

        n->item = data;
        n->next = *s;
        n->prev = (*s)->prev;

        (*s)->prev->next = n;
        (*s)->prev = n;
    }
}

void insertAfter(struct node **start,int pData,int data)
{
    struct node *n,*t;
    t = *start;
    do{
        if(t->item == pData)
        {
            n=createNode();
            n->item = data;
            n->next = t->next;
            n->prev = t;
            t->next = n;
            break;
        }
        t=t->next;
    }while(t!=*start);
    if(t==*start)
        printf("The value you have entered [i.e %d] is not in the list\nTry again...",pData);
}

void deleteFirst(struct node **s)
{
    if(*s==NULL)
        printf("Sorry!\nThe list is empty.");
    else if((*s)->next==*s)  //or, (*s)->prev==*s
    {
        free(*s);
        *s = NULL;
    }
    else
    {
        struct node *firstNode;
        firstNode = *s;
        (*s)->next->prev = (*s)->prev;
        (*s)->prev->next = (*s)->next;
        *s = (*s)->next;
        free(firstNode);
    }
}

void deleteLast(struct node **s)
{
    if(*s==NULL)
        printf("Sorry!\nThe list is empty.");
    else if((*s)->next== *s)
        deleteFirst(s);
    else
    {
        struct node *lastNode;
        lastNode = (*s)->prev;
        (*s)->prev->prev->next = *s;
        (*s)->prev = (*s)->prev->prev;
        free(lastNode);
    }
}

void deleteElement(struct node **start,int delData)
{
    if(*start==NULL)
        printf("The list is empty");
    else if((*start)->next==*start)
        deleteFirst(start);
    else
    {
        struct node *t;
        t=*start;
        do{
            if(t->item == delData)
            {
                t->prev->next=t->next;
                t->next->prev = t->prev;
                if(t==*start)
                    *start=t->next;
                free(t);
                break;
            }
            t=t->next;
        }while(t!=*start);
        if(t==*start)
            printf("The value you have entered [i.e %d] is not in the list\nTry again...",delData);
    }
}

void deleteAllElements(struct node **s)  //problem hai isme...
{
//    struct node *t1,*t2;
//    t1=*s;
//    t2=NULL;
//    while(t1!=*s)
//    {
//        printf("\nHello");
//        t2=t1;
//        t1=t1->next;
//        free(t2);
//    }
//    free(t1);
//    *s=NULL;
}

struct node* find(struct node *start,int data)
{
    struct node *t;
    t=start;
    if(start==NULL){
        printf("List is empty");
        return -1;
    }
    else
    {
        do{
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=start);
        return NULL;
    }
}

void viewList(struct node *s)
{
    if(s==NULL)
        printf("The list is empty.");
    else
    {
        struct node *t;
        t=s;
        do{
            printf("%d ",t->item);
            t=t->next;
        }while(t!=s);
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
    printf("\n8. View All Elements");
    printf("\n9. Reverse elements in the List");
    printf("\n10. Delete All Elements");
    printf("\n11. Exit");

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
            else if(returnedV>0)
                printf("Hurray!!!Value Found!\n(at address %u)",returnedV);
            break;
        case 8:
            viewList(start);
            break;
        case 9:
//            reverseList(start);
            break;
        case 10:
            deleteAllElements(&start);
        case 11:
            exit(0);
        default:
            printf("Invalid input!\a\nRetry");
        }
        getch();
    }
}
