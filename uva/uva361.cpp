#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point { int x, y; // we use double for most examples in this source code
  point(int _x, int _y) { x = _x, y = _y; } };

double dist(point p1, point p2) { // get Euclidean distance of two points
  return hypot(p1.x - p2.x, p1.y - p2.y); } // as shown earlier

// returns the perimeter of polygon, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(vector<point> P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size(); i++)
    result += dist(P[i], P[(i + 1) % P.size()]);
  return result; }

// returns the area, which is half the determinant
double area(vector<point> P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size(); i++) {
    x1 = P[i].x; x2 = P[(i + 1) % P.size()].x;
    y1 = P[i].y; y2 = P[(i + 1) % P.size()].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x); }

bool collinear(point p, point q, point r) {
  return fabs(cross(p, q, r)) < EPS; }

bool ccw(point p, point q, point r) {
  return cross(p, q, r) > 0; }

// returns true if we always make the same turn while examining
// all the edges of the polygon one by one
bool isConvex(vector<point> P) {
  int sz = (int)P.size();
  if (sz < 3) // boundary case, we treat point/line as not convex
    return false;
  bool isLeft = ccw(P[0], P[1], P[2]); // remember one
  for (int i = 1; i < sz; i++) // compare with others
    if (ccw(P[i], P[(i + 1) % sz], P[(i + 2) % sz]) != isLeft)
      return false; // if different sign->this polygon is concave
  return true; } // this polygon is convex

double angle(point a, point b, point c) {
  double ux = b.x - a.x, uy = b.y - a.y;
  double vx = c.x - a.x, vy = c.y - a.y;
  return acos((ux*vx + uy*vy) / 
              sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy))); }

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point p, vector<point> P) {
  if ((int)P.size() == 0) return false;
  double sum = 0;
  
  for (int i = 0; i < (int)P.size() - 1; i++) {
      if (P[i].x == p.x && P[i].y == p.y)
         return true;
      if (collinear(p,P[i],P[i+1])){
         if (P[i].x <= p.x && p.x <= P[i+1].x || P[i].x >= p.x && p.x >= P[i+1].x){
            if (P[i].y <= p.y && p.y <= P[i+1].y || P[i].y >= p.y && p.y >= P[i+1].y)
               return true;
         }
      }
         //printf("cross: %lf %lf\n",cross(p, P[i], P[i + 1]),angle(p, P[i], P[i + 1]));
    if (cross(p, P[i], P[i + 1]) < 0) // right turn/cw
         sum -= angle(p, P[i], P[i + 1]);
    else sum += angle(p, P[i], P[i + 1]); } // left turn/ccw
    //printf("%lf %lf\n",fabs(sum-2*PI),fabs(sum+2*PI));
  return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS); }

point pivot(0, 0);
bool angle_cmp(point a, point b) { // angle-sorting function
  if (collinear(pivot, a, b))
    return dist(pivot, a) < dist(pivot, b); // which one is closer?
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }

vector<point> CH(vector<point> P) {
  int i, N = (int)P.size();
  if (N <= 3) return P; // special case, the CH is P itself

  // first, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for (i = 1; i < N; i++)
    if (P[i].y  < P[P0].y ||
       (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;
  // swap selected vertex with P[0]
  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

  // second, sort points by angle w.r.t. P0, skipping P[0]
  pivot = P[0]; // use this global variable as reference
  sort(++P.begin(), P.end(), angle_cmp);

  // third, the ccw tests
  point prev(0, 0), now(0, 0);
  stack<point> S; S.push(P[N - 1]); S.push(P[0]); // initial
  i = 1; // and start checking the rest
  while (i < N) { // note: N must be >= 3 for this method to work
    now = S.top();
    S.pop(); prev = S.top(); S.push(now); // get 2nd from top
    if (ccw(prev, now, P[i])) S.push(P[i++]); // left turn, ACC
    else S.pop(); // otherwise, pop until we have a left turn
  }

  vector<point> ConvexHull; // from stack back to vector
  while (!S.empty()) { ConvexHull.push_back(S.top()); S.pop(); }
  return ConvexHull; } // return the result

int main() {
    int c,r,o;
    int test = 1;
    while(true){
        scanf("%d %d %d",&c,&r,&o);
        if (c == 0 && r == 0 && o == 0)
           break;
        vector<point> cop,rob,civ;
        vector<int> cx;
        vector<int> cy;
        
        int x,y;
        for (int i = 0; i < c; i++){
            scanf("%d %d",&x,&y);
            cop.push_back(point(x,y));
        }
        
        for (int i = 0; i < r; i++){
            scanf("%d %d",&x,&y);
            rob.push_back(point(x,y));
        }

        int xi,yi;
        for (int i = 0; i < o; i++){
            scanf("%d %d",&xi,&yi);
            civ.push_back(point(xi,yi));
        }
        
        
        point tempcop = point(1,1);
        if (cop.size() > 0)
           point(cop[0].x,cop[0].y);
        point temprob = point(1,1);
        if (rob.size() > 0)
           point temprob = point(rob[0].x,rob[0].y);
        if (cop.size() > 0){
           cop = CH(cop);printf("asd\n");
           if (cop.size() == 0)
               cop.push_back(tempcop);
           if (cop.size() == 3)
               cop.push_back(cop[0]);
        }
        if (rob.size() > 0){
           rob = CH(rob);
           if (rob.size() == 0)
               rob.push_back(temprob);
           if (rob.size() == 3)
               rob.push_back(rob[0]);
        }
        

        if (test > 1)
           printf("\n");
        printf("Data set %d:\n",test);
        test++;
        for (int i = 0; i < o; i++){
            if (c > 2 && inPolygon(civ[i],cop))
               printf("     Citizen at (%d,%d) is safe.\n",civ[i].x,civ[i].y);
            else if (r > 2 && inPolygon(civ[i],rob))
               printf("     Citizen at (%d,%d) is robbed.\n",civ[i].x,civ[i].y);
            else
               printf("     Citizen at (%d,%d) is neither.\n",civ[i].x,civ[i].y); 
        }
    }
    

    return 0;
}
