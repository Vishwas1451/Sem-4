#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "multiplication_matrix_header.h"
struct timespec start;
struct timespec end;
double time_elapsed(struct timespec start, struct timespec end)
{
  double t;
  //t = (end.tv_sec -start.tv_sec);
  t = (end.tv_nsec - start.tv_nsec) * 0.000000001;
  return t;
}

void first_matrix(int a[100][100],int m,int n){
	int i,j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      a[i][j]=(rand()%10);
      printf("%d ",a[i][j]);

    }
    printf("\n");
  }
}
void second_matrix(int b[100][100],int m,int n){
	int i,j;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      b[i][j]=(rand()%10);
      printf("%d ",b[i][j]);

    }
    printf("\n");
  }
}
void multiply_matrix(int a[100][100],int b[100][100],int c[100][100],int m,int n,int q,int l){
int i,j,k;
if(m==q){
  for(i=0;i<m;i++)
  {
  for(j=0;j<l;j++)
  {
  c[i][j]=0;
  for(k=0;k<n;k++)
  {
  c[i][j]+=a[i][k]*b[k][j];
  }
  }
}
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    printf("%d ",c[i][j]);
    printf("\n");
  }
}
else 
	printf("cannot multiply");
}
