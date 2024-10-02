/*Write a recursive function to find nth term of a fibonacci series*/
#include<stdio.h>
void fibonacci(int);
void fibonacci(int t)
{
    static int a=-1,b=1;
    int c;
    if(t>0){
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
        fibonacci(t-1);
    }
}
int main()
{
    int T;
    printf("Til how many terms you want to print fibonacci series\n");
    scanf("%d",&T);
    fibonacci(T);
    return 0;
}

//without recursion
//void fibonacci(int t)
//{
//    int a=-1,b=1,c,i;
//    for(i=0;i<t;i++)
//    {
//        c=a+b;
//        a=b;
//        b=c;
//        printf("%d ",c);
//    }
//}
