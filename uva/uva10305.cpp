#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> topo;
int adjList[105][105];
int adjCount[105];
int visited[105];

void dfs(int u){
    visited[u] = 1;
    for (int i = 0; i < adjCount[u]; i++){
        int next = adjList[u][i];
        if (visited[next] == 0)
           dfs(next);
    }
    topo.push_back(u);
}

int main(void){
    
    int vertex, edges;
    while(true){
        topo.clear();
        scanf("%d %d",&vertex,&edges);
        if (vertex == 0 && edges == 0)
           break;
           
        memset(adjCount,0,sizeof(adjCount));
        memset(visited,0,sizeof(visited));
        for (int i = 0; i < edges; i++){
            int first, second;
            scanf("%d %d",&first,&second);
            adjList[first][adjCount[first]] = second;
            adjCount[first]++;
        }
            
        for (int i = 1; i < vertex+1; i++)
            if (visited[i] == 0)
               dfs(i);
        
        reverse(topo.begin(), topo.end());
        
        vector<int>::iterator i;
        printf("%d",*topo.begin());
        for (i = topo.begin()+1; i != topo.end(); i++)
            printf(" %d",*i);
        printf("\n");
    }
    
    return 0;
}
