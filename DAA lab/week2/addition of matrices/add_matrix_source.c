#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"add_matrix_header.h"
double time_elapsed(struct timespec start, struct timespec end)
{
  double t;
  //t = (end.tv_sec -start.tv_sec);
  t = (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}
void first_matrix(int a[100][100], int m, int n){
	int i,j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      a[i][j]=(rand()%100);
      printf("%d ",a[i][j]);

    }
    printf("\n");
  }
}
void second_matrix(int b[100][100], int m, int n){
	int i,j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      b[i][j]=(rand()%100);
      printf("%d ",b[i][j]);

    }
    printf("\n");
  }
}
void sum_matrix(int a[100][100],int b[100][100],int sum[100][100], int m, int n){
	int i,j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      sum[i][j]=a[i][j]+b[i][j];
      printf("%d ",sum[i][j]);

    }
    printf("\n");
  }
}