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
vector<int> allo;
int res[40][40];

void augment(int v, int minEdge) {
    if (v == 0) { f = minEdge; return; }
    else if (p[v] != -1) { 
       augment(p[v], min(minEdge, res[p[v]][v]));
       res[p[v]][v] -= f; 
       allo[v] = p[v];
       res[v][p[v]] += f; 
    }   
}

int main(void){

    char first;
    char comp[15];
    while (scanf("%c",&first) == 1){
          if (first == '\n')
             break;
          gets(comp);
          if (strlen(comp) == 0)
             break;
        int count, total = 0;
        adjList.assign(40,vector<int>());
        memset(res,0,sizeof res);
        
        res[0][first-'A'+1] = comp[0] - '0';
        total += comp[0] - '0';
        adjList[0].push_back(first-'A'+1);

        for (int i = 2; comp[i] != ';'; i++){
          adjList[first-'A'+1].push_back(comp[i]-'0'+27);
          res[first-'A'+1][comp[i]-'0'+27] = 1;
          if (res[comp[i]-'0'+27][37] != 1){
              adjList[comp[i]-'0'+27].push_back(37);
              res[comp[i]-'0'+27][37] = 1;
          }
        }
        
        while (true){
              gets(comp);
              if (strlen(comp) == 0)
                 break;
              res[0][comp[0]-'A'+1] = comp[1] - '0';
              total += comp[1] - '0';
              adjList[0].push_back(comp[0]-'A'+1);
              
              for (int i = 3; comp[i] != ';'; i++){
                  adjList[comp[0]-'A'+1].push_back(comp[i]-'0'+27);
                  res[comp[0]-'A'+1][comp[i]-'0'+27] = 1;
                  if (res[comp[i]-'0'+27][37] != 1){
                      adjList[comp[i]-'0'+27].push_back(37);
                      res[comp[i]-'0'+27][37] = 1;
                  }
              }
                  
        }
        /*
        for (int i = 0; i < 38;i++){
            printf("%d: ",i);
            for (int j = 0; j < adjList[i].size(); j++)
                printf("%d ",adjList[i][j]);
            printf("\n");
        }*/
           
        allo.assign(40,-1);

        mf = 0;
        while (true) {
            f = 0;
            bool visited[40];
            memset(visited,false, sizeof visited);
            queue<int> q; 
            q.push(0);            
            visited[0] = true;
            p.assign(40, -1);
            
            while (!q.empty()) {
                int u = q.front(); 
                q.pop();
                
                if (u == 37) 
                   break;
                  /*
                for (int v = 0; v < adjList[u].size() ; v++){
                    if (res[u][adjList[u][v]] > 0 && p[adjList[u][v]] == -1){
                        q.push(adjList[u][v]);
                        //visited[adjList[u][v]] = true; 
                        p[adjList[u][v]] = u;
                    }
                }*/
                
                
                for (int v = 0; v < 38 ; v++){
                    if (res[u][v] > 0 && p[v] == -1){
                        q.push(v); 
                        p[v] = u;
                    }
                }
            }
            augment(37, 100000000);
            if (f == 0) 
               break;

            mf += f;
        }
      //  for (int i = 0; i < 38 ;i++)
     //       printf("%d\n",allo[i]);
        if (mf == total){
           for (int i = 0; i < 10; i++){
              if (allo[i+27] != -1)
                   printf("%c",allo[i+27]+'A'-1);
               else
                   printf("_");
           }
           printf("\n");
        } else
           printf("!\n");
          // printf("mf: %d\n",mf);
    }
    return 0;
}
