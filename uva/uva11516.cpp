#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double MINDIFF = 0.05;
const double EPS = 1e-6;

int main(void){
    int testcount;
    scanf("%d",&testcount);
    for (int test = 0; test < testcount; test++){
        int wifi, numhouse;
        scanf("%d %d",&wifi,&numhouse);        
        double dist[numhouse];
        double largest = 0.0;
        for (int i = 0; i < numhouse; i++){
            scanf("%lf",&dist[i]);
            if (dist[i] > largest)
               largest = dist[i];
        }
        sort(dist,dist+numhouse);
        double start = 0.0, end = largest;     
        double diff, previous = largest;
        
        do {
            double middle = (start+end)/2.0, at = 10000000.0;
            int used = 0;
            bool valid = true;
            for (int i = 0; i < numhouse; i++){
                if (fabs(at - dist[i]) > middle - EPS){
                   at = dist[i] + middle;
                   used++;
                   if (used > wifi){
                      valid = false;
                      break;
                   }
                }
            }        
            if (!valid)
                start = middle;
            else
                end = middle;            
            diff = fabs(middle - previous);
            previous = middle;
        } while(diff > MINDIFF);   
        printf("%.1lf\n",previous);
    } 
    return 0;
}
