#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


#define INF 1000000000

int V, E, cap, target, f ,mf;
vector<vector<int> > adjList;
int cost[105][105];
int res[105][105];
int flow[105][105];
vector<int> p;

void augment(int v, int minEdge) {
     printf("%d ",v);
     if (v == 1) { 
           f = minEdge; 
           return; 
     }
     else if (p[v] != -1) { 
          augment(p[v], min(minEdge, res[p[v]][v]));
          res[p[v]][v] -= f; 
          res[v][p[v]] += f;
          flow[v][p[v]] -= f; 
          flow[p[v]][v] += f;
     }
}

int main() {


    while(scanf("%d %d", &V, &E) == 2){
        adjList.assign(V+1,vector<int>());
        memset(res, 0, sizeof res);
        memset(flow, 0, sizeof flow);
        for (int i = 0; i < E; i++){
            int first, second, third;
            scanf("%d %d %d",&first,&second,&third);
            adjList[first].push_back(second);
            adjList[second].push_back(first);
            cost[first][second] = cost[second][first] = third;
            //res[first][second] = res[second][first] = 1;
        }
        scanf("%d %d",&target,&cap);
        
        for (int i = 1; i < V+1; i++){
            for (int j = 0; j < adjList[i].size(); j++){
                res[i][adjList[i][j]] = res[adjList[i][j]][i] = cap;
            }
        }
        
        mf = 0;
        while (1) {
            f = 0;
            p.assign(V+1,-1);
            int weights[V+1];
            for (int i = 0; i < V+1 ; i++)
                weights[i] = 100000000;
            priority_queue<pair<int,int> > current_span;
            weights[1] = 0;
            current_span.push(make_pair(0,1));
            while (!current_span.empty()){
                  pair<int,int> cur = current_span.top(); current_span.pop();
                  if (cur.first > weights[cur.second])
                     continue;
                  if (cur.first > weights[V])
                     break;
                  for (int  i = 0; i < adjList[cur.second].size(); i++){
                      if (flow[cur.second][adjList[cur.second][i]] < cap &&
                      cur.first + cost[cur.second][adjList[cur.second][i]] < weights[adjList[cur.second][i]]){
                         if (res[cur.second][adjList[cur.second][i]] >= res[adjList[cur.second][i]][cur.second])
                         weights[adjList[cur.second][i]] = cur.first + cost[cur.second][adjList[cur.second][i]];
                         else
                         weights[adjList[cur.second][i]] = cur.first - cost[cur.second][adjList[cur.second][i]];
                         current_span.push(make_pair(weights[adjList[cur.second][i]],adjList[cur.second][i]));
                         p[adjList[cur.second][i]] = cur.second;
                      }
                }
                
            }
            printf("Augment: ");
            augment(V, INF);
            printf("\n");
            if (f == 0) 
               break;
            mf += min(weights[V]*f,target*weights[V]);
            target -= f;
            //printf("%d\n",f);
            if (target <= 0)
               break;   
        }
        if (target <= 0)
            printf("%d\n", mf);
        else
            printf("Impossible\n");
    }
    return 0;
}
