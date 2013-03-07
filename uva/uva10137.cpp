#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


int main(void){
    int count;
    while(true){
        scanf("%d",&count);
        if (count == 0)
           break;
        
        double sum = 0.0;
        double arr[count];
        for (int i = 0; i < count; i++){
            scanf("%lf",&arr[i]);
            sum += arr[i];
        }
        
        double avg = sum/count;
        avg *= 100;
        avg = floor(avg)/100.0;
        double add = 0.0, add2 = 0.0;
        
        for (int i = 0; i < count; i++){
            if (arr[i] > avg)
               add += arr[i] - avg - 0.01;
            else
                add2 += avg - arr[i];
        }

        double ans = max(add,add2);
        
        printf("$%.2lf\n",ans);
    }
    
    
    return 0;
}
