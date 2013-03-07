#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char s[1005];
vector<vector<int> > len;

int dp(int x, int y){
    if (x < 0 || y == strlen(s))
       return 0;
    if (len[x][y] != -1)
       return len[x][y];
    
    if (s[x] == s[y])
        len[x][y] = 2 + dp(x+1,y-1);
    else
        len[x][y] = max(dp(x+1,y),dp(x,y-1));
       
    return len[x][y];
}

int main(void){
    int testcases;
    scanf("%d",&testcases);
    char dummy[100];
    gets(dummy); 
    for (int test = 0; test< testcases; test++){
        gets(s);
        if (strlen(s) == 0){
           printf("0\n");
           continue; 
        }
        len.resize(strlen(s));
        for (int i = 0; i < strlen(s); i++){
            len[i].resize(strlen(s));
            len[i].assign(strlen(s),-1);
        }
            
        for (int i = 0; i < strlen(s); i++)
            len[i][i] = 1;
        for (int i = 0; i < strlen(s)-1;i++){
            if (s[i] == s[i+1])
                len[i][i+1] = 2;
            else
                len[i][i+1] = 1;
        }
        printf("%d\n",dp(0,strlen(s)-1));
        
    }

    return 0;
}
