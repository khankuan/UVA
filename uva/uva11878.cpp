#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

int main(void){
    int first,second;
    char sign;
    int correct = 0;
    while(scanf("%d",&first) == 1){
        scanf("%c",&sign);
        scanf("%d",&second);
        getchar();
        char ans[5];
        gets(ans);
        if (ans[0] == '?')
           continue;
        
        int answer = atoi(ans);
        if (sign == '-'){
           if (first - second == answer)
              correct++;
        } else {
           if (first + second == answer)
              correct++;
        } 
    }
    printf("%d\n",correct);
    
    return 0;
}
