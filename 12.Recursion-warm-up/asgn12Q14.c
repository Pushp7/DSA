/*Write a recursive function to print reverse of a given number.*/
#include<stdio.h>
int reverseDigits(int);
int reverseDigits(int num)
{
    static int rev=0;
    if(num==0)
        return rev;
    rev=rev*10+(num%10);
    reverseDigits(num/10);
}
int main()
{
    int num;
    printf("Enter any number to reverse digits\n");
    scanf("%d",&num);
    printf("Reversed Number is %d",reverseDigits(num));
}

//reverse function using loop....
//int reverseDigits(int num)
//{
//    int rem,rev=0;
//    while(num>0)
//    {
//        rem=num%10;
//        rev=rev*10+rem;
//        num=num/10;
//    }
//    return rev;
//}
