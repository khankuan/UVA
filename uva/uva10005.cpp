#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

#define EPS 1e-6
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } };

struct point_i { int x, y; // whenever possible, work with point_i
  point_i(int _x, int _y) { x = _x, y = _y; } // constructor (optional)
};

double dist(point p1, point p2) { // get Euclidean distance of two points
  return hypot(p1.x - p2.x, p1.y - p2.y); } // as shown earlier


int inCircle(point p, point c, double r) { // all integer version
  double dx = p.x - c.x, dy = p.y - c.y;
  double Euc = dx * dx + dy * dy, rSq = r * r; 
  return Euc < rSq ? 0 : (fabs(Euc - rSq) < EPS) ? 1 : 2; } // inside/border/outside

bool circle2PtsRad(point p1, point p2, double r, point *c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; }

int main() {
    int count;
    while(true){
        vector<point> arr;
        scanf("%d",&count);
        if (count == 0)
           break;
        double x,y;
        for (int i = 0; i < count; i++){
            scanf("%lf %lf",&x,&y);
            arr.push_back(point(x,y));
        }
        double radius;
        scanf("%lf",&radius);
        
        bool has;
        point c = point(0,0);
        for (int a = 0; a < count ; a++){
            for (int b = a+1; b < count ;b++){           
                has = circle2PtsRad(arr[a],arr[b],radius,&c);
        
                for (int i = 0; i < count; i++){
                    if (i == a || i == b)
                       continue;
                    if (inCircle(arr[i],c,radius) == 2){
                       has = false;
                       break;
                    }
                }
                
                if (has)
                    break;
                             
                has = circle2PtsRad(arr[b],arr[a],radius,&c);
                
                for (int i = 0; i < count; i++){
                    if (i == a || i == b)
                       continue;
                    if (inCircle(arr[i],c,radius) == 2){
                       has = false;
                       break;
                    }
                }
                
                if (has)
                   break;
            }
            if (has)
               break;
        }
        if (has)
           printf("The polygon can be packed in the circle.\n");
        else
            printf("There is no way of packing that polygon.\n");
    }

    return 0;
}
