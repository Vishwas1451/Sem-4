#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n,j,i,A[100];
	printf("enter the size:");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	i=1;
	while(A[i]!=1){
		i=2*i;
		for(j=i/2;j<=i;j++){
			if(A[j]==1){
				printf("element found at %d",j);
				break;
			}
		}
		
	}
	return 0;
}