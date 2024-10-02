/*Write recursive function to print first n even natural numbers.*/
void evenNatural(int N)
{
    if(N>0)
    {
        evenNatural(N-1);
        printf(" %d",2*N);
    }
}
int main()
{
    int n;
    printf("Enter how many first even natural numbers want to print\n");
    scanf("%d",&n);
    evenNatural(n);
}
