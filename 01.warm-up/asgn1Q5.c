#include<stdio.h>
#include<conio.h>

struct Temp
{
    int minTemp,maxTemp;
};

int minAvg(struct Temp d[],int totalDays)
{

}

int maxAvg(struct Temp d[],int totalDays)
{

}

int main()
{
    int days,i;
    struct Temp t[40];
    printf("Enter no. of days: ");
    scanf("%d",&days);
//  struct Temp t= (struct Temp*)malloc(days * sizeof(struct Temp));
    printf("Now enter min and max temperature of cosecutive %d days\n",days);
    for(i=0;i<days;i++)

    {
        printf("Day %d.) Minimum Temperature : ",i+1);
        scanf("%d",t[i].minTemp);
        printf("Day %d.) Maximum Temperature : ",i+1);
        scanf("%d",t[i].maxTemp);
    }
    for(i=0;i<days;i++)
    {
        printf("\n%d    %d",&t[i].minTemp,&t[i].maxTemp);
    }

    getch();
}
