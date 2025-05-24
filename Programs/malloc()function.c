#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *myArray= (int*) malloc (n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        myArray[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\t",myArray[i]);
    }
} //output: Enter the size of array: 5 ;1  2  3  4  5