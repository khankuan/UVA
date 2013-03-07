#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define EPS 1e-9



struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } };
  
point c = point(0,0);

double dist(point p1, point p2) { // get Euclidean distance of two points
  return hypot(p1.x - p2.x, p1.y - p2.y); } // as shown earlier
  
double distToLine(point p, point A, point B) {
  // formula: cp = A + (p-A).(B-A) / |B-A| * (B-A)
  double scale = (double)
    ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
    ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
  c.x = A.x + scale * (B.x - A.x);
  c.y = A.y + scale * (B.y - A.y);
  return dist(p, c); } // Euclidean distance between p and *c  
  
  
// returns the distance from p to the line segment ab defined by
// two points A and B (still OK if A == B)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point A, point B) {
  if ((B.x-A.x) * (p.x-A.x) + (B.y-A.y) * (p.y-A.y) < EPS) {
    c.x = A.x;   c.y = A.y; // closer to A
    return dist(p, A); } // Euclidean distance between p and A
  if ((A.x-B.x) * (p.x-B.x) + (A.y-B.y) * (p.y-B.y) < EPS) {
    c.x = B.x;   c.y = B.y; // closer to B
    return dist(p, B); } // Euclidean distance between p and B
  return distToLine(p, A, B); } // run distToLine as above



int main(void){
    double mx, my;
    while(scanf("%lf %lf",&mx,&my) == 2){
        point M = point(mx, my);
        int count;
        scanf("%d",&count);
        double px, py;
        scanf("%lf %lf",&px,&py);
        point P1 = point(px,py);
        double min = 99999999.0;
        point minP = point(0,0);
        
        for (int i = 0; i < count; i++){
            double px2, py2;
            scanf("%lf %lf",&px2,&py2);
            point P2 = point(px2,py2);
            double nearest = distToLineSegment(M,P1,P2);//printf("asd\n");
            if (nearest < min){
               min = nearest;
               minP = point(c.x,c.y);
            }
            P1 = point(P2.x,P2.y);
        }
        printf("%.4lf\n%.4lf\n",minP.x,minP.y);
    }
    
    return 0;
}
