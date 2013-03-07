#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int candy[35];
int memo[35][645][645];

int dp(int k, int a, int b){
    if (k == N)     
       return max(a,b);
        
    if (memo[k][a][b] != -1 )
       return memo[k][a][b];
       
    int ans = dp(k+1,a+candy[k],b+candy[k]);
    if (a > candy[k])
        ans = min(ans,dp(k+1, a-candy[k], b));
    else
        ans = min(ans,dp(k+1, candy[k]-a, b+candy[k]-a));
    if (b > candy[k])
        ans = min(ans,dp(k+1, b-candy[k], a));
    else
        ans = min(ans,dp(k+1, candy[k]-b, a+candy[k]-b));
    memo[k][a][b] = memo[k][b][a] = ans;
    return ans;
}

int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d",&N);
        for (int i = 0; i < N; i++)
            scanf("%d",&candy[i]);    
        memset(memo,-1, sizeof memo);
        printf("Case %d: %d\n",test+1,dp(0,0,0));
    }
    return 0;
}
