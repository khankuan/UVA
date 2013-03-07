#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int V,E;
        scanf("%d %d",&V,&E);
        
        vector<pair<int,pair<int,int > > > edges;
        for (int i = 0; i < E; i++){
            int from,to,weight;
            scanf("%d %d %d",&from,&to,&weight);
            edges.push_back(make_pair(weight,make_pair(from,to)));
        }
    
        int dist[V];
        memset(dist,100000000,sizeof(dist));
        dist[0] = 0;
        for (int i = 0; i < V -1; i++)
            for (int j = 0; j < E; j++)
                dist[edges[j].second.second] = min(dist[edges[j].second.second], dist[edges[j].second.first]+edges[j].first);
    
        bool hasNega = false;
        for (int j = 0; j < E; j++){
            if (dist[edges[j].second.second] >  dist[edges[j].second.first] + edges[j].first){
               hasNega = true;
               break;
            }
        }
        if (hasNega)
            printf("possible\n");
        else
            printf("not possible\n");
    
    }
    
    
    return 0;
}
