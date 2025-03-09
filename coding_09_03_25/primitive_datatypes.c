#include <stdio.h>
#include <string.h>

int main()
{
    // int choose=0;
    while(1)
    {
        int option;
        printf(" MENU\n");
        printf(" 1)INTEGER SUM\n 2)FLOAT SUM\n 3)CHAR ADDITION\n 4)EXIT\n");
        printf("Enter your option=");
        scanf("%d",&option);

        switch(option)
        {
            case 1: int a=0,b=0,sum=0;
                    printf("enter first integer=");
                    scanf("%d",&a);
                    printf("enter second integer=");
                    scanf("%d",&b);
                    sum=a+b;

                    printf("sum=%d\n",sum);
                    break;

            case 2: float c=0,d=0,sum1=0;
                    printf("Enter the first number=");
                    scanf("%f", &c);
                    printf("Enter the second number=");
                    scanf("%f",&d);
                    sum1=c+d;
                    printf("sum=%f\n",sum1);
                    break;
            case 3: char e[8], f[8];
                    printf("enter the first string=");
                    scanf("%s",e);
                    printf("enter the second string=");
                    scanf("%s",f);
                    strcat(e,f);
                    printf("Enter the final string=%s\n",e);
                    break;
            case 4: printf("exiting...");
                    return 0;
            default:
                    printf("Invalid Input. Try again\n");
        }

        // printf("Do you want to add another number(enter 1=yes or 0=no)=");
        // scanf("%d", choose);
    }

    return 0;
}
