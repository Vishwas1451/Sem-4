#include<stdio.h>
#include<stdlib.h>

void print(int V,int path[],int r);

int isSafe(int V,int v, int graph[V][V], int path[], int pos,int key)
{

    if(pos==V){
        if(graph [ path[pos] ][ path[0] ] == 0){
            return 0;
        }
        else{
            return 1;
        }
    }
	if (graph [ path[pos-1] ][ v ] == 0)
		return 0;

	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return 0;

	return 1;
}

int hamiltonLap(int V,int graph[V][V], int path[], int pos,int key,int r)
{

	if (pos == V-1)
	{

		if ( graph[ path[pos-1] ][ path[0] ] !=0 )
		return 1;
		else
		return 0;
	}
    
	for (int v = 0; v < V; v++)
	{
        if(path[0]!=v){

        if(pos==4)
          v=path[0];
		if(isSafe(V,v, graph, path, pos,key))
		{
            path[pos] = v;
			if (hamiltonLap (V,graph, path, pos+1,key,r) == 1)
				return 1;
			path[pos] = -1;
		}
        }
	}
	return 0;
}

int hamilton(int V,int graph[V][V],int cost)
{
    int r,flag;
	int *path,*path1;
    path = (int*) malloc((V) * sizeof(int));
    path1 = (int*) malloc((V) * sizeof(int));
	for (int i = 0; i < V; i++)
		path[i] = -1;
    int key=0;
     for(int x=0;x<V;x++){
	    path[0] = x;
        path[3]=x;
         r=0;
	if ( hamiltonLap(V,graph, path, 1,key,r) == 0 )
	{
		//printf("\nSolution does not exist");
		//return 0;
	}
    for(int f=0;f<3;f++){
        r=r+graph[path[f]][path[f+1]]; 
     }
    if(x==0){
        cost=r;
        for(int x=0;x<V;x++){
            path1[x]=path[x];
        }    
    }
    else if(cost>r){
         cost=r;
        for(int x=0;x<V;x++){
            path1[x]=path[x];
        } 
    }
    }
     for(int x=0;x<V;x++){
           if(path1[x]==-1)
            flag=1;
        } 
    if(flag!=1)    
      print(V,path1,cost);
    else{
       for(int x=0;x<V;x++){
           path1[x]=-1;
        } 
        cost=-1;
        print(V,path1,cost);
    }
	return 1;
}

void print(int V,int path[],int r)
{
	printf ("Solution Exists:"
			" Following is one Hamiltonian Cycle \n");
             printf("%d\n",r);
	for (int i = 0; i < V; i++)
		printf(" %d ", path[i]);

	printf("\n");
}


int main()
{
int V=3;
//int graph1[4][4]={0,7,3,5,0,0,0,1,0,2,0,4,4,0,6,0};
//graph1[V][V]

    int cost=0;
	// hamilton(V,graph1,cost);

	int graph2[3][3] = {{0, 1, 0},
					{0, 0, 2},
					{3, 0, 0}
					};

 hamilton(V,graph2,cost);

	return 0;
}
