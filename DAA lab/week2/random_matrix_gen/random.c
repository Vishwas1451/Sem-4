#include <stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n;
	printf("enter the dimension of n: ");
	scanf("%d",&n);
	srand(time(0));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t", rand()%1000);
		}	
	printf("\n");	
	}	
	return 0;
}