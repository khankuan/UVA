#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define capital 0
#define largest 1

int res[60][60], f;
vector<int> p;

void augment(int v, int minEdge){
     if (v == capital){
        f = minEdge;
        return;
     } else if (p[v] != -1){
       augment(p[v],min(minEdge,res[p[v]][v]));
       res[p[v]][v] -= f;
       res[v][p[v]] += f;
     }
}

int main(void)
{ 
    int V,E;
    while(true){
        scanf("%d %d",&V,&E);
        if (V == 0 && E == 0)
           break;
        
        for (int i = 0; i < V; i++)
            for (int j = 0 ;j < V; j++)
                res[i][j] = -1;
        
        for (int i = 0; i < E; i++){
            int from, to, amt;
            scanf("%d %d %d",&from, &to, &amt);
            from--;
            to--;
            res[from][to] = res[to][from] = amt;        
        }
        while(true){
            f = 0;
            vector<int> dist;
            dist.assign(60, 10000000);
            dist[capital] = 0;
            queue<int> q;
            q.push(capital);
            p.assign(60, -1);
            while (!q.empty()){
                  int u = q.front(); q.pop();
                  if (u == largest)
                     break;
                     for (int v = 0; v < V; v++){
                         if (res[u][v] > 0 && dist[v] == 10000000){
                             dist[v] = dist[u] + 1;
                             q.push(v);
                             p[v] = u;
                         }
                     }
            }
            augment(largest,10000000);
            if (f == 0)
               break;

        }
               
        queue<int> q;
        q.push(capital);
        int visited[V];
        for (int i = 0; i <V;i++)
            visited[i] = 0;
        visited[capital] = 1;
        while (!q.empty()){
              int u = q.front(); q.pop();
              for (int v = 0; v < V; v++){
                 if (res[u][v] > 0 && !visited[v]){
                     q.push(v);
                     visited[v] = 1;
                 }
              }
        }
        
        

        q.push(capital);
        int visited2[V];
        for (int i = 0; i <V;i++)
            visited2[i] = 0;
        visited2[capital] = 1;
        while (!q.empty()){
              int u = q.front(); q.pop();
              for (int v = 0; v < V; v++){
                 if (res[u][v] > 0 && !visited2[v]){
                     q.push(v);
                     visited2[v] = 1;
                 }
                 else if (res[u][v] == 0 && visited[v] == 0)
                      printf("%d %d\n",u+1,v+1);
              }
        }
        
             
        printf("\n");

    }
    return 0;
}
