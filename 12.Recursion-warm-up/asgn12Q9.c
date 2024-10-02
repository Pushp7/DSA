/*Write a recursive function to calculate sum of first n odd natural numbers*/
int sumOddNatNum(int tn)
{
    if(tn==1){
        printf("%d ",2*tn-1);
        return 2*tn-1;
    }
    else
    {
        printf("%d+",2*tn-1);
        return (2*tn-1)+sumOddNatNum(tn-1);
    }
}
int main()
{
    int nTh,sum;
    printf("Enter nth term to sum first all odd natural number\n");
    scanf("%d",&nTh);
    sum = sumOddNatNum(nTh);
    printf("= %d",sum);
}

