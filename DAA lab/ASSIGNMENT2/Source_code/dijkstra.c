#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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
    int min,mincost=0,cost[4][4],parent[4];
	
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	//printf("\nEnter the cost adjacency matrix:\n");
    for(int x=0;x<n;x++){
//         for(int y=0;y<n;y++){
//             cost[x][y]=connections[x][y].time;
//             if( connections[x][y].time==0 || connections[x][y].time==INT_MAX){
//                 cost[x][y]=999;
//             }
//         }
//     } 
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=0,min=999;i<n;i++)
		{
			for(j=0;j < n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	
}
