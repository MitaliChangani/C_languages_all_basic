#include<stdio.h>
int main()
{
  int a,b,c;
  printf("enter first values:");
  sacnf("%d",&a);
  printf("enter first values:");
  sacnf("%d",&b);
  c=a;
  a=b;
  b=c;
  printf("\n after swapping first number=",a);
  printf("\n after swapping first number=",b);
  return 0;
}