#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;


int mf, f;
vector<vector<int> > adjList;
vector<int> owner, visited;
int res[505][505];

double dis(double x, double y, double x1, double y1){
       return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

int Alter(int left){
    if (visited[left]) return 0;
    visited[left] = true;
    
    for (int j = 0; j < adjList[left].size(); j++){
        int right = adjList[left][j];
        if (owner[right] == -1 || Alter(owner[right])){
           owner[right] = left;
           return 1;
        }
    
    }
    return 0;
}

int main(void){
    int n,m,s,v;
    
    while (scanf("%d %d %d %d",&n,&m,&s,&v) == 4){

        memset(res,0,sizeof(res));
        
        double d = s*v;
        double gopherx[n], gophery[n];
        adjList.clear();
        adjList.assign(n+m,vector<int>());
        for (int i = 0; i < n; i++)
          scanf("%lf %lf",&gopherx[i],&gophery[i]);
        
      
        for (int i = 0; i < m; i++){
           double x,y;
           scanf("%lf %lf",&x,&y);
           for (int j = 0; j < n; j++){
               if (dis(x,y,gopherx[j],gophery[j]) <= d*d || fabs(dis(x,y,gopherx[j],gophery[j]) - d*d) < 1e-7){
                  adjList[j].push_back(n+i);
                  adjList[n+i].push_back(j);
               }
           }
        }
    
        int card = 0;
        owner.assign(n+m,-1);
        for (int left = 0; left < n; left++){
            visited.assign(n,0);
            card +=Alter(left);
        }


        printf("%d\n",n-card);
    
    }
    return 0;
}
