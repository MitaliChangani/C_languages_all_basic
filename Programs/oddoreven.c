#include<stdio.h>
int main()
{
    int i, n;
    printf("enter the number:");
    scanf("%d",&n);
    if(n/2==0)
    {
        printf("the number is even");
    }
    else{
        printf("the number is odd");
    }
    return 0;
}