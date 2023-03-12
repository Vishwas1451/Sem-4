#include<time.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include"time_header.h"
double time_elapsed(struct timespec start, struct timespec end)
{
   double t;
   //t= (end.tv_sec -start.tv_sec)
   t=(end.tv_nsec - start.tv_nsec) * 0.000000001;
    return t;
}
int main()
{
   struct timespec start;
   struct timespec end;
   clock_gettime(CLOCK_REALTIME,&start); //start the clock
   
   long int s=0;
   for(int i=0; i<1000; ++i)
   {
       for(int j=0; j<1000;++j)
	   {
			++s;
	   }
   
   }
    clock_gettime(CLOCK_REALTIME, &end);//get the end time
    printf("time %lf \n",time_elapsed(start,end));
    printf("s :%ld\n",s);	
    return 0;



}