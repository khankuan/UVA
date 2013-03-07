#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int V,E;
vector<vector<int> > adjMat;
vector<int> degree;
vector<int> odd;
int* memo;

int minMatch(int bitmask){
    if (bitmask == (1 << odd.size()) - 1)
       return 0;
    if (memo[bitmask] != -1)
       return memo[bitmask];
    
    int i = 0, j;
    for (; i < odd.size(); i++){
        if (!((bitmask >> i) & 1))
           break;
    }
    int ans = 100000000;
    for (int j = i + 1; j < odd.size(); j++){
        if (!((bitmask >> j) & 1))
           ans = min(ans,minMatch(bitmask | (1 << j) | (1 << i)) + adjMat[odd[i]][odd[j]]);
    }
    memo[bitmask] = ans;
    return ans;    
}

int main(void){
    
    while(true){
        scanf("%d",&V);
        if (V == 0)
           break;
           
        scanf("%d",&E);
        adjMat.assign(V,vector<int>());
        degree.assign(V,0);
        int totalWeight = 0;
        
        for (int i = 0; i < V; i++)
            adjMat[i].assign(V,100000000);
        
        for (int i = 0; i < E; i++){
            int from, to, weight;
            scanf("%d %d %d",&from, &to, &weight);
            from--; to--;
            if (adjMat[from][to] > weight){
               adjMat[from][to] = weight;
               adjMat[to][from] = weight;
            }
            totalWeight += weight;
            degree[from]++;
            degree[to]++;
        }
             
        odd.clear();
        for (int i = 0; i < V; i++)
            if (degree[i] % 2 == 1)
               odd.push_back(i);
        
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = i+1; j < V; j++)
                    if (adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                       adjMat[i][j] = adjMat[j][i] = adjMat[i][k] + adjMat[k][j];
                
        
        memo = new int[1 << odd.size()];
        memset(memo, -1, (1 << odd.size())*4);
        
        printf("%d\n",totalWeight + minMatch(0));
    }
   
    return 0;
}
