/*Tower of Hanoi(TOH)*/

#include<stdio.h>
void TOH(int n,char beg,char aux,char end)
{
    if(n>0)
    {
        TOH(n-1,beg,end,aux);
        printf("\n%c -> %c",beg,end);
        TOH(n-1,aux,beg,end);
    }
}
int main()
{
    int n;
    printf("Enter the number of disc in a tower(TOH)....\n");
    scanf("%d",&n);
    printf("\nsteps: ");
    TOH(n,'A','B','C');
    getch();
}
