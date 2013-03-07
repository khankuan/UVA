#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(void){
    int K,N;
    while (scanf("%d %d",&N,&K)){ 
          if (K == 0 && N == 0)
             break;
            long long ans = 0, dp[K+1][N+1];   
            memset(dp,0,sizeof(dp));
            
            for (int a = 0; a <= N; a++)              
                dp[1][a] = 1; // 1 digit to give sum of a = only 1 way      
            
            for (int i = 2; i < K; i++) // can be <= K if (K,M) is needed where M might not be N              
                for (int j = 0; j <= N; j++)                       
                    for (int k = 0; k <= j; k++){                                
                        dp[i][j] += dp[i-1][k]; // can be: combi(5,30) = 0 + combi(4,30)     
                        if (dp[i][j] > 1000000)
                           dp[i][j] %= 1000000;
                    }     
            
            for (int b = 0; b <= N; b++){
          
                ans += dp[K-1][b];
                if (ans > 1000000)
                   ans %= 1000000;
            }
            
            if (K == 1)
                printf("1\n");
            else 
                cout << ans << endl;
    }
}
