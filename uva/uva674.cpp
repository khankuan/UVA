#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int input;
    long long dp[7600];
    memset(dp,0,sizeof(dp));
    int c[]={1,5,10,25,50}; 
    dp[0]=1; 
    for(int j = 0; j < 5; j++) 
        for(int i=c[j]; i< 7600; i++) 
            dp[i] += dp[i-c[j]];    
    
    while (scanf("%d",&input) == 1)
       cout << dp[input] << endl;
     
    return 0;
}
