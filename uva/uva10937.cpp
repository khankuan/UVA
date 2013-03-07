#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int map[5555];
int adjMat[15][15];
int t, start;
vector<int> treasure;
int memo[1 << 15][15];

int dp(int bitmask, int at){
    if (bitmask == (1 << t) -1)
       return adjMat[at][t];

    if (memo[bitmask][at] != -1)
       return memo[bitmask][at];
       
    int ans = 100000000;
    for (int i = 0; i < t; i++){
        if (!((bitmask >> i)&1))
           ans = min(ans, dp(bitmask | (1 << i), i) + adjMat[at][i]);
    }

    memo[bitmask][at] = ans;
    return ans;
}

int main(void){
    while(true){
        int h,w;
        scanf("%d %d",&h,&w);
        if (h == 0 && w == 0)
           break;       
        getchar();
        
        treasure.clear();
        for (int i = 0; i < 5555; i++)
            map[i] = 1;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                char input;
                scanf("%c",&input);
                if (input == '@')
                   start = i*100+j;
                else if (input == '*'){
                   map[i*100+j] = 10000;
                   if (i > 0){
                       if (j > 0)
                          map[(i-1)*100+j-1] = 10000;
                       map[(i-1)*100+j] = 10000;
                       map[(i-1)*100+j+1] = 10000;
                   }
                   if (j > 0)
                       map[i*100+j-1] = 10000;
                   map[i*100+j+1] = 10000;
                   if (j > 0)
                       map[(i+1)*100+j-1] = 10000;
                   map[(i+1)*100+j] = 10000;
                   map[(i+1)*100+j+1] = 10000;
                } else if (input == '~' || input == '#'){
                   map[i*100+j] = 10000;    
                } else if (input == '!') 
                   treasure.push_back(i*100+j);
                
                
            }
            getchar();
        }
        treasure.push_back(start);
        t = treasure.size()-1;
        int weights[5555];  
        
        for (int i = 0; i < treasure.size()-1; i++){
            for (int k = 0; k < 5555; k++)
                weights[k] = 10000;
            if (map[treasure[i]] < 10000)
               weights[treasure[i]] = 0;
            
            queue<int> q;
            q.push(treasure[i]);
            
            while (!q.empty()){
                int u = q.front(); q.pop();
                if (u%100 > 0 && map[u-1] < 10000 && weights[u-1] == 10000){
                   weights[u-1] = weights[u] +1;
                   q.push(u-1);
                }
                if (u%100 < w-1 && map[u+1] < 10000 && weights[u+1] == 10000){
                   weights[u+1] = weights[u] +1;
                   q.push(u+1);
                }
                if (u/100 > 0 && map[u-100] < 10000 && weights[u-100] == 10000){
                   weights[u-100] = weights[u] +1;
                   q.push(u-100);
                }
                if (u/100 < h-1 && map[u+100] < 10000 && weights[u+100] == 10000){
                   weights[u+100] = weights[u]+1;
                   q.push(u+100);
                }
            }
            
            for (int j = 0; j < treasure.size(); j++){
                adjMat[i][j] = weights[treasure[j]];
                adjMat[j][i] = weights[treasure[j]];
                adjMat[t][i] = adjMat[i][t] = weights[start];
            }
        }
        
        memset(memo,-1,sizeof(memo));
        int answ = dp(0,t);
        if (answ > 10000)
           printf("-1\n");
        else
           printf("%d\n",answ);
        
    }
    return 0;
}
