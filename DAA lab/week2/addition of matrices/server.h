#include<time.h>

double time_elapsed(struct timespec start,struct timespec end)
{
	double t;
	//t = (end.tv_sec-start.tv_sec);
	t = (end.tv_sec-start.tv_nsec)*0.000000001;
	return t;
}

struct timespec start; //two variables to store the start and end time
struct timespec end;