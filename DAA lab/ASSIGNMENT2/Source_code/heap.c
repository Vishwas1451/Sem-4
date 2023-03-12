// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 
#include <string.h>
#define INF 9999999

    #include <conio.h>
    #include <stdlib.h>
    // int i,j,k,a,b,u,v,n,ne=1;
    // int min,mincost=0,cost[4][4],parent[4];
    int parent[4];
  int find(int i)
    {
    	while(parent[i])
    	i=parent[i];
    	return i;
    }
    int uni(int i,int j)
    {
    	if(i!=j)
    	{
    	parent[j]=i;
    	return 1;
    	}
    	return 0;
    }
    void main()
    {
      int i,j,k,a,b,u,v,n,ne=1;
    int min,mincost=0,cost[4][4];//parent[4];
    	n=4;
      printf("kkk\n");
      int maxi[4][4]={{999,2,6,999},
                  {2,999,5,1},
                  {6,5,999,7},
                  {999,1,5,999},
                  };
      for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cost[x][y]=maxi[x][y];
            if( maxi[x][y]==0){
                cost[x][y]=999;
            }
        }
    }    
    printf("kkk\n");        
    	while(ne < n)
    	{
    	for(i=0,min=999;i<n;i++)
    	{
    	for(j=0;j < n;j++)
    	{
        // printf("kkk\n");
    	if(cost[i][j] < min)
    	{
    	min=cost[i][j];
    	a=u=i;
    	b=v=j;
    	}
    	}
    	}
      printf("kkk");
    	int u=find(u);
    	int v=find(v);
    	if(uni(u,v))
    	{
    	printf("(%d,%d)\n",a,b);
      ne=ne+1;
    	mincost +=min;
      printf("kkk");
    	}
    	cost[a][b]=cost[b][a]=999;
      printf("kkk");
    	}
    	printf("\n\tMinimum cost = %d\n",mincost);
    
    }
