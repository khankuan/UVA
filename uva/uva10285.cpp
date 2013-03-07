#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r,c;
int memo[200][200];
int weight[200][200];

int slide(int x, int y){
     if (memo[x][y] != -1) // already found out longest streak
          return memo[x][y];
     
     memo[x][y] = 1;
     if (weight[x][y] > weight [x-1][y] && x > 0)   // can slide
          memo[x][y] = max(memo[x][y], slide(x-1,y) + 1);
     if (weight[x][y] > weight [x][y-1] && y > 0)
          memo[x][y] = max(memo[x][y], slide(x,y-1) + 1);
     if (weight[x][y] > weight [x+1][y] && x < r-1)
          memo[x][y] = max(memo[x][y], slide(x+1,y) + 1);
     if (weight[x][y] > weight[x][y+1] && y < c-1)
          memo[x][y] = max(memo[x][y], slide(x,y+1) + 1);

     return memo[x][y];
}


int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    
    for (int test = 0; test< testcases; test++){
        char name[5000];
        scanf("%s %d %d",&name, &r,&c);
        memset(memo,-1,sizeof(memo));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                scanf("%d",&weight[i][j]);
                    
        int maxi = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                maxi = max(maxi,slide(i,j));
                
        printf("%s: %d\n",name,maxi);
    
    }

    return 0;
}
