#include<stdio.h>
#include<stdlib.h>

void hanoi(int n){
	
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
	hanoi(n);
	return 0;
}
