#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int memo[155][55][205];
int target;

int dp(int coke, int ten, int five, int one){
    if (coke >= target)
       return 0;
       
    if (memo[coke][ten][five] != -1)
       return memo[coke][ten][five];
       
    int ans = 100000000;

    if (ten > 0 && one > 2)
       ans = min(ans, dp(coke+1,ten-1,five+1,one-3)+4);
    if (ten > 0)
       ans = min(ans, dp(coke+1,ten-1,five,one+2)+1);
    if (five > 1)
       ans = min(ans, dp(coke+1,ten,five-2,one+2)+2);
    if (five > 0 && one > 2)
       ans = min(ans, dp(coke+1,ten,five-1,one-3)+4);
    if (one > 7)
       ans = min(ans, dp(coke+1,ten,five,one-8)+8);
    
    memo[coke][ten][five] = ans;
    return ans;
}

int main(void){
    int testcases;
    scanf("%d",&testcases);
    
    for (int test = 0; test< testcases; test++){
        int one, five, ten;
        int coins = 0;
        scanf("%d %d %d %d", &target, &one, &five, &ten);

        memset(memo,-1,sizeof(memo));
        
        printf("%d\n",dp(0,ten,five,one));

    }


}
