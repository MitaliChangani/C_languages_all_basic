#include<stdio.h>
int main()
{
    int area, length ,width;
    printf("enter the length :");
    scanf("%d",&length);
    printf("enter the width :");
    scanf("%d",&width);
    area=  length * width;
    printf("the area of rectangle:%d",area);
    return 0;
}