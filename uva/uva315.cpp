#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

int dfsCounter, crit, child, curRoot;
vector<int> dfsNum, dfsLow, dfsParent;
vector<vector<int> > adjList;
bool* counted;

void artic(int u){
     dfsLow[u] = dfsNum[u] = dfsCounter++;
     for (int i = 0; i < adjList[u].size(); i++){
         int v = adjList[u][i];
         if (dfsNum[v] == -1){
           dfsParent[v] = u;
           if (u == curRoot)
              child++;
           artic(v);
           
           if (dfsLow[v] >= dfsNum[u] && u != curRoot && !counted[u]){
              crit++;
              counted[u] = true;
           }
           
           dfsLow[u] = min(dfsLow[u], dfsLow[v]);
         } else if (dfsParent[u] != v)
           dfsLow[u] = min(dfsLow[u], dfsNum[v]); 
     }
}

int main(void){
    int V;
    while(scanf("%d", &V)){
        if (V == 0)
            break;

        adjList.assign(V,vector<int>());
        counted = new bool[V];
        memset(counted,false,V);
        char str[10000];
        char *split;
        while(true){
            int u;
            cin >> u;
            if (u == 0)
               break;
            gets(str);
            split = strtok(str," ");
            while (split != NULL){
                int v = atoi(split);
                split = strtok(NULL," ");
                adjList[u - 1].push_back(v - 1);
                adjList[v - 1].push_back(u - 1);
            }
        }
        
        dfsCounter = 0;
        dfsNum.assign(V,-1);
        dfsLow.assign(V,0);
        dfsParent.assign(V,0);
        crit = 0;
        
        for (int i = 0; i < V; i++){
            if (dfsNum[i] == -1){
               curRoot = i; 
               child = 0;
               artic(i);               
               if (child > 1 && !counted[i]){
                  crit++;   
                  counted[i] = true;
               }
            }     
        }
                
        printf("%d\n",crit);
    }

    
    return 0;
}
