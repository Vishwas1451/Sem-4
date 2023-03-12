#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
  double t;
  //t = (end.tv_sec -start.tv_sec);
  t = (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}
int main()
{
	struct timespec start;
	struct timespec end;
	int n,ele = 10,flag=0;
	n = 200000;
	int a[n];
	for(int i=0;i<n;i++)
		a[i]=rand()%100;
	clock_gettime(CLOCK_REALTIME, &start);
	for(int i=0;i<n && flag==0;i++)
	{
		if(a[i]==ele)
		{
			flag=1;
			printf("found");
		}
	}
	clock_gettime(CLOCK_REALTIME, &end);
	printf("%d\t",n);
	printf("%lf\n",time_elapsed(start, end));
	return 0;
	
}

/*
	run the program for various values of n
	*/