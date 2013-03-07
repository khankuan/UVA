#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int> > adjList;
vector<int> owner, visited;

int AltPath(int left){
    if (visited[left]) return 0;
    visited[left] = true;
    for (int i = 0; i < adjList[left].size(); i++){
        int right = adjList[left][i];
        if (owner[right] == -1 || AltPath(owner[right])){
           owner[right] = left;
           return 1;
        }
    }
    return 0;
}

int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int size1,size2;
        scanf("%d",&size1);
        int set1[size1];
        
        for (int i = 0; i <size1; i++)
            scanf("%d",&set1[i]);
        
        scanf("%d",&size2);
        int set2[size2];
        for (int i = 0; i <size2; i++)
            scanf("%d",&set2[i]);
            
        adjList.assign(size1 + size2, vector<int>());
        for (int i = 0; i <size1; i++){
            for (int j = 0; j <size2; j++){
                if (set1[i] != 0 && set2[j] % set1[i] == 0){
                    adjList[i].push_back(j+size1);
                    adjList[j+size1].push_back(i);
                } else if (set1[i] == 0 && set2[j] == 0){
                    adjList[i].push_back(j+size1);
                    adjList[j+size1].push_back(i);
                }
            }
        }
    
        int cardin = 0;
        owner.assign(size1 + size2,-1);
        for (int left = 0; left < size1; left++){
            visited.assign(size1,0);
            cardin += AltPath(left);
        }
        
        printf("Case %d: %d\n",test+1,cardin);
        
    }

    return 0;
}
