#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int dfsCounter;
vector<int> dfsNum, dfsLow, S, visited;
vector<vector<int> > adjList;
string* names;
map<string,int> mapper;
int V, E;

void tarjan(int u){
     dfsLow[u] = dfsNum[u] = dfsCounter++;
     S.push_back(u);
     visited[u] = 1;
     for (int i = 0; i < adjList[u].size(); i++){
         int v = adjList[u][i];
         if (dfsNum[v] == -1)
            tarjan(v);
         if (visited[v] == 1)
            dfsLow[u] = min(dfsLow[u], dfsLow[v]); 
     }
     if (dfsLow[u] == dfsNum[u]){
        bool first = true;
        while(true){
            int v = S.back(); S.pop_back(); visited[v] = 0;
            if (!first)
                printf(", ");
            else
                first = false;
            cout << names[v];
            if (u == v)
               break;
        }
        printf("\n");
     }
     
}

int main(void){
    int testcase = 1;
    bool first = true;
    while(true){
        scanf("%d %d",&V,&E);
        if (V == 0 && E == 0)
           break;
        if (first)
            first = false;
        else
            printf("\n");
        
        int index = 0;
        names = new string[V];
        adjList.clear(); visited.clear(); S.clear(); dfsNum.clear(); 
        dfsLow.clear(); mapper.clear();
        
        adjList.assign(V,vector<int>());
        visited.assign(V,0);
        dfsNum.assign(V,-1);
        dfsLow.assign(V,0);
        
        for (int i = 0; i < E; i++){
            string first,second;
            cin >> first >> second;
            if (mapper.find(first) == mapper.end()){
               mapper[first] = index;
               names[index] = first;
               index++;
            }
            if (mapper.find(second) == mapper.end()){
               mapper[second] = index;
               names[index] = second;
               index++;
            }
            adjList[mapper[first]].push_back(mapper[second]);
            
        }
        
        printf("Calling circles for data set %d:\n",testcase);
        testcase++;
        dfsCounter = 0;
        for (int i = 0; i < V; i++){
            if (dfsNum[i] == -1)
               tarjan(i);
        }
    }

    
    return 0;   
}
