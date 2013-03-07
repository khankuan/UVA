#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double x[10010],y[10010];
int r[10010];

struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } 
};
  
double dist(int p1, int p2) { // get Euclidean distance of two points
  return hypot(x[p1] - x[p2], y[p1] - y[p2]); } // as shown earlier
  
int cmp(const void *_a,const void *_b){
    int *a=(int *)_a;
    int *b=(int *)_b;
    return x[*a]>x[*b]?1:-1;
}

double minimise(int start, int end){

       if (start+1 == end)
           return dist(r[start],r[end]);
       
       if (start >= end)
          return 9999999.0;
          
       int mid = (end+start)/2;
       double left = minimise(start,mid);
       double right = minimise(mid,end);
       double ans = min(left,right);

       for (int i = mid-1; i >= start && x[r[mid]]-x[r[i]]<ans; i--)
           for (int j = mid+1; j <= end && x[r[j]]-x[r[mid]]<ans; j++)
               ans = min(ans,dist(r[i],r[j]));
           
       return ans;
}


int main(void){
    int count;
    while(true){
        scanf("%d",&count);
        if (count == 0)
           break;

        for (int i = 0; i < count; i++){
            double xi,yi;
            scanf("%lf %lf",&xi,&yi);
            x[i] = xi;
            y[i] = yi;
            r[i] = i;
        }
        
        qsort(r,count,sizeof(r[0]),cmp);
        
        double mindist = 9999999.0;
        mindist = min(mindist,minimise(0,count-1));
        
        if (mindist < 10000.0)
            printf("%.4lf\n",mindist);
        else
            printf("INFINITY\n");
    }
    
    return 0;
}
