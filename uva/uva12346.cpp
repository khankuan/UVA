#include <cstdio>
using namespace std;


int main(void){
    int gatecount;
    while(scanf("%d",&gatecount) == 1){
        int flow[gatecount];
        int cost[gatecount];
        for (int i = 0; i < gatecount; i++)
            scanf("%d %d",&flow[i], &cost[i]);
            
        int testcount;
        scanf("%d",&testcount);
        for (int test = 0; test <testcount; test++){
            int totalflow, time;
            scanf("%d %d", &totalflow, &time);
            
            int minimum = (1 << 31) -1;
            
            for (int i = 0; i < (1 << gatecount); i++){
                int sum = 0;
                int tcost = 0;
                for (int j = 0; j < gatecount; j++){
                    if ((i >> j) & 1){
                       sum += flow[j];
                       tcost += cost[j];
                    }
                }
                
                sum *= time;
                if (sum > totalflow){
                   if (minimum > tcost)
                      minimum = tcost;
                }
            
            }
            
            if (minimum == (1 << 31) -1)
                printf("Case %d: IMPOSSIBLE\n",test+1);
            else
                printf("Case %d: %d\n",test+1,minimum);      
        }
    
    }
    return 0;
}
