/*Write a recursive function to calculate sum of squares of first n natural numbers*/
int sumNatNumSqr(int tn)
{
    if(tn==1){
        printf("%d^2",tn);
        return tn*tn;
    }
    else
    {
        printf("%d^2 + ",tn);
        return tn*tn+sumNatNumSqr(tn-1);
    }
}
int main()
{
    int nTh,sum;
    printf("Enter nth term to find the sum of squares of first all natural number\n");
    scanf("%d",&nTh);
    sum=sumNatNumSqr(nTh);
    printf(" = %d",sum);
}
