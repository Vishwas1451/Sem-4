#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"multiplication_matrix_header.h"

int main()
{
  int i,j,k,m,n,l;
  struct timespec start;
  struct timespec end;
  printf("Enter the number of rows of 1st matrix: ");
  scanf("%d",&m);
  printf("Enter the number of columns of 1st matrix: ");
  scanf("%d",&n);
 
 int a[100][100];
  int b[100][100];
  int c[100][100];
  printf("First Matrix: \n");
  first_matrix(a,m,n);
   printf("Enter the number of rows of 2nd matrix: ");
  scanf("%d",&k);
  printf("Enter the number of columns of 2nd matrix: ");
  scanf("%d",&l);
  
printf("Second Matrix: \n");
second_matrix(b,k,l);
  
  printf("Product of two Matrics: \n");
  clock_gettime(CLOCK_REALTIME, &start);
  multiply_matrix(a,b,c,m,n,k,l);
  

  clock_gettime(CLOCK_REALTIME, &end);
  printf("time %lf \n", time_elapsed(start, end));
}
