#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

double dp(int bitmask, int count, int current, double memo[][9], double SSSP[9][9],int next[][9]){
       //printf("%d %d %d %.2lf\n",bitmask,count,current,total);
       if (bitmask == (1 << count) - 1)
          return 0;
       if (memo[bitmask][current] != -1.0)
          return memo[bitmask][current];
       
       double ans = 10000000.0;
       for (int i = 0; i < count; i++){
           if ((bitmask & (1 << i)) == 0){
              double ifTake = SSSP[current][i] + dp((bitmask | (1 << i)), count, i,memo,SSSP,next);
              if (ifTake < ans){
                 ans = ifTake;
                 next[bitmask][current] = i;
              }
           }
       }
       memo[bitmask][current] = ans;
       return ans;
}

int main(void){
    
    int count, test = 0;
    while(true) {
        test++;
        scanf("%d",&count);
        if (count == 0)
           break;
        int x[count], y[count];
        for (int i = 0; i < count; i++)
            scanf("%d %d",&x[i],&y[i]);
            
        double SSSP[9][9];
        memset(SSSP,0,sizeof(SSSP));
        //int next[9];
        //memset(next,-1,sizeof(next));
        
        for (int i = 0; i < count; i++)
            for (int j = i+1; j < count; j++)
                SSSP[i][j] = SSSP[j][i] = pow((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]),0.5) + 16.0;
        double memo[1 << count][9];
        int next[1 << count][9];
        memset(next,-1,sizeof(next));
        for (int i = 0; i < (1 << count); i++)
            for (int j = 0; j < 9; j++)
                memo[i][j] = -1.0;
        
        dp(0,count,8,memo,SSSP,next);
        printf("**********************************************************\n");
        printf("Network #%d\n",test);
        int current = next[0][8];
        int bitmask = 0;
        while(true){
            bitmask = (bitmask | (1 << current));
            if (next[bitmask][current] == -1) 
               break;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
            x[current],y[current],x[next[bitmask][current]],y[next[bitmask][current]],SSSP[current][next[bitmask][current]]);
            current = next[bitmask][current];
        }
        printf("Number of feet of cable required is %.2lf.\n",memo[0][8]);
    }
    
    return 0;
}
