#include<stdio.h>
#include<stdlib.h>

void fibonacci(int n){
	
	int x,i,a=0,b=1,sum;
	for(i=0;i<n;i++){
		printf("\t");
		printf("%d",a);
		sum=a+b;
		a=b;
		b=sum;		
	}
	
}



int main(){
	
	int n;
	printf("Enter the number :");
	scanf("%d",&n);
	fibonacci(n);
	return 0;
}
