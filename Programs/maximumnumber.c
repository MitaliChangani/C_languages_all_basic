#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter three different number:");
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b && a>=c)
    {
        printf("the largest number is:%d",a);
    }
    else{
        if(b>=a && b>=c)
        {
            printf("the largest number is:%d",a);
        }
        else{
            printf("the largest number is:%d",c);
        }
    }
    return 0;
}