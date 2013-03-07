#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int dfsCounter, SCC;
vector<int> dfsNum, dfsLow, S, visited;
vector<vector<int> > adjList;

void tarjan(int u, int VCount){
     dfsLow[u] = dfsNum[u] = dfsCounter++;
     S.push_back(u);
     visited[u] = 1;
     for (int i = 0; i < adjList[u].size(); i++){
         int v = adjList[u][i];
         if (dfsNum[v] == -1)
            tarjan(v, VCount);
         if (visited[v] == 1)
            dfsLow[u] = min(dfsLow[u], dfsLow[v]); 
     }
     if (dfsLow[u] == dfsNum[u]){
        while(true){
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (u == v)
               break;
        }
        SCC++;
     }
     
}

int main(void){
    int V, E, test = 0;
    while(true){
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
           break;
        test++;
        adjList.assign(V,vector<int>());
        for (int i = 0; i < E ; i++){
            int first, second, third;
            scanf("%d %d %d",&first ,&second, &third);
            if (third == 2){
               adjList[first-1].push_back(second - 1);
               adjList[second-1].push_back(first -1);
            } else 
               adjList[first-1].push_back(second - 1);
        }
     
        SCC = 0;     
        dfsCounter = 0;
        dfsNum.assign(V,-1);
        dfsLow.assign(V,0);
        visited.assign(V,0);
        tarjan(0,V);
        for (int i = 0; i < V; i++)
            if (dfsNum[i] == -1)
               tarjan(i,V);               

        printf("%d\n", (SCC==1)?1:0);
    }
    
    return 0;
}
