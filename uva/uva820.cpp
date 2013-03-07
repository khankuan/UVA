#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int mf, f,s,d,E,V;
vector<vector<int> > adjList;
vector<int> p;
int res[250][250];

void augment(int v, int minEdge) {
    if (v == s) { f = minEdge; return; }
    else if (p[v] != -1) { 
       augment(p[v], min(minEdge, res[p[v]][v]));
       res[p[v]][v] -= f; 
       res[v][p[v]] += f; 
    }   
}

int main(void){
    int test =1;
    while (true){
        scanf("%d",&V);
        if (V == 0)
           break;
        scanf("%d %d %d",&s,&d,&E);
        adjList.assign(250,vector<int>());
        memset(res,0,sizeof res);
        
        for (int i = 0; i < E; i++){
            int from, to, weight;
            scanf("%d %d %d",&from,&to,&weight);
            if (res[from][to] == 0)
               adjList[from].push_back(to);
            res[from][to] += weight;    
            if (res[to][from] == 0)
               adjList[to].push_back(from);
            res[to][from] += weight;      
        }
        
        mf = 0;
        while (true) {
            f = 0;
            queue<int> q; 
            q.push(s);         
            p.assign(250, -1);
            
            while (!q.empty()) {
                int u = q.front(); 
                q.pop();
                
                if (u == d) 
                   break;
                
                for (int v = 0; v < adjList[u].size() ; v++){
                    if (res[u][adjList[u][v]] > 0 && p[adjList[u][v]] == -1){
                        q.push(adjList[u][v]); 
                        p[adjList[u][v]] = u;
                    }
                }
            }
            augment(d, 100000000);
            if (f == 0) 
               break;

            mf += f;
        }
        printf("Network %d\n",test);
        printf("The bandwidth is %d.\n\n",mf);
        test++;
    }
    return 0;
}
