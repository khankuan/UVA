#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


bool pairCompare (pair<int,int> i, pair<int,int> j){
    if (i.first != j.first)
       return i.first < j.first;
    else
        return i.second < j.second;
}

int dfsCounter, crit;
vector<int> dfsNum, dfsLow, dfsParent, adjCount;
vector<vector<int> > adjList;
vector<pair<int,int> > edges;

void artic(int u){
     dfsLow[u] = dfsNum[u] = dfsCounter++;
     for (int i = 0; i < adjCount[u]; i++){
         int v = adjList[u][i];
         if (dfsNum[v] == -1){
           dfsParent[v] = u;
           artic(v);
           
           if (dfsLow[v] > dfsNum[u]){
              if (u > v)
                 edges[crit] = make_pair(v,u);
              else
                 edges[crit] = make_pair(u,v);
              crit++;
           }
           dfsLow[u] = min(dfsLow[u], dfsLow[v]);
         } else if (dfsParent[u] != v)
           dfsLow[u] = min(dfsLow[u], dfsNum[v]); 
     }
}

int main(void){
    int V;
    while(scanf("%d", &V) == 1){
        adjCount.assign(V,0);
        adjList.assign(V,vector<int>());
        for (int i = 0; i < V ; i++)
            adjList[i].assign(V,0);
        for (int i = 0; i < V ; i++){
            int input;
            scanf("%d",&input);
            char dummy;
            scanf("%c",&dummy);
            scanf("%c",&dummy);
            scanf("%d",&adjCount[input]);
            scanf("%c",&dummy);
            
            for (int j = 0 ; j < adjCount[input]; j++){
                scanf("%d",&adjList[input][j]);
                adjList[j][input] = adjList[input][j];
            }

        }
        getchar();
        
        dfsCounter = 0;
        dfsNum.assign(V,-1);
        dfsLow.assign(V,0);
        dfsParent.assign(V,0);
        crit = 0;
        int V2 = V*V;
        edges.assign(V2,make_pair(V,V));
        
        for (int i = 0; i < V; i++){
            if (dfsNum[i] == -1)
               artic(i);           
        }
        
        sort(edges.begin(),edges.end(),pairCompare);
        
        printf("%d critical links\n", crit);
        for (int i = 0;i < crit; i++) {
            printf("%d - %d\n",edges[i].first,edges[i].second);
        }
        printf("\n");
    }

    
    return 0;
}
