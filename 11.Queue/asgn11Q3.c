/*Example of QUEUE using Linked List*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void insertion(struct node **r,struct node **f,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = NULL;
    if(*r==NULL)
    {
        *f=n;
        *r=n;
    }
    else
    {
        (*r)->next = n;
        *r=n;
    }
}

void deletion(struct node **r,struct node **f)
{
    if(*f==NULL)
        printf("Queue is empty");
    else if(*f==*r)
    {
        free(*f);
        *f=NULL;
        *r=NULL;
    }
    else
    {
        struct node *temp;
        temp = *f;
        *f=(*f)->next;
        free(temp);
    }
}

int getFrontElement(struct node *front)
{
    if(front==NULL)
        return NULL;
    else
        return front->item;
}

void queue(struct node *front)
{
    if(front==NULL)
        printf("");
    else
    {
        while(front!=NULL)
        {
            printf("%d ",front->item);
            front=front->next;
        }
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
    struct node *front=NULL,*rear=NULL;
    int data;
    while(1)
    {
        system("cls");
        printf("Data in Queue: ");
        queue(front);
        printf("\n............................\n");
        switch(menu())
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            insertion(&rear,&front,data);
            break;
        case 2:
            deletion(&rear,&front);
            break;
        case 3:
            data = getFrontElement(front);
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
