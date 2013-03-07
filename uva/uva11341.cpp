#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[11][101];
int memo[10][101][101];
int n,m;

int dp(int x, int y, int remain){

    if (remain == 0){
       if (x == n)
           return 0;
       else
           return -100000000;
    }
    
    if (x == n)
       return 0;
    if (memo[x][y][remain] != -100000000)
       return memo[x][y][remain];

    int ans = -100000000;
    if (arr[x][y] >= 5)
       ans = max(ans,dp(x+1,0,remain-1) + arr[x][y]);
    if (y < m -1)
       ans = max(ans, dp(x,y+1,remain-1));
    memo[x][y][remain] = ans;
    return ans;
}

int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d %d",&n,&m);
        for (int i = 0;i < n; i++)
            for (int j =0;j < m; j++)
                for (int k = 0; k < 101; k++)
                    memo[i][j][k] = -100000000;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&arr[i][j]);
        
        int max = dp(0,0,m);
        
        if (((double)max)/((double)n)+1e-9 < 5.0)
            printf("Peter, you shouldn't have played billiard that much.\n");
        else
            printf("Maximal possible average mark - %.2lf.\n",((double)max+1e-9)/((double)n));
            

    }

    return 0;
}
