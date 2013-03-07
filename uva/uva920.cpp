#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } };

double dist(point p1, point p2) { // get Euclidean distance of two points
  return hypot(p1.x - p2.x, p1.y - p2.y); } // as shown earlier

bool x_comparator (point a,point b) { return (a.x < b.x); }

int main(void){

    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d",&count);
        vector<point> arr;
        for (int i = 0; i < count; i++){
            double x,y;
            scanf("%lf %lf",&x,&y);
            arr.push_back(point(x,y));
        }
        std:sort(arr.begin(),arr.end(),x_comparator);
        
        double high = arr[arr.size()-2].y;
        double total = dist(arr[arr.size()-1],arr[arr.size()-2]);
        for (int i = arr.size()-3; i >= 0; i--){
            if (arr[i].y <= high)
               continue;
            total += dist(arr[i], arr[i+1])*(arr[i].y-high)/(arr[i].y-arr[i+1].y);
            high = arr[i].y;
        }
        printf("%.2lf\n",total);
    }
    
    return 0;
}
