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
        vector<int> hotels;
        
        scanf("%d",&hotelcount);
        int input;
        for (int i = 0; i < hotelcount; i++){    
            scanf("%d",&input);
            input--;
            if (input == 0 || input == V-1){
               i--;
               hotelcount--;
               continue;
            }
            hotels.push_back(input);
        }
        hotels.push_back(0);
        hotels.push_back(V-1);
        hotelcount += 2;
            
        scanf("%d",&E);
        for (int i = 0; i < E; i++){
            int from,to,amt;
            scanf("%d %d %d",&from,&to,&amt);
            from--;
            to--;
            adjList[from].push_back(make_pair(to,amt));
            adjList[to].push_back(make_pair(from,amt));
        }
        
        vector<int> adjList2[V];
        
        for (int h = 0; h < hotelcount; h++){
            int weights[V];
            for (int i = 0; i < V; i++)
                weights[i] = 100000000;
            int source = hotels[h];
            weights[source] = 0;
            priority_queue<pair<int,int> > Q;
            Q.push(make_pair(0, source));
            
            while (!Q.empty()){
                pair<int,int> cur = Q.top(); Q.pop();
          	    if (cur.first > weights[cur.second])
                   continue; 
                if (cur.first > 600)
                   break;         	
                for (int i = 0; i < adjList[cur.second].size(); i++) {
                    int next = adjList[cur.second][i].first;
                    int later = cur.first + adjList[cur.second][i].second;
                	if (later < weights[next]) {
                		weights[next] = later ;
                		Q.push(make_pair(weights[next], next));
                	}
                }
            }
            for (int i = h+1; i < hotelcount; i++){
                if (weights[hotels[i]] < 601 && hotels[i] != source){
                   adjList2[source].push_back(hotels[i]);
                   adjList2[hotels[i]].push_back(source);
                }
            }
        }
                  
        bool visited[V];
        memset(visited,false,sizeof visited);
        queue<pair<int,int > > Qbfs;
        int source = 0;
        Qbfs.push(make_pair(0,source));
        
        int ans = -1;
        while (!Qbfs.empty()){
            pair<int,int> cur = Qbfs.front(); Qbfs.pop();
            if (visited[cur.second])
               continue;
            visited[cur.second] = true;
            if (cur.second == V-1){
               ans = cur.first-1;
               break;
            }

            for (int i = 0; i < adjList2[cur.second].size(); i++) {
                int next = adjList2[cur.second][i];
                if (!visited[next]){                
                   Qbfs.push(make_pair(cur.first+1,next));
                }
            }
        }
        
        printf("%d\n",ans);
    }
    return 0;
}
