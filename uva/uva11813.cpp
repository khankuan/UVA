#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int V,E,c;
vector<pair<int,int> > adjList[100005];

int* minD[12];
int shoppingList[12];
long memo[12][1 << 12];


long DP_Market(int u, int vis) {
	if (vis == (1 << c) - 1)	//	if all visited, go back to counter
		return minD[u][0];
	if (memo[u][vis] != -1)	//	memoised
		return memo[u][vis];
	memo[u][vis] = 100000000;	//	default

	//	add weight between u to next item and set next item visited bit as visited
	for (int i = 0; i < c; i++) {
		if (((vis >> i) & 1) == 0) {
			memo[u][vis] = min(memo[u][vis], minD[u][i + 1]
					+ DP_Market(i + 1, vis | (1 << i)));
		}
	}
	
	return memo[u][vis];
}



int* Dijkstra(int source){
    priority_queue<pair<int,int> > Q;
    int weights[V];
    for (int i = 0; i < V; i++)
        weights[i] = 100000000;
    weights[source] = 0;
    Q.push(make_pair(0, source));
    
    while (!Q.empty()){
        pair<int,int> cur = Q.top(); Q.pop();
        if (cur.first > weights[cur.second])
           continue;
        
        bool isOver = true;
        for (int u = 0; u < c; u++){	//	check if all require items are reached
        	if (weights[cur.second] < weights[shoppingList[u]] && cur.second != shoppingList[u]){
        		isOver = false;
        		break;
        	}
        }
        if (isOver == true){
            if (weights[cur.second] >= weights[0]) 
            	break;
         }
        	
        for (int i = 0; i < adjList[cur.second].size(); i++) {
            int next = adjList[cur.second][i].first;
        	if (cur.first + adjList[cur.second][i].second < weights[next]) {
        		weights[next] = cur.first + adjList[cur.second][i].second ;
        		Q.push(make_pair(weights[next], next));
        	}
        }
    }
    
    int* items_weight;
    items_weight = new int[12];
	items_weight[0] = weights[0];
	for (int j = 0; j < c; j++)
		items_weight[j + 1] = weights[shoppingList[j]];
		

	return items_weight;
}

int main(void){
    for (int i = 0; i < 12; i++)
        minD[i] = new int[12];
    int testcount;
    scanf("%d",&testcount);
    for (int test = 0; test < testcount; test++){
        scanf("%d %d",&V,&E);
       
        int from, to, amt;
        for (int i = 0; i < E; i++){
            scanf("%d %d %d",&from,&to,&amt);
            adjList[from].push_back(make_pair(to,amt));
            adjList[to].push_back(make_pair(from,amt));
        }
        
        scanf("%d",&c);

        for (int i = 0; i < c; i++)
            scanf("%d",&shoppingList[i]);
        
        for (int i = 0; i < c; i++)
            minD[i+1] = Dijkstra(shoppingList[i]);
            
        for (int i = 1; i < c+1; i++)
            minD[0][i] = minD[i][0];
        
        minD[0][0] = 0;
        memset(memo,-1,sizeof memo);
        
        DP_Market(0,0);
        if (memo[0][0]) == -1)
           memo[0][0] = 0;
        printf("%ld\n",memo[0][0]);
    }


    return 0;
}
