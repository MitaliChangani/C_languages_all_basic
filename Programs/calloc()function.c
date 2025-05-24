#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *myArray= (int*) calloc (n,sizeof(int));

    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",myArray[i]);
    }
} //output :Enter the size of array: 5 ; 0  0  0  0  0