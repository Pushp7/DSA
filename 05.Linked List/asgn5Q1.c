/* Example of Singly Linked List*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};
//functions' protypes...
struct node* createNode();
void insertAtFirst(struct node **,int);
void insertAtLast(struct node **,int);
void insertAfter(struct node *,int);
void deleteFirst(struct node **);
void deleteLast(struct node **);
void deleteElement(struct node **);
struct node* find(struct node *,int);
void viewList(struct node **);
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
    n->item = data;
    n->next = *s;
    *s=n;
}

void insertAtLast(struct node **s,int data)
{
    struct node *n,*t;
    n = createNode();
    n->item = data;
    n->next = NULL;
    if(*s==NULL)
        *s=n;
    else
    {
        t= *s;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}

void insertAfter(struct node *temp,int data)
{
    struct node *n;
    n = createNode();
    n->item=data;
    n->next=temp->next;
    temp->next=n;
}

void deleteFirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        printf("Sorry! No elements found.\nThe List is empty...");
    else
    {
        t= *s;
        *s = t->next;
        free(t);
    }
}

void deleteLast(struct node **s)
{
    struct node *t,*prev;
    if(*s==NULL)
        printf("Sorry! No elements found.\nThe List is empty...");
    else
    {
        t=*s;
        prev=*s;
        while(t->next!=NULL){
            prev=t;
            t=t->next;
        }
        if(t!=prev)
            prev->next=NULL;
        else
            *s=NULL;
        free(t);
    }
}

void deleteElement(struct node **s)
{
    int data;
    struct node *t,*temp;
    printf("Enter element to delete\n");
    scanf("%d",&data);
    temp=find(*s,data);
    if(*s==NULL)
        printf("List is empty");
    else if(temp==*s)
        deleteFirst(s);
    else
    {
        t=*s;
        while(t->next!=temp)
            t=t->next;
        t->next=temp->next;
        free(temp);
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

void viewList(struct node **s)
{
    struct node *t;
    t= *s;
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

int menu()
{
    int choice;
    printf("\n1. Insert Element At First");
    printf("\n2. Insert Element At Last");
    printf("\n3. Insert After An Element");
    printf("\n4. Delete First Element");
    printf("\n5. Delete Last Element");
    printf("\n6. Delete Any Particular Element");
    printf("\n7. Find");
    printf("\n8. View All Elements");
    printf("\n9. Exit");

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
            insertAfter(find(start,x),y);
            break;
        case 4:
            deleteFirst(&start);
            break;
        case 5:
            deleteLast(&start);
            break;
        case 6:
            deleteElement(&start);
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
            viewList(&start);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid input!\a\nRetry");
        }
        getch();
    }
}
