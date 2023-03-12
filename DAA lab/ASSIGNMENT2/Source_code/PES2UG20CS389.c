#include "header.h"
#include <limits.h>
#include <string.h>
// ANY STATIC FUNCTIONS ARE UP HERE
int minTime(int V, int *time, int *s) {
   int min = INT_MAX;
   int min_index;
   for (int i = 0; i < V; i++)
	   if (s[i] == 0 && time[i] <= min) {
		   min = time[i];
		   min_index = i;
	   }
   return min_index;
}
int minimum_Time(int V, int *time, int *s,int key,const connection_t connections[V][V],int trip_order[V - 1],int g) {
   int min = INT_MAX;
   int min_index;
   printf("trip:%d\t",g);
   if(key==V-1){
	   if(connections[g][trip_order[0]].distance!=0 ){
		   	trip_order[g]=trip_order[0];
		return trip_order[0];
	   }
	   else
	      return -1;
   }
   for (int i = 0; i < V; i++)
	   if (s[i] == 0 && time[i] <= min) {
		   min = time[i];
		   min_index = i;
	   }
   return min_index;
}

static int dijkstra(int V, const connection_t connections[V][V], const int dest, const int src) {
	int time[V];
	int s[V];
	for (int i = 0; i < V; i++) {
		time[i] = INT_MAX;
		s[i] = 0;
	}
	time[src] = 0;
	for (int i = 0; i < V - 1; i++) {
		int m = minTime(V, time, s);
		s[m] = 1;
	    for (int n = 0; n < V; n++) {
			if (!s[n] && connections[m][n].time && time[m] != INT_MAX && time[m] + connections[m][n].time < time[n])
				time[n] = time[m] + connections[m][n].time;
		}
	}
	return time[dest];
}


static int dijkstra_distance(int V, const connection_t connections[V][V], const int dest, const int src, int trip_order[V - 1]) {
	int dist[V],g=1,key=0;
	int s[V];
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		s[i] = 0;
	}
	dist[src] = 0;
	for (int i = 0; i < V - 1; i++) {
		int m = minimum_Time(V, dist, s,key,connections,trip_order,trip_order[g-1]);
		key++;
		printf("%d\t",key);
		s[m] = 1;
		trip_order[g++]=m;
		if(key!=V-1){
	    for (int n = 0; n < V; n++) {
			if (!s[n] && connections[m][n].distance && dist[m] != INT_MAX && dist[m] + connections[m][n].distance < dist[n])
				dist[n] = dist[m] + connections[m][n].distance;
		}
		}
	}
	printf("\n");
	return dist[dest];
}



static int horspool(int n, const char *pat, const char *text) {
	int y = strlen(pat);
	char table[126];
	int i = 0;
	int flag = 0;
	int k = 0;

	for (int i = 0; i < 126; i++) {
		table[i] = y;
	}
	for (int j = 0; j < y-2; j++) {
		table[pat[j]] = y-1-j;
	}
	i = y-1;
	while (i <= n-1) {
		k = 0;
		while (k <= y-1 && pat[y-1-k] == text[i-k])
			k++;
		if (k == y) {
			flag = 1;
			return flag;
		}
		else
			i = i + table[text[i]];
	}
	return flag;
}

static void swap(airport_t *m, airport_t *n) {
    airport_t temp = *m;
    *m = *n;
    *n = temp;
}

static void heapify(airport_t airport[], int n, int i, int (*predicate_func)(const airport_t *, const airport_t *)) {
	int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && predicate_func(&airport[smallest], &airport[left]))
		smallest = left;

    if (right < n && predicate_func(&airport[smallest], &airport[right]))
		smallest = right;

    if (smallest != i) {
		swap(&airport[i], &airport[smallest]);
		heapify(airport, n, smallest, predicate_func);
	}
}

static void heap_sort(int n, airport_t airport[n], int (*predicate_func)(const airport_t *, const airport_t *)) {
    for (int i = n / 2 - 1; i >= 0; i--)
		heapify(airport, n, i, predicate_func);

    for (int i = n - 1; i >= 0; i--) {
		swap(&airport[0], &airport[i]);
		heapify(airport, i, 0, predicate_func);
	}
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for (; i < n; i++) {
		for (; j < n; j++) {
			if (connections[i][j].distance > 0 && connections[i][j].time > 0 && i != j && connections[i][j].distance != INT_MAX && connections[i][j].time != INT_MAX) {
				flag = 1;
			}
			else if (i == j && connections[i][j].distance != INT_MAX && connections[i][j].time != INT_MAX)
				flag = 1;
			else
				return flag = 0;
		}
	}
    return flag;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k, const connection_t connections[n][n])
{
	if (k < 0)
		return 0;
	if (connections[src -> num_id][dest -> num_id].distance != 0 && connections[src -> num_id][dest -> num_id].time != 0 && connections[src -> num_id][dest -> num_id].distance != INT_MAX && connections[src -> num_id][dest -> num_id].time != INT_MAX) {
        if(k >= 0)
          return 1;
    }
	for (int i = src -> num_id; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && connections[i][j].distance != 0 && connections[i][j].time != 0 && connections[i][j].distance != INT_MAX && connections[i][j].time != INT_MAX) {
				airport_t src_1;
				src_1.num_id = j;
				src_1.airport_name = src -> airport_name;
				airport_t dest_1;
				dest_1.num_id = dest -> num_id;
				dest_1.airport_name = dest -> airport_name;
				k--;
				if(q2(&src_1, &dest_1, n, k,connections)) {
					return 1;
                }
			}
		}
	}
	return 0;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
	int flag = 0;
	for (int i = src -> num_id; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i != j) && (connections[i][j].distance != 0 || connections[i][j].time != 0 || connections[i][j].distance != INT_MAX || connections[i][j].time != INT_MAX) && (connections[j][i].distance != 0 || connections[j][i].time != 0 || connections[j][i].distance != INT_MAX || connections[j][i].time != INT_MAX)) {
				flag = 1;
			}
		}
	}
	return flag;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),
        airport_t airport_list[n])
{
	heap_sort(n, airport_list, predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
	int m, y = 0;
	char s[10];
	char s1[10];
	for(int i = 0; i < n; i++) {
		strcpy(s1, airports[i].airport_name);
		for(int j = i+1; j < n; j++) {
			strcpy(s, airports[j].airport_name);
			m = strlen(airports[j].airport_name);
            int z = 0;
            while(z < m && (s[z] == s1[z]))
				z++;
			if(y < z) {
				y = z;
				ans.first = airports[i].num_id;
                ans.second = airports[j].num_id;
			}
		}
    }
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
	int l = 0;
	int h = n;
	int mid = (l+h)/2;
	if (entry_fee[0] > amount)
		return 0;
	if (entry_fee[n-1] < amount)
		return n;
	while (l != h) {
		if (entry_fee[mid] == amount)
			return mid+1;
		else if (entry_fee[mid] < amount) {
			l = mid;
			mid = (l+h)/2;
		}
		else {
			h = mid;
			mid = (l+h)/2;
		}
	}
    return 0;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
	for (int i = 0; i < n; i++) {
		if (horspool(n, pat, airports[i].airport_name))
			contains[i] = 1;
	}
}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
	int s;
	int d;
	int min = INT_MAX;
	int cost = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (connections[i][j].distance < min && connections[i][j].distance != 0) {
				min = connections[i][j].distance;
				s = i;
			}
		}
	}
	printf("%d %d\n",min,s);
		// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < n; j++) {
		// 	printf("%d\t", connections[i][j].distance);
		// }
		// printf("\n");
	// }
	int dmin = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (connections[i][s].distance < dmin && connections[i][s].distance != 0 && connections[i][s].distance != INT_MAX)
			d = i;
	}
    //printf("%d\n",d);
	trip_order[0]=d;
	cost = dijkstra_distance(n, connections, d, s, trip_order) + connections[d][s].distance;

	 printf("%d\t%d\t%d\n", s, d, cost);
	for (int i = 0; i < n; i++) {
		
			printf("%d\n", trip_order[i]);
		
	}
	if(cost<0){
		for (int i = 0; i < n-1; i++) {
		
			 trip_order[i]=-1;
		
	}
	cost=-1;
	}
	return cost;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
	int no_edge = 0;
	int selected[n-1];
	for (int i = 0; i < n-1; i++)
		selected[i] = 0;
	int x;
	int y;
	int cost = 0;
	while (no_edge < n - 1) {
		int min = INT_MAX;
		x = 0;
		y = 0;
		for (int i = 0; i < n; i++) {
			if (selected[i]) {
				for (int j = 0; j < n; j++) {
					if (!selected[j] && connections[i][j].time) {
						if (min > connections[i][j].time) {
							min = connections[i][j].time;
							x = i;
							y = j;
							edges[no_edge].first = i;
							edges[no_edge].second = j;
						}
					}
			    }
			}
		}
		cost = cost + connections[x][y].time;
		selected[y] = 1;
	    no_edge++;
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
	for (int i = 0; i < k; i++) {
		costs[i] = dijkstra(n, connections, destinations[i], src -> num_id);
	}
}

// END
