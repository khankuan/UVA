#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int i, j, TC, xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1 << 11];

int dp(int pos, int bitmask) {
    if (bitmask == (1<<(n+1))-1)
       return dist[pos][0];
    if (memo[pos][bitmask] != -1)
       return memo[pos][bitmask];

    int ans = 1000000000;
    for (int next = 0; next <= n; next++)
        if (next != pos && !(bitmask & (1 << next))) 
           ans = min(ans, dist[pos][next] + dp(next, bitmask | (1 << next)));
    
    return memo[pos][bitmask] = ans;
}

int main() {
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &xsize, &ysize);
        scanf("%d %d", &x[0], &y[0]);
        scanf("%d", &n);
        for (i = 1; i <= n; i++) 
            scanf("%d %d", &x[i], &y[i]);
    
        for (i = 0; i <= n; i++) 
            for (j = 0; j <= n; j++)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); 
    
        memset(memo, -1, sizeof memo);
        printf("The shortest path has length %d\n", dp(0, 1)); 
    }
    
    return 0;
}
