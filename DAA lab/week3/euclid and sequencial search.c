#include<stdio.h>
#include <time.h>
#include<math.h>
#include <stdlib.h>
double time_elapsed(struct timespec start, struct timespec end)
{
  double t;
  //t = (end.tv_sec -start.tv_sec);
  t = (end.tv_nsec - start.tv_nsec)*0.00000001;
  return t;
}
void time_calc(int A[],int k, int n){
	int count=0;
	for(int i=0;i<k;i++){
		if(A[i]==n){
			
			//clock_gettime(CLOCK_REALTIME, &end);
			printf("found");
			//break;
			
		}
	}
	//return count;
}
int main(){
	struct timespec start;
    struct timespec end;
	int k=90000;
	int A[k];
	for(int i=0;i<k;i++){
		A[i]=i;
		//printf("%d ",A[i]);
	}
	int f=89999;
	clock_gettime(CLOCK_REALTIME, &start);
	time_calc(A,k,f);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("%d\t",k);
    printf("time %lf \n", time_elapsed(start, end));
	return 0;
}
/*
//sequencial search 2
int main(){
	int i=0;
	int A[]={1,2,3,4,5}
	int k=42;
	A[5]=k;
	while(A[i]!=k)
	{
		i++;
	}	
	if(i<n)
		return i;
	else 
		return -1;
	return 0;
}
//euclid's algorythm to find gcd of two numbers
int main()
{
	printf("enter 2 numbers to find gcd");
	int a,b;
	scanf("%d %d",&a,&b);
	int i=0;
	int x = gcd(a,b);
	printf("the gcd of two numbers is %d",x);
	return 0;
	
}
int gcd(int a, int b)
{
	
	while(b!=0){
		a=b;
		b=a%b;
	}
	return a;
}
//program to convert binary number to decimal number
int convert(long long);
int main() {
  long long n;
  printf("Enter a binary number: ");
  scanf("%lld", &n);
  printf("%d in decimal",convert(n));
  return 0;
}
int convert(long long n) {
  int d=0,i=0,r;
  while (n!=0) {
    r = n % 10;
    n /= 10;
    d += r * pow(2, i);
    ++i;
  }
  return d;
}
*/

