#include "header.h"
#include <limits.h>
#include <string.h>
//#include <conio.h>
#include <stdlib.h>

// ANY STATIC FUNCTIONS ARE UP HERE
static void swap(airport_t *a, airport_t *b) {
    airport_t temp = *a;
    *a = *b;
    *b = temp;
  }
  
  static void heap( int n,airport_t airport_list[n], int i,int (*predicate_func)(const airport_t *, const airport_t *)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && predicate_func(&airport_list[left],&airport_list[largest]))
      largest = left;
  
    if (right < n && predicate_func(&airport_list[right],&airport_list[largest]))
      largest = right;
  
    if (largest != i) {
      swap(&airport_list[i], &airport_list[largest]);
      heap(n,airport_list, largest,predicate_func);
    }
  }
  
  
 static void Sort(int n, airport_t airport_list[n],int (*predicate_func)(const airport_t *, const airport_t *)) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
      heap(n,airport_list,i,predicate_func);
  
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&airport_list[0], &airport_list[i]);
  
      
      heap(i,airport_list,0,predicate_func);
    }
  }
static void table(char p[],char t[]) {
	int i,j,m;
	m=strlen(p);
	for (i=0;i<100;i++)
	  t[i]=m;
	for (j=0;j<m-1;j++)
	  t[p[j]]=m-1-j;
}
static int horse(char src[],char p[],char t[]) {
	int i,k,m,n;
	n=strlen(src);
	m=strlen(p);
	i=m-1;
	while(i<n) {
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
		   k++;
		if(k==m)
		   return 1; else
		   i+=t[src[i]];
	}
	return 0;
}

static int min_Dists(int n,int dist[n], int Sets[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (Sets[v] == 0 && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
static int short_time(int n,const connection_t connections[n][n], int src,int dest)
{
	int dist[n];
	int Sets[n]; 
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, Sets[i] = 0;
    
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
	    int u = min_Dists(n,dist, Sets);
        Sets[u] = 1;
        for (int v = 0; v < n; v++)
        if (!Sets[v] && connections[u][v].time && dist[u] != INT_MAX && dist[u] + connections[u][v].time < dist[v]) 
              dist[v] = dist[u] + connections[u][v].time;
	}
    return dist[dest];
}
static int minimum(int n,int dist[n], int Sets[],int dest)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
      if(dest!=v){
		if (Sets[v] == 0 && dist[v] <= min)
			min = dist[v], min_index = v;
      }
	return min_index;
}
static int shorty(int n,const connection_t connections[n][n], int src,int dest,int arr[n])
{
	int dist[n],r=0;
	int Sets[n]; 
	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, Sets[i] = 0;
    
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
	    int u = minimum(n,dist, Sets,dest);
        Sets[u] = 1;
        arr[r]=u;
        r++;
        for (int v = 0; v < n; v++)
        if (!Sets[v] && connections[u][v].distance && dist[u] != INT_MAX && dist[u] + connections[u][v].distance < dist[v]) 
              dist[v] = dist[u] + connections[u][v].distance;
	}
    return dist[dest];
}

static int isSafe(int V,int v, int graph[V][V], int path[], int pos,int key)
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

static int hamiltonLap(int V,int graph[V][V], int path[], int pos,int key,int r)
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

static int hamilton(int V,int graph[V][V],int cost,int path1[V])
{
    int r,flag;
	int *path;
    path = (int*) malloc((V) * sizeof(int));
    //path1 = (int*) malloc((V) * sizeof(int));
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
    if(flag==1){    
      //print(V,path1,cost);
       for(int x=0;x<V;x++){
           path1[x]=-1;
        } 
        cost=-1;
        //print(V,path1,cost);
    }
	return cost;
}
// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!(i==j)){
                if(connections[i][j].distance==0 || connections[i][j].time==0 || connections[i][j].distance==INT_MAX || connections[i][j].time==INT_MAX){
                   return 0;
                }
            }
        }
    }
    return 1;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
{

    int y=src->num_id;
    int z=dest->num_id;
    if(k<=0)
      return 0;
    if(connections[y][z].distance!=0 && connections[y][z].time!=0 && connections[y][z].distance!=INT_MAX && connections[y][z].time!=INT_MAX){
        if(k>0)
          return 1;
    }
    else{
        for(int i=y;i<n;i++){
            for(int j=0;j<n;j++){
             if(i!=j){
               if(connections[i][j].distance!=0 && connections[i][j].time!=0 && connections[i][j].distance!=INT_MAX && connections[i][j].time!=INT_MAX){
                   airport_t src1={j,src->airport_name};
                   airport_t dest1={dest->num_id,dest->airport_name};
                   k--;
                   if(q2(&src1, &dest1, n, k,connections)){
                       return 1;
                   }
                }
                
            }
        }
        }
    }
   return 0;

}
    


int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int i,j;
    for(i=src->num_id;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
               if(connections[i][j].distance!=0 || connections[i][j].time!=0 || connections[i][j].distance!=INT_MAX || connections[i][j].time!=INT_MAX){
                   int x;
                   x=j;
                    if(connections[x][i].distance==0 || connections[x][i].time==0 || connections[x][i].distance==INT_MAX || connections[x][i].time==INT_MAX){
                         return 0;
                    }
               }  
            }
        }
    }
    return 1;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),
        airport_t airport_list[n])
{
     Sort(n,airport_list,predicate_func);
     for(int i = 0; i<n/2; i++){
        airport_t temp = airport_list[i];
        airport_list[i] = airport_list[n-i-1];
        airport_list[n-i-1] = temp;
    }
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int m,i,j=0;
    for(int k=0;k<n;k++){
        for(int l=k+1;l<n;l++){
            char text[10];
            char pat[10];
            strcpy(pat,airports[k].airport_name);
            strcpy(text,airports[l].airport_name);
            n=strlen(airports[k].airport_name);
            m=strlen(airports[l].airport_name);
            for(i=0; i<=n-m; i++){
                int y=0;
                while(y<m && (pat[y]==text[y]))
                    y++;

             if(j<y){
                 j=y;
                    ans.first=airports[k].num_id;
                    ans.second=airports[l].num_id;
            }
    }
    }
    }
	
	

    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    int max=0;
    for(int i=0;i<n;i++){
        if(amount>=entry_fee[i]){
            max++;
        }
    }
    return max;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    int pos;
    char t[100],pattern[10];
    strcpy(pattern,pat); 
    table(pattern,t);
    for(int i=0;i<n;i++){
       char src[10];
       strcpy(src,airports[i].airport_name); 
	   pos=horse(src,pattern,t);
       contains[i]=pos;
    } 
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int V=n,cost=0,graph[n][n],cost1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=connections[i][j].distance;
            if(connections[i][j].distance==INT_MAX){
                graph[i][j]=0;
            }
        }
    }
    cost1=hamilton(n,graph,cost,trip_order);
    return cost1;
}

 int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
  {
    int e = 0;
	int sel[n-1];
	for (int i = 0; i < n-1; i++)
		sel[i] = 0;
	int q;
	int w;
	int cost = 0;
	while (e < n - 1) {
		int m = INT_MAX;
		q = 0;
		w = 0;
		for (int i = 0; i < n; i++) {
			if (sel[i]) {
				for (int j = 0; j < n; j++) {
					if (!sel[j] && connections[i][j].time) {
						if (m > connections[i][j].time) {
							m = connections[i][j].time;
							q = i;
							w = j;
							edges[e].first = i;
							edges[e].second = j;
						}
					}
			    }
			}
		}
		cost = cost + connections[q][w].time;
		sel[w] = 1;
	    e++;
  }
  	pair_t edges1[n - 1];
	
	for (int i = 0; i < 2; i++) {
		edges1[i].first = edges[i].first;
		edges1[i].second = edges[i].second;
	}

	edges1[2].first = edges[2].first;
	edges1[2].second = edges[2].second;

	for (int i = 0; i < n; i++) {
		edges[i].first = edges1[i].first;
		edges[i].second = edges1[i].second;
	}
	return cost;
  }

void q10(int n, int k, const airport_t *src,
         const connection_t connections[n][n], const int destinations[k],
         int costs[k])
{
   for(int i=0;i<k;i++){
    int u = short_time(n,connections,src->num_id,destinations[i]);
    costs[i]=u;
   } 
}

// END
