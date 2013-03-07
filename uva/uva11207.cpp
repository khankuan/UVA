#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int count;
    while(true){
        scanf("%d",&count);
        if (count == 0)
           break;
        
        double x,y; 
        double highest = -1;  
        int index = -1;
        for (int i = 0; i < count ;i++){
            scanf("%lf %lf",&x,&y);
            if (highest < min(x/4,y)){
               highest = min(x/4,y);
               index = i;
            }
            if (highest < min(x/2,y/2)){
               highest = min(x/2,y/2);
               index = i;
            }
            if (highest < min(x,y/4)){
               highest = min(x,y/4);
               index = i;
            }
        }
        printf("%d\n",index+1);
    
    }
    
    
    return 0;
}
