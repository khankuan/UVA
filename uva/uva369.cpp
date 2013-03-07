#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

long long memo[150][150];

long long c(int m, int k){
    if (k == 0 || m == k)
       return 1;
    if (memo[m][k] != -1)
       return memo[m][k];
       
    memo[m][k] = c(m-1,k) + c(m-1,k-1);
    return memo[m][k];
}


int main(void){
    int m, k;
    while(true){
        memset(memo,-1,sizeof memo);
        scanf("%d %d",&m,&k);
        if (m == 0 && k == 0)
           break;
        cout << m << " things taken " << k << " at a time is " << c(m,k) << " exactly." << endl;
    }
    return 0;
}
