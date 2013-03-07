#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int c;
vector<int> visited, visited2, topo;
vector<vector<int> > adjList;

void dfs(int u){
    visited[u] = 1;
    for (int i = 0; i < adjList[u].size(); i++){
        int next = adjList[u][i];
        if (visited[next] == 0)
           dfs(next);
    }
    topo.push_back(u);
}

void dfs2(int u){
    visited2[u] = 1;
    for (int i = 0; i < adjList[u].size(); i++){
        int next = adjList[u][i];
        if (visited2[next] == 0)
           dfs2(next);
    }
}

int main(void){
    int V, E, testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d %d", &V, &E);
        adjList.clear();visited.clear();visited2.clear();topo.clear();
        adjList.assign(V,vector<int>());
        for (int i = 0; i < E ; i++){
            int first, second;
            scanf("%d %d",&first ,&second);
            adjList[first-1].push_back(second-1);
        }
     
        c = 0;     
        visited.assign(V,0);
        visited2.assign(V,0);
        for (int i = 0; i < V; i++)
            if (visited[i] == 0)
               dfs(i);
        
        reverse(topo.begin(), topo.end());

        for (int i = 0; i < V; i++){
            if (visited2[topo[i]] == 0){
               dfs2(topo[i]);
               c++;
            }
        }

        printf("%d\n", c);
    }
    scanf("%d",&testcases);
    return 0;
}
