#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;



int main(void){
    
    int V,E;
    while(true){
        vector<vector<pair<int,int> > > adjList;
        scanf("%d %d",&V, &E);
        if (V == 0 && E == 0)
           break;
        adjList.assign(V,vector<pair<int,int> >());
        
        int weightSum = 0;
        for (int i = 0; i < E; i++){
            int first, second, weight;
            scanf("%d %d %d",&first, &second, &weight);
            adjList[first].push_back(make_pair(second,weight));
            adjList[second].push_back(make_pair(first,weight));
            weightSum += weight;
        }
        
        int weightMST = 0;
        int visited[V];
        memset(visited,0,sizeof(visited));
        priority_queue<pair<int,int> > PQ;
        for (int i = 0; i < adjList[0].size(); i++)
            PQ.push(make_pair(-adjList[0][i].second,-adjList[0][i].first));
        visited[0] = true;
        while (!PQ.empty()){
              pair<int,int> edge = PQ.top(); PQ.pop();
              int v = -edge.second;
              if (!visited[v]){
                 for (int i = 0; i < adjList[v].size(); i++)
                     if (!visited[adjList[v][i].first])
                        PQ.push(make_pair(-adjList[v][i].second,-adjList[v][i].first));    
                 weightMST -= edge.first;
                 visited[v] = true;
              }            
        }      
        
        printf("%d\n",weightSum - weightMST);
    }
    
    return 0;
}
