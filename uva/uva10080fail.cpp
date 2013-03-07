#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int mf, f;
vector<vector<int> > adjList;
vector<int> p;
int res[505][505];

double dis(double x, double y, double x1, double y1){
       return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

void augment(int v, int minEdge) {
    if (v == 0) { f = minEdge; return; }
    else if (p[v] != -1) { 
       augment(p[v], min(minEdge, res[p[v]][v]));
       res[p[v]][v] -= f; 
       res[v][p[v]] += f; 
    }   
}

int main(void){
    int n,m,s,v;
    
    while (scanf("%d %d %d %d",&n,&m,&s,&v) == 4){

        memset(res,0,sizeof(res));
        
        double d = s*v;
        double gopherx[n], gophery[n];
        adjList.clear();
        adjList.assign(n+m+2,vector<int>());
        for (int i = 0; i < n; i++){
          scanf("%lf %lf",&gopherx[i],&gophery[i]);
          adjList[0].push_back(i+1);
          adjList[i+1].push_back(0);
          res[0][i+1] = res[i+1][0] = 1;
        }
      
        for (int i = 0; i < m; i++){
           double x,y;
           scanf("%lf %lf",&x,&y);
           for (int j = 0; j < n; j++){
               if (dis(x,y,gopherx[j],gophery[j]) <= d*d || fabs(dis(x,y,gopherx[j],gophery[j]) - d*d) < 1e-7){
                  adjList[j+1].push_back(n+1+i);
                  adjList[n+1+i].push_back(j+1);
                  res[j+1][n+1+i] = res[n+1+i][j+1] = 1;
               }
           }
           adjList[n+1+i].push_back(n+m+1);
           adjList[n+m+1].push_back(n+1+i);
           res[n+1+i][n+m+1]  = res[n+m+1][n+1+i] = 1;
        }
        
           
        mf = 0;
        while (true) {
            f = 0;

            queue<int> q; 
            q.push(0);
            bool visited[n+m+2];
            
            memset(visited,false,sizeof(visited));
            visited[0] = true;
            
            p.assign(n+m+2, -1);
            while (!q.empty()) {
                int u = q.front(); 
                q.pop();
                
                if (u == n+m+1) 
                   break;
                  /* 
                for (int v = 0; v < adjList[u].size() ; v++){
                    if (res[u][adjList[u][v]] > 0 && !visited[adjList[u][v]]){
                        q.push(adjList[u][v]); 
                        p[adjList[u][v]] = u;
                        visited[adjList[u][v]] = true;
                    }
                }*/
                
                for (int v = 0; v < n+m+2 ; v++){
                    if (res[u][v] > 0 && !visited[v]){
                        q.push(v); 
                        p[v] = u;
                        visited[v] = true;
                    }
                }
            }
            augment(n+m+1, 100000000);
            if (f == 0) 
               break;

            mf += f;
        }
        printf("%d\n",n-mf);
    
    }
    return 0;
}
