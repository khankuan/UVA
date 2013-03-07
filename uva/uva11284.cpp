#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxState 1<<13
#define maxN 13
#define oo 0xfffffffffLL

long long DP[maxState][maxN], map[51][51];
int A[maxN], AD[maxN], best;
int TSP(int state, int n, int last) {

    if(state == 0)    return 0;
    if(DP[state][last] != -oo)    return DP[state][last];
    int i;
    long long max = -oo, tmp;
    for(i = 0; i <= n; i++) {
        if((state&(1<<i)) != 0 && last != i) {
            tmp = TSP(state-(1<<last), n, i);
            tmp -= map[A[i]][A[last]];
            tmp += AD[last];
            if(max < tmp)    max = tmp;
            
        }
    }
    if(state == (1<<last))    max = -map[A[last]][0]+AD[last];
    if(best < max-map[A[last]][0])    best = max-map[A[last]][0];

    DP[state][last] = max;
    return DP[state][last];
}
long long min(long long a, long long b) {
    return a < b ? a : b;
}
int main() {

    int T, x, y;
    int n, m, p, i, j, k, a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i <= n; i++)
            for(j = 0; j <= n; j++)
                map[i][j] = oo;
        for(i = 0; i < m; i++) {
            scanf("%d %d %d.%d", &x, &y, &a, &b);
            map[x][y] = min(100*a+b, map[x][y]);
            map[y][x] = min(100*a+b, map[y][x]);
        }
        scanf("%d", &p);
        int newp, tmpAD[51];
        memset(tmpAD, 0, sizeof(tmpAD));
        for(i = 1; i <= p; i++) {
            scanf("%d %d.%d", &A[i], &a, &b);
            tmpAD[A[i]] += 100*a+b;
        }
        newp = 0;
        for(i = 1; i <= n; i++)
            if(tmpAD[i]) {
                newp++, A[newp] = i, AD[newp] = tmpAD[i];
            }
        p = newp;
        for(k = 0; k <= n; k++)
            for(i = 0; i <= n; i++)
                for(j = 0; j <= n; j++)
                    if(map[i][j] > map[i][k] + map[k][j])
                        map[i][j] = map[i][k] + map[k][j];
        int final = (1<<(p+1))-1;
        for(i = 0; i <= final; i++)
            for(j = 0; j <= p; j++)
                DP[i][j] = -oo;
        map[0][0] = 0;
        best = 0;

        TSP(final, p, 0);
        if(best == 0)
            puts("Don't leave the house");
        else
            printf("Daniel can save $%d.%02d\n", best/100, best%100);
    }
    return 0;
}





/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int V,E;
long long adjM[55][55];
long long shopM[15][15];
vector<long long> offer;
int offercount;
long long memo[15][1 << 15];

long long dp(int at, int bitmask, long long saving){//printf("%d %d %.2lf %.2lf\n",at,bitmask,saving, shopM[at][0]);
       if (bitmask == (1 << offercount)-1)
          return saving-shopM[at][0];
       
       if (memo[at][bitmask] > -900000000)
          return memo[at][bitmask];
          
       if (at == 0 && bitmask > 1)
          return saving;
          
       long long ans = -1000000000;
       for (int i = 1; i < offercount; i++){
           if (!((bitmask >> i) & 1) && i != at)
              ans = max(ans, dp(i,bitmask | (1 << i),saving - shopM[at][i] + offer[i]));
       }
       
       if (at != 0)
          ans = max(ans,dp(0,bitmask,saving-shopM[at][0]));
          
       memo[at][bitmask] = ans;
       return ans;
}


int main(void){
    int testcases;
    scanf("%d",&testcases);
    
    for (int test = 0; test < testcases; test++){
        scanf("%d %d",&V,&E);
        V++;
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++)
                adjM[i][j] = 1000000000;
            adjM[i][i] = 0;
        }
                
        for (int i = 0; i < E; i++){
            int from, to;
            double amt;
            scanf("%d %d %lf",&from, &to, &amt);
            adjM[from][to] = adjM[to][from] = min(adjM[from][to],(long long)(amt*100+0.000001));
        }
        
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    adjM[i][j] = min(adjM[i][j],adjM[i][k] + adjM[k][j]);
        
        scanf("%d",&offercount);
        offercount++;
        int input;
        double amount;
        vector<int> shops;
        offer.clear();
        shops.push_back(0);
        offer.push_back(0);
        for (int i = 0; i < offercount-1; i++){
            scanf("%d %lf",&input,&amount);
            bool found = false;
            for (int j = 1; j < offer.size(); j++){
                if (shops[j] == input){
                   offercount--;
                   i--;
                   offer[j] += (long long)(amount*100+0.000001);
                   found = true;
                   break;
                }
            }
            if (!found){
                shops.push_back(input);
                offer.push_back((long long)(amount*100+0.000001));
            }
        }
        
        
        for (int i = 0; i < offercount; i++){
            for (int j = i+1; j < offercount; j++)
                shopM[i][j] = shopM[j][i] = adjM[shops[i]][shops[j]];
            shopM[i][i] = 0;
        }
        
        
        printf("-----\n");
        for (int i = 0; i < offercount; i++){
            for (int j = 0; j < offercount; j++)
                printf("%ld ",shopM[i][j]);
            printf("\n");
        }
        printf("-----\n");
       
        for (int i = 0; i < offercount; i++)
            for (int j = 0; j < (1<<offercount); j++)
                memo[i][j] = -1000000000;
        
        
        long long ans = dp(0,1,0);
        if (ans > 0)
            printf("Daniel can save $%d.%02d\n", ans/100, ans%100);
        else
            printf("Don't leave the house\n");
    }
    
    return 0;
}
*/
