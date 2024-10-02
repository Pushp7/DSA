//Example of STACK using Linked list..

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int item;
    struct node *next;
};

void push(struct node **t,int data)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->next = *t;
    *t=n;
}

void pop(struct node **t)
{
    if(*t==NULL)
        printf("Stack is empty");
    else
    {
        struct node *r;
        r=*t;
        *t=r->next;
        free(r);
    }
}

int peek(struct node *top)
{
    if(top==NULL)
    {
        //printf("Stack is empty");
        return NULL;
    }
    else
        return top->item;
}

//void viewData(struct node *top)
//{
//    struct node *r1,*r2;
//    r1=r2=NULL;
//    while(top!=NULL)
//    {
//        r2=top->next;
//        top->next = r1;
//        r1 = top;
//        top = r2;
//    }
//
//    while(top!=NULL)
//    {
//        printf("%d ",top->item);
//        top=top->next;
//    }
//}

int menu()
{
    int choice;
    printf("1. Push Data into stack");
    printf("\n2. Pop Data from stack");
    printf("\n3. Peek stack");
    printf("\n4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    struct node *top=NULL;
    int data;
    while(1)
    {
        system("cls");
//        printf("Data in stack : ");
//        viewData(top);
        printf("\nTop : ");
        if(peek(top)==NULL)
            printf("empty");
        else
            printf("%d",peek(top));
        printf("\n..............................\n");
        switch(menu())
        {
            case 1:
                printf("Enter data\n");
                scanf("%d",&data);
                push(&top,data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                data = peek(top);
                if(data==NULL)
                    printf("Stack is empty");
                else
                    printf("%d",data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again\n");
        }
        getch();
    }
}
