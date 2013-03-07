#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } };


double dist(point p1, point p2) { // get Euclidean distance of two points
  return hypot(p1.x - p2.x, p1.y - p2.y); } // as shown earlier

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x); }

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u + v),
               (p.y * v + q.y * u) / (u + v)); }


// returns the area, which is half the determinant
double area(vector<point> P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size(); i++) {
    x1 = P[i].x; x2 = P[(i + 1) % P.size()].x;
    y1 = P[i].y; y2 = P[(i + 1) % P.size()].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }


// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, vector<point> Q) {
  vector<point> P;
  for (int i = 0; i < (int)Q.size(); i++) {
    double left1 = cross(a, b, Q[i]), left2 = 0.0;
    if (i != (int)Q.size() - 1) left2 = cross(a, b, Q[i + 1]);
    if (left1 > -EPS) P.push_back(Q[i]);
    if (left1 * left2 < -EPS)
      P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
  }
  if (P.empty()) return P;
  if (fabs(P.back().x - P.front().x) > EPS ||
      fabs(P.back().y - P.front().y) > EPS)
    P.push_back(P.front());
  return P; }


int lines, width, height, x, y, px, py, qx, qy;
vector<point> poly;

bool isLeft(point a, point b, point c){
     return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

int main(void){
    int test = 1;
    while(scanf("%d",&lines) == 1){
        scanf("%d %d %d %d",&width,&height,&x,&y);
        poly.clear();
        poly.push_back(point(0,0));
        poly.push_back(point(width,0));
        poly.push_back(point(width,height));
        poly.push_back(point(0,height));
        poly.push_back(point(0,0));
        
        for (int i = 0; i < lines; i++){
            scanf("%d %d %d %d",&px,&py,&qx,&qy); 
            if (isLeft(point(px,py),point(qx,qy),point(x,y)))
                poly = cutPolygon(point(px,py), point(qx,qy), poly);
            else
                poly = cutPolygon(point(qx,qy), point(px,py), poly); 
        }
        
        printf("Case #%d: %.3lf\n", test, area(poly));
        test++;
    }
    
    return 0;
}
