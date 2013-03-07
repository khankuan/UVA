#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

long long memo[51][51][2][51];

long long dp(int unitLeft, int barLeft, int preCol, int preWid, long long memo[51][51][2][51],int m){
     if (barLeft <0 || unitLeft <0 || preWid > m) // no more bar or units lefts or width too fat
         return 0;
     if (unitLeft == 0 && barLeft == 0 && preWid <= m) // just nice
         return 1;

     if (memo[unitLeft][barLeft][preCol][preWid] != -1) //memoise
          return memo[unitLeft][barLeft][preCol][preWid];

     memo[unitLeft][barLeft][preCol][preWid] = dp(unitLeft-1, barLeft , preCol, preWid+1,memo,m)
                       + dp(unitLeft-1, barLeft-1, 1-preCol, 1,memo,m); //  case of same and different color

     return memo[unitLeft][barLeft][preCol][preWid];
}

int main(void){
    int n,k,m;
    while(scanf("%d",&n) == 1){
        scanf("%d %d",&k,&m);  
        memset(memo,-1,sizeof(memo));
        cout << dp(n,k,0,m,memo,m) << endl;       
    }
    
    system("pause");
    return 0;
}
