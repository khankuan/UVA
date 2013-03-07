#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 1010
#define MAX_W 40

int N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];

int value(int id, int w) {
    if (id == N || w == 0) 
       return 0;
    if (memo[id][w] != -1) 
       return memo[id][w];
       
    memo[id][w] = value(id + 1, w);
    if (W[id] > w)         
       return memo[id][w];
       
    memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
    
    return memo[id][w];
}

int main() {
    int i, T, G, ans;
    
    scanf("%d", &T);
    while (T--) {
        memset(memo, -1, sizeof memo);
    
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d %d", &V[i], &W[i]);
        
        ans = 0;
        scanf("%d", &G);
        while (G--) {
              scanf("%d", &MW);
              ans += value(0, MW);
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}
