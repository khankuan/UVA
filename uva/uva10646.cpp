#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


int main(void){
    int testcases;
    scanf("%d",&testcases);
    getchar();
    for (int test = 0; test < testcases; test++){
        char deck [52][10];
        for (int i = 51; i >= 0; i--){
            scanf("%s", &deck[i]);
            if (i == 26)
               getchar();
        }
        
        int cur = 25;
        int y = 0;
        int takeAway = 0;
        
        for (int times = 0; times < 3; times++){
            char top[10];
            strcpy(top,deck[cur+takeAway]);
            int value;
            if (top[0] > '1' && top[0] <= '9')
                value = top[0] - '0';
            else
                value = 10;
            y += value;
            takeAway += 10 - value + 1;

        }
        cur += takeAway;
        for (int i = 25; i >= 0; i--)
            strcpy(deck[cur-25+i-1],deck[i]);
            
            
        printf("Case %d: %s\n",test+1,deck[51-y]);
    }
    system("pause");
    return 0;
}
