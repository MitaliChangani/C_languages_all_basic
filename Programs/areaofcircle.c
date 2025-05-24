#include<stdio.h>
int main()
{
    int area, length;
    printf("enter the length of circle:");
    scanf("%d",&length);
    area= 3.14* length * length;
    printf("the area of circle:%d",area);
    return 0;
}