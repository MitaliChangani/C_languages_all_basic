#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *A= (int*) malloc (n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        A[i]=i+1;
    }
    int *B=(int*)realloc(A,2*n*sizeof(int));
    printf("Pre.blockaddress=%d,New address=%d\n",A,B);
           for(int i=0;i<2*n;i++)
           {
            printf("%d\n",B[i]);
           }
           return 0;
} 
//Enter the size of array: 5
//Pre.blockaddress=28895936,New address=28895936
//1
//2
//3
//4
//5
//0
//132401
//0
//0
//0
