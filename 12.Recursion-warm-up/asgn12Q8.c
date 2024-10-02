/*Write a recursive function to calculate sum of first n even natural numbers*/
int sumEvenNatNum(int tn)
{
    if(tn==1){
        printf("%d ",2*tn);
        return 2*tn;
    }
    else
    {
        printf("%d+",2*tn);
        return 2*tn+sumEvenNatNum(tn-1);
    }
}
int main()
{
    int nTh,sum;
    printf("Enter nth term to sum first all even natural number\n");
    scanf("%d",&nTh);
    sum = sumEvenNatNum(nTh);
    printf("= %d",sum);
}

