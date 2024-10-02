/*Write a recursive function to print first n natural numbers in reverse order.*/

reversePrint(int tn)
{
    if(tn>0){
        printf("%d ",tn);
        reversePrint(tn-1);
    }
}
int main()
{
    int nth;
    printf("Enter nth term to print natural number in reverse order\n");
    scanf("%d",&nth);
    reversePrint(nth);
}
