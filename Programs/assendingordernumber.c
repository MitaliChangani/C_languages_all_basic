#include<stdio.h>
int main()
{
    int arr[5];
    int i,j,a;
    printf("enter the element:");
    scanf("%d",&i);
    for(i=0;i<5;i++)
    {
        printf("%d",&arr[i]);
    }
    for (i = 0; i < 5; i++)
	{
      for(j=i+1;j<5;j++)
      {
        if(arr[i]>arr[j])
        {
          a=arr[i];
          arr[i]=arr[j];
          arr[j]=a;
        }
      }
	}
    printf("\nArray of Elemenst in Ascending Order are :\n");
    for(i=0;i<5;i++)
    {
        printf("%d",&arr[i]);
    }
    return 0;
}