#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int calc(int i){
    if (i == 1)
       return 1;
    
    if (i % 2 == 0)
       return calc(i >> 1) +1;
    else
       return calc(i*3+1) +1;
}


int main(void){
    
    int one,two;

    while(scanf("%d %d",&one,&two) == 2){
        printf("%d %d ",one,two);
        if (one > two){
           int temp = one;
           one = two;
           two = temp;
        }
        int maxV = -1;
        for (int i = one; i <= two; i++)
            maxV = max(maxV,calc(i));
        
        printf("%d\n",maxV);
    
    }
    
    
    return 0;
}
