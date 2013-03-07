#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    
    int n,hours,rate;
    while(true){
        scanf("%d %d %d",&n,&hours,&rate);
        if (n == 0 && hours == 0 && rate == 0)
           break;
           
        int day[n], night[n];
        for (int i = 0; i < n; i++)
            scanf("%d",&day[i]);
        for (int i = 0; i < n; i++)
            scanf("%d",&night[i]);
            
        sort(day,day+n);
        sort(night,night+n);
        
        int over = 0;
        for (int i = 0; i < n; i++){
            int worked = day[i] + night[n-i-1];
            if (worked > hours)
               over += worked - hours;
        }
        printf("%d\n",over*rate);
    }   
    
    return 0;
}
