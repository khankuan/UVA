#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int arr[105];
int memo[2][105][105];

int dp(int turn, int s, int e){
    if (s > e){
       return 0;  
    }
    
    if (memo[turn][s][e] != -1)
       return memo[turn][s][e];
       
    int ans = -100000000;
    int sum = 0;
    for (int i = s; i <= e; i++){
        sum += arr[i];
        ans = max(ans, -dp(1-turn, i+1, e) + sum);
    }
    sum = 0;
    for (int i = e; i >= s; i--){
        sum += arr[i];
        ans = max(ans, -dp(1-turn, s, i-1) + sum);
    }
    
    memo[turn][s][e] = ans;
    return ans;
}


int main(void){
    while(true){
        int c;
        scanf("%d",&c);
        if (c == 0)
           break;
           
        for (int i = 0; i < c; i++)
            scanf("%d",&arr[i]);
        
        memset(memo,-1,sizeof(memo));
        
        printf("%d\n",dp(0,0,c-1));
    
    }
    return 0;
}
