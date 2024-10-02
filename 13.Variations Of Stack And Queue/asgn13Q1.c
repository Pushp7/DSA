/*Example of two way stack using Array only*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct twStack              //tw: two way
{
    int top_stack1,top_stack2;
    int capacity;
    int *arr;
};

struct twStack* createStack(int size)
{
//    if(size>0)
//    {
        struct twStack *s;
        s = (struct twStack*)malloc(sizeof(struct twStack));
        s->capacity = size;
        s->top_stack1 = -1;
        s->top_stack2 = size;
        s->arr = (int*)malloc(sizeof(int)*size);
        return s;
//    }
//    else
//        exit(0);
}

void push1(struct twStack *s,int data)
{
    if(s->top_stack1+1==s->top_stack2 || s->top_stack1+1==s->capacity)
        printf("Stack is full.\a");
    else
    {
        s->top_stack1++;
        s->arr[s->top_stack1] = data;
    }
}

void push2(struct twStack *s,int data)
{
    if(s->top_stack1+1==s->top_stack2 || s->top_stack1+1==s->capacity)
        printf("Stack is full.\a");
    else
    {
        s->top_stack2--;
        s->arr[s->top_stack2] = data;
    }
}

void pop1(struct twStack *s)
{
    if(s->top_stack1==-1)
        printf("Front Stack is empty");
    else
        s->top_stack1--;
}

void pop2(struct twStack *s)
{
    if(s->top_stack2==s->capacity)
        printf("Rear Stack is empty");
    else
        s->top_stack2++;
}

int peek1(struct twStack *s)
{
    if(s->top_stack1==-1)
        return NULL;
    else
        return s->arr[s->top_stack1];
}

int peek2(struct twStack *s)
{
    if(s->top_stack2==s->capacity)
        return NULL;
    else
        return s->arr[s->top_stack2];
}

void viewStack1(struct twStack *s)
{
    int i;
    for(i=s->top_stack1;i>=0;i--)
        printf("%d ",s->arr[i]);
}

void viewStack2(struct twStack *s)
{
    int i;
//    for(i=s->top_stack2;i<s->capacity;i++)
    for(i=s->capacity-1;i>=s->top_stack2;i--)
        printf("%d ",s->arr[i]);
}

int menu()
{
    int choice;
    printf("1. Push from front side");
    printf("\n2. Push from rear side");
    printf("\n3. Pop from fron side");
    printf("\n4. Pop from rear side");
    printf("\n5. Peek from front side");
    printf("\n6. Peek from rear side");
    printf("\n7. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

int main()
{
    int size;
    struct twStack *s;
    printf("Enter size of stack\n");
    scanf("%d",&size);
    if(size>0)
        s=createStack(size);
    else
    {
        printf("Invalid size\a\n");
        exit(0);
    }
    while(1)
    {
        int data;
        system("cls");
        printf("..............................\n");
        printf("For Log inspection:\n\n");
        printf("Stack Capacity = %d",s->capacity);
        printf("\nData in stack: ");
        viewStack1(s);
        viewStack2(s);
        printf("\n\n..............................\n");
        switch(menu())
        {
        case 1:
            printf("Enter data\n");
            scanf("%d",&data);
            push1(s,data);
            break;
        case 2:
            printf("Enter data\n");
            scanf("%d",&data);
            push2(s,data);
            break;
        case 3:
            pop1(s);
            break;
        case 4:
            pop2(s);
            break;
        case 5:
            data = peek1(s);
            if(data==NULL)
                printf("Sorry!!! Front stack is empty");
            else
                printf("%d",data);
            break;
        case 6:
            data = peek2(s);
            if(data==NULL)
                printf("Sorry!!! Rear stack is empty");
            else
                printf("%d",data);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice. Retry!!!");
        }
    getch();
    }
}
