#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int V;
vector<vector<int> > adjList;
int memo[1100][1100][2];

int MVC(int u, int v, bool take){
    
    if (u != -1){
       if (take && memo[u][v][1] != -1)
           return memo[u][v][1];
       else if (!take && memo[u][v][0] != -1)
           return memo[u][v][0];
    }
    
    int ans = 0;
    if (!take){
       for (int i = 0; i < adjList[v].size(); i++){
           if (adjList[v][i] != u)
              ans += MVC(v, adjList[v][i], true);
       }
    } else {
      ans = 1;
      for (int i = 0; i < adjList[v].size(); i++){
           if (adjList[v][i] != u)
              ans += min(MVC(v, adjList[v][i], true),MVC(v, adjList[v][i], false));
      }  
    }
    if (u != -1){
       if (take)
           memo[u][v][1] = ans;
       else
           memo[u][v][0] = ans;
    }
    return ans;
}

int main(void){
    
    while(true){
        scanf("%d",&V);
        if (V == 0)
           break;
         
        adjList.assign(V,vector<int>());
        memset(memo,-1,sizeof(memo));
        for (int i = 0; i < V; i++){
            int count;
            scanf("%d",&count);
            for (int j = 0; j < count; j++){
                int input;
                scanf("%d",&input);
                adjList[i].push_back(input-1);
            }
        }
        int mini = MVC(-1,0,false);
        if (adjList[0].size() == 0)
           mini++;
        mini = min(mini,MVC(-1,0,true));
        
        printf("%d\n",mini);
    }
    
    
    return 0;
}
