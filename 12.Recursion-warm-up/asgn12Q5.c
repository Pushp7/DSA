/*Write a recursive function to print first n odd natural numbers*/
void oddNatural(int N)
{
    if(N>0)
    {
        oddNatural(N-1);
        printf("%d ",2*N-1);
    }
}
int main()
{
    int n;
    printf("Enter how many first odd natural numbers you want to print\n");
    scanf("%d",&n);
    oddNatural(n);
}
