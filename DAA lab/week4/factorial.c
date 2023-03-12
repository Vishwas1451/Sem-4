#include<stdio.h>
#include<stdlib.h>

void factorial(int n){
	
	int fact=1;
	while(n!=0){
		fact = n*fact;
		n--;
	}
	printf("The factorial is:%d",fact);
}



int main(){
	
	int n;
	printf("Enter the number to find it's factorial:");
	scanf("%d",&n);
	factorial(n);
	return 0;
}