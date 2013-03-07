#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
    
    int V,E,Q, test = 0;
    while(true){
        test++;
        vector<vector<pair<int,int> > > adjList;
        vector<vector<pair<int,int> > > adjListMST;
        scanf("%d %d %d",&V, &E, &Q);
        if (V == 0 && E == 0 && Q == 0)
           break;
        adjList.assign(V,vector<pair<int,int> >());
        adjListMST.assign(V,vector<pair<int,int> >());
        for (int i = 0; i < E; i++){
            int first, second, weight;       
            scanf("%d %d %d",&first, &second, &weight);
            first--;
            second--;
            adjList[first].push_back(make_pair(second,weight));
            adjList[second].push_back(make_pair(first,weight));
        }
        
        
        
        
        int visited[V];
        memset(visited,0,sizeof(visited));
        
        for (int k = 0; k < V; k++){
            if (!visited[k]){
                priority_queue<pair<int,pair<int,int> > > PQ;
                for (int i = 0; i < adjList[k].size(); i++)
                    PQ.push(make_pair(-adjList[k][i].second,make_pair(-adjList[k][i].first,k)));
                visited[k] = true;
                while (!PQ.empty()){
                      pair<int,pair<int,int> > edge = PQ.top(); PQ.pop();
                      int u = edge.second.second;
                      int v = -edge.second.first;
                      int weight = -edge.first;
                      if (!visited[v]){
                         for (int i = 0; i < adjList[v].size(); i++)
                             if (!visited[adjList[v][i].first])
                                PQ.push(make_pair(-adjList[v][i].second,make_pair(-adjList[v][i].first,v)));    
                         visited[v] = true;
                         adjListMST[v].push_back(make_pair(u,weight));
                         adjListMST[u].push_back(make_pair(v,weight));
                      }
                }  
            }         
        }
        if (test != 1)
           printf("\n");
        printf("Case #%d\n",test);
        for (int j = 0; j < Q; j++){
            int from,to;
            scanf("%d %d",&from, &to);
            from--;
            to--;  
            int miniMAX = -1;
            memset(visited,0,sizeof(visited));
            priority_queue<pair<int,int> > PQ2;
            for (int i = 0; i < adjListMST[from].size(); i++)
                PQ2.push(make_pair(-adjListMST[from][i].second,-adjListMST[from][i].first));
            visited[from] = true;
            bool found = false;;
            while(!PQ2.empty()){
                pair<int,int> edge = PQ2.top(); PQ2.pop();
                int v = -edge.second;
                miniMAX = max(miniMAX,-edge.first);
                if (v == to){
                   found = true;
                   break;
                }
                if (!visited[v]){
                     for (int i = 0; i < adjListMST[v].size(); i++)
                         if (!visited[adjListMST[v][i].first])
                            PQ2.push(make_pair(-adjListMST[v][i].second,-adjListMST[v][i].first));    
                     visited[v] = true;
                 }
            }              
            if (found)
                printf("%d\n",miniMAX);
            else
                printf("no path\n");
        }
        
    }
    
    return 0;
}
