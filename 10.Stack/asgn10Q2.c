//Example of STACK using Dynamic Array..
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack
{
    int capacity;
    int top;
    int *ptr;
};

struct stack* createStack(int size)
{
    struct stack *S=NULL;
    S = (struct stack*)malloc(sizeof(struct stack));
    S->capacity = size;
    S->top = -1;
    S->ptr=(int*)malloc(sizeof(int)*size);
    return S;
}

void doubleStack(struct stack *s)
{
    s->ptr=(int*)realloc(s->ptr, 2*s->capacity * sizeof(int));
    s->capacity = 2*s->capacity;
}

void halfStack(struct stack *s)
{
    s->ptr=(int*)realloc(s->ptr, s->capacity/2 * sizeof(int));
    s->capacity = s->capacity/2;
}

void push(struct stack *S,int data)
{
    if(S->top==S->capacity-1)
        doubleStack(S);
    S->top++;
    S->ptr[S->top]=data;
}

void pop(struct stack *s)
{
    if(s->top==-1)
        printf("Stack is empty");
    else
    {
        s->top--;
        if(s->capacity/2==s->top+1)
            halfStack(s);
    }

}

int peek(struct stack *s)
{
    if(s->top==-1)
//        printf("Stack is empty");
        return NULL;
    else
        return s->ptr[s->top];
}

void viewData(struct stack *s)
{
    if(s->top==-1)
        printf("Stack is empty for now");
    else
    {
        int i;
        for(i=0;i<=s->top;i++)
            printf("%d ",s->ptr[i]);
    }
}

int menu()
{
    int choice;
    printf("\n1. Push Data into stack");
    printf("\n2. Pop Data from stack");
    printf("\n3. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    int stackSize;
    struct stack *S;
    printf("Enter size of STACK\n");
    scanf("%d",&stackSize);
    S = createStack(stackSize);
    while(1)
    {
        int data;
        system("cls");
        printf("Capacity of Stack: %d",S->capacity);
        printf("\nData in Stack : ");
        viewData(S);
        printf("\nTop : ");
        if(peek(S)==NULL)
            printf("none");
        else
            printf("%d",peek(S));
        printf("\n.......................................");
        switch(menu())
        {
        case 1:
            printf("Enter Data\n");
            scanf("%d",&data);
            push(S,data);
            break;
        case 2:
            pop(S);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Try again\n");
        }
        getch();
    }
    return 0;
}
