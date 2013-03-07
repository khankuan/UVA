#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int S, M, N;
int cost[105];
int sub[105][9];
int memo[100][1 << 17];

int dp(int bitmask, int t){
    if (bitmask == (1 << (S*2)) -1)
       return 0;
    if (t == N)
       return 10000000;
    
    if (memo[t][bitmask] != -1)
       return memo[t][bitmask];

    int i = 0;
    while (true){
          if ((bitmask >> i) & 1)
              i++;
          else
              break;
    }

    int mini = 10000000;


   int newbitmask = bitmask;
   for (int k = 0; k < S; k++){          
       if (sub[t][k] == 1){
          if (!((bitmask >> (k*2+1))&1)){
             if (!((bitmask >> (k*2))&1))
                 newbitmask += (1 << (k*2));
             else
                 newbitmask += (1 << (k*2 + 1));
          }
       }
   }
   mini = min(mini,dp(newbitmask,t+1) + cost[t]);
   mini = min(mini,dp(bitmask,t+1));
        
    
    memo[t][bitmask] = mini;
    return mini;

}

int main(void){
    while(true){
        scanf("%d %d %d",&S, &M, &N);
        if (S == 0)
           break;
        
        int count[S];
        memset(count,0,sizeof(count));
        int servingCost = 0;
        
        char str[10000];
        char *split;        
        for (int i = 0; i < M; i++){
            int input;
            cin >> input;
            servingCost += input;
            gets(str);
            split = strtok(str," ");
            while (split != NULL){
                int s = atoi(split) - 1;
                split = strtok(NULL," ");
                count[s]++;
            }
        }
        
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 9; j++)
                sub[i][j] = 0;
        for (int i = 0; i < N; i++){
            cin >> cost[i];
            gets(str);
            split = strtok(str," ");
            while (split != NULL){
                int s = atoi(split) - 1;
                split = strtok(NULL," ");
                sub[i][s] = 1;
            }
        }
        
        int sBitMask = 0;
        for (int i = 0; i < S ; i++){
            if (count[i] >= 2)
               sBitMask += 3 * (1 << (i*2));
            else if (count[i] == 1)
               sBitMask += 1 * (1 << (i*2));
        }   

        memset(memo,-1,sizeof(memo));
        printf("%d\n", servingCost + dp(sBitMask,0));
    }
    
    return 0;
}
