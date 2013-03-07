#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    int input;
    while (scanf("%d",&input) == 1){
        long long dp[30001];
        memset(dp,0,sizeof(dp));
        int c[]={1,5,10,25,50}; 
        dp[0]=1; 
        for(int j = 0; j < 5; j++) 
            for(int i=c[j]; i< 30001; i++) 
                dp[i] += dp[i-c[j]];
        
        if (dp[input] == 1)
            cout << "There is only 1 way to produce " << input << " cents change." << endl;
        else
            cout << "There are " << dp[input] << " ways to produce " << input << " cents change." << endl;
    }
    scanf("%d",&input);
    return 0;
}
