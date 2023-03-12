#include<time.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"time_header.h"


double time_elapsed(struct timespec start, struct timespec end)
{
   double t;
   //t= (end.tv_sec -start.tv_sec)
   t=(end.tv_nsec - start.tv_nsec) * 0.000000001;
    return t;
}