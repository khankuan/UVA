#include <cstdio>
#include  <cstdlib>
#include <cstring>
using namespace std;

int main(void){
    
    
    bool memo[1000001];
    int count = 1;
    int i = 1;
    memset(memo,false,sizeof(memo));
    memo[1] = true;
    while (count != 1500){
          i++;
          int current = i;
          if (i > 1000000){
              while (current % 2 == 0 && current > 1000000)
                    current /= 2;
              while (current % 3 == 0 && current > 1000000)
                    current /= 3;
              while (current % 5 == 0 && current > 1000000)
                    current /= 5;
          } else {
              if (current % 2 == 0)
                    current /= 2;
              if (current % 3 == 0)
                    current /= 3;
              if (current % 5 == 0)
                    current /= 5;
          }
          //printf("%d %d\n",i, current);
          if (current <= 1000000 && memo[current]){//printf("%d %d\n",i,count);
             if (i <= 1000000)
                memo[i] = true;
             count++; 
          } else if (i <= 1000000)
            memo[i] = false;
    }
    
    printf("The 1500'th ugly number is %d.\n",i);
    system("pause");
    return 0;
}
