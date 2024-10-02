/*Write a recursive function to calculate sum of digits of a given number*/
int digitSum(int n)
{
    if(n>0)
        return (n%10)+digitSum(n/10);
}

int main()
{
    int num,sum;
    printf("Enter any Number to sum its digits\n");
    scanf("%d",&num);
    sum = digitSum(num);
    printf("%d",sum);
}
