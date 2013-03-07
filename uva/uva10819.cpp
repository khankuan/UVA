#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int cost[105], sat[105], money, c;
int memo[105][10005];

int dp(int k, int spent, int offer){
    if (k == c)
       return 0;
    if (memo[k][spent] != 0)
       return memo[k][spent];

    int high = 0;
    int oldoffer = offer;
    if (cost[k] + spent > 2000 && cost[k] + spent <= money + 200)
       offer = 1;
    
    if (cost[k] + spent <= money + 200*offer)
       high = max(high, dp(k+1,spent+cost[k],offer) + sat[k]);
    high = max(high, dp(k+1,spent,oldoffer));
    
    memo[k][spent] = high;
    return high;
}


int main(void){
    
    while(scanf("%d %d",&money,&c) == 2){
        for (int i = 0; i < c; i++)
            scanf("%d %d",&cost[i],&sat[i]);
        
        for (int i = 0; i < 105;i++)
            for (int j = 0; j < 10005;j++)
                memo[i][j] = 0;

        printf("%d\n",dp(0,0,0));
    }

    return 0;
    
}
