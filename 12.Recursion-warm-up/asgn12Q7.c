/*Write a recursive function to calculate sum of first n natural numbers*/
int sumNatNum(int tn)
{
    if(tn==1){
        printf("%d ",tn);
        return tn;
    }
    else
    {
        printf("%d+",tn);
        return tn+sumNatNum(tn-1);
    }
}
int main()
{
    int nTh,sum;
    printf("Enter nth term to sum first all natural number\n");
    scanf("%d",&nTh);
    sum=sumNatNum(nTh);
    printf("= %d",sum);
}
