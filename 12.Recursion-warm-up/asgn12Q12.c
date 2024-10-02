/*Write a recursive function to print binary equivalent of a given decimal number.*/
int decimal2Binary(int deciNum)
{
    if(deciNum>0)
    {
        r=deciNum%2;
        deciNum/=2
        decimal2Binary(deciNum);
    }
}
int main()
{
    int num,binNum;
    printf("Enter any decimal number and Get equivalent binary number\n");
    scanf("%d",&num);
    binNum = decimal2Binary(num);
    printf("Binary equivalnet = %d",binNum);
}
