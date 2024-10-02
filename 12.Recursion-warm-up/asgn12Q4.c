/*Write a recursive function to print first n even natural numbers in reverse order.*/
void evenNaturalReverse(int N)
{
    if(N>0)
    {
        printf("%d ",2*N);
        evenNaturalReverse(N-1);
    }
}
int main()
{
    int n;
    printf("Enter how many first even natural numbers want to print(in reverse order)\n");
    scanf("%d",&n);
    evenNaturalReverse(n);
}
