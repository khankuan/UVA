#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int main(void){
    int V,E,hotelcount;
    while(true){
        scanf("%d",&V);
        if (V == 0)
           break;
        vector<pair<int,int> > adjList[V];
        bool hotels[V];
        memset(hotels,false,sizeof hotels);
        
        scanf("%d",&hotelcount);
        int input;
        for (int i = 0; i < hotelcount; i++){    
            scanf("%d",&input);
            input--;
            if (input == 0 || input == V-1)
               continue;
            hotels[input] = true;
        }
            
        scanf("%d",&E);
        for (int i = 0; i < E; i++){
            int from,to,amt;
            scanf("%d %d %d",&from,&to,&amt);
            from--;
            to--;
            adjList[from].push_back(make_pair(to,amt));
            adjList[to].push_back(make_pair(from,amt));
        }
        
        int weights[V];
        for (int i = 0; i < V; i++)
            weights[i] = 100000000;
        int source = 0;
        weights[source] = 0;
        priority_queue<pair<int,pair<int,int> > > Q;
        Q.push(make_pair(0, make_pair(source,0)));
        
        int ans = -1;
        while (!Q.empty()){
            pair<int,pair<int,int> > cur = Q.top(); Q.pop();
      	    if (cur.first > weights[cur.second.first])
               continue; 
            if (cur.second.first == V-1){
               ans = cur.first;
               break;         	
            }
            for (int i = 0; i < adjList[cur.second.first].size(); i++) {
                int next = adjList[cur.second.first][i].first;
                int eweight = adjList[cur.second.first][i].second;
                int dist = cur.second.second + eweight;
                if (dist > 600)
                   continue;
                int isnight = 0;
                if (hotels[next]){
                   dist -= cur.second.second;
                   isnight = 1;
                }
            	if (cur.first+isnight < weights[next]) {
            		weights[next] = cur.first+isnight ;
            		Q.push(make_pair(weights[next], make_pair(next,dist)));
            	}
            }
        }        
        printf("%d\n",ans);
    }
    return 0;
}
