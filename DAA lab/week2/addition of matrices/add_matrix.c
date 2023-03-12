#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"add_matrix_header.h"
int main()
{
  int i,j,m,n;
  struct timespec start;
  struct timespec end;
  printf("Enter the number of rows: ");
  scanf("%d",&m);
  printf("Enter the number of columns: ");
  scanf("%d",&n);
  int a[100][100];
  int b[100][100];
  int sum[100][100];
  printf("First Matrix: \n");
  
  first_matrix(a,m,n);
  
printf("Second Matrix: \n");
second_matrix(b,m,n);
  
  clock_gettime(CLOCK_REALTIME, &start);
  printf("Sum of two Matrices: \n");
  sum_matrix(a,b,sum,m,n);
  
  clock_gettime(CLOCK_REALTIME, &end);
  printf("time %lf \n", time_elapsed(start, end));
}
