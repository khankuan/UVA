#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int capital;
int largest;
int res[300][300], f;
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
        largest = V-1;
        capital = V;
        for (int i = 0; i < 2*V; i++)
            for (int j = 0 ;j < 2*V; j++)
                res[i][j] = -1;
        

        for (int i = 1; i < V-1; i++){
            int comp, compAmt;
            scanf("%d %d",&comp,&compAmt);
            comp--;
            res[comp][comp+V] = res[comp+V][comp] = compAmt;
        }
        
        for (int i = 0; i < E; i++){
            int from, to, amt;
            scanf("%d %d %d",&from, &to, &amt);
            from--;
            to--;
            res[from+V][to] = res[to+V][from] = amt;       
    
        }


        int mf = 0;
        while(true){
            f = 0;
            vector<int> dist;
            dist.assign(300, 107000000);
            dist[capital] = 0;
            queue<int> q;
            q.push(capital);
            p.assign(300, -1);
            while (!q.empty()){
                  int u = q.front(); q.pop();
                  if (u == largest)
                     break;
                 for (int v = 0; v < 2*V; v++){
                     if (res[u][v] > 0 && dist[v] == 107000000){
                         dist[v] = dist[u] + 1;
                         q.push(v);
                         p[v] = u;
                     }
                 }
            }
            augment(largest,107000000);   
            if (f == 0)
               break;
            mf += f;
        }
               
               
                
        printf("%d\n",mf);
        

    }
    return 0;
}
