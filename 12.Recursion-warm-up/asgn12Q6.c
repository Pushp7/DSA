/*Write a recursive function to print first n odd natural numbers in reverse order*/
void oddNaturalReverse(int N)
{
    if(N==1)
        printf("%d ",2*N-1);
    else
    {
        printf("%d ",2*N-1);
        oddNaturalReverse(N-1);
    }
}
int main()
{
    int n;
    printf("Enter how many first odd natural numbers you want to print(in reverse order)\n");
    scanf("%d",&n);
    oddNaturalReverse(n);
}
