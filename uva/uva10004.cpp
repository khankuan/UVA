#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;


int main(void){
    int V,E;
    while(true){
        scanf("%d",&V);
        if (V == 0)
           break;
        scanf("%d",&E);
        
        int adjList[V][V], adjCount[V], visited[V];
        memset(adjCount, 0, sizeof(adjCount));
        memset(visited,0,sizeof(visited));
        for (int i = 0; i < E; i ++){
            int first, second;
            scanf("%d %d", &first, &second);
            adjList[first][adjCount[first]] = second;
            adjCount[first]++;
        }
        
        queue<int> q;
        map<int,int> color;
        color[0] = 0;
        q.push(0);
        bool isBiColorable = true;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            visited[u] = 1;
            for (int i = 0; i < adjCount[u]; i++){
                int v = adjList[u][i];
                if (!color.count(v)){
                   color[v] = 1 - color[u];
                   q.push(v);
                } else if (color[v] == color[u]){
                  isBiColorable = false;
                  while(!q.empty())
                      q.pop();
                  break;
                }
            }
        }
        
        if (isBiColorable)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
        
        
    }
    
    return 0;
}
