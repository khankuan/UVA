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

//struct point_i { int x, y; }; // basic raw form, minimalist mode
struct point_i { int x, y; // whenever possible, work with point_i
  point_i(int _x, int _y) { x = _x, y = _y; } // constructor (optional)
};

struct point { double x, y; // we use double for most examples in this source code
  point(double _x, double _y) { x = _x, y = _y; } };

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
    if (cross(p, P[i], P[i + 1]) < 0) // right turn/cw
         sum -= angle(p, P[i], P[i + 1]);
    else sum += angle(p, P[i], P[i + 1]); } // left turn/ccw
  return (fabs(sum - 2*PI) < EPS || fabs(sum + 2*PI) < EPS); }

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
  double a = B.y - A.y;
  double b = A.x - B.x;
  double c = B.x * A.y - A.x * B.y;
  double u = fabs(a * p.x + b * p.y + c);
  double v = fabs(a * q.x + b * q.y + c);
  return point((p.x * v + q.x * u) / (u + v),
               (p.y * v + q.y * u) / (u + v)); }

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

bool areSame(point_i p1, point_i p2) { // integer version
  return p1.x == p2.x && p1.y == p2.y; } // precise comparison

bool areSame(point p1, point p2) { // floating point version
  // use EPS when testing equality of two floating points
  return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS; }

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
  // rotation matrix R(theta) = [cos(theta) -sin(theta)]
  //                            [sin(theta)  cos(theta)]
  double rad = DEG_to_RAD(theta); // must work in radian
  return point(p.x * cos(rad) - p.y * sin(rad),
               p.x * sin(rad) + p.y * cos(rad)); }

struct line { double a, b, c; }; // a way to represent a line

// the answer is stored in the third parameter (pass byref)
void pointsToLine(point p1, point p2, line *l) {
  if (p1.x == p2.x) { // vertical line is handled nicely here
    l->a = 1.0;   l->b = 0.0;   l->c = -p1.x;
  } else {
    l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1.0;
    l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
} }

// not needed since we will use the more robust form: ax + by + c = 0 (see above)
//struct line2 { double m, c; }; // another way to represent a line
//
//int pointsToLine(point p1, point p2, line2 *l) {
//  if (p1.x == p2.x) { // special case: vertical line
//    l->m = INF; // l contains m = INF and c = x_value
//    l->c = p1.x; // to denote vertical line x = x_value
//    return 0; // we need this return variable to differentiate result
//  }
//  else {
//    l->m = (double)(p1.y - p2.y) / (p1.x - p2.x);
//    l->c = p1.y - l->m * p1.x;
//    return 1; // l contains m and c of the line equation y = mx + c
//} }

bool areParallel(line l1, line l2) { // check coefficient a + b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

bool areSame(line l1, line l2) { // also check coefficient c
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point *p) {
  if (areSame(l1, l2)) return false; // all points intersect
  if (areParallel(l1, l2)) return false; // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p->x = (double)(l2.b * l1.c - l1.b * l2.c) / 
                 (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS) // test for vertical line
    p->y = - (l1.a * p->x + l1.c) / l1.b; // avoid div by zero
  else // this is another special case in geometry problem...
    p->y = - (l2.a * p->x + l2.c) / l2.b;
  return true; }

struct vec { double x, y; // similar to point
  vec(double _x, double _y) { x = _x, y = _y; } };

vec toVector(point p1, point p2) { // convert 2 points to vector
  return vec(p2.x - p1.x, p2.y - p1.y); }

vec scaleVector(vec v, double s) { // s = [<1 ...   1   ... >1]
  return vec(v.x * s, v.y * s); }  // shorter v  same v  longer v

point translate(point p, vec v) { // translate p according to v
  return point(p.x + v.x , p.y + v.y); }

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line *l) {
  l->a = -m; // always -m
  l->b = 1;  // always 1
  l->c = -((l->a * p.x) + (l->b * p.y)); } // compute this

void closestPoint(line l, point p, point *ans) {
  line perpendicular; // perpendicular to l and pass through p
  if (fabs(l.b) < EPS) { // special case 1: vertical line
    ans->x = -(l.c);   ans->y = p.y;      return; }

  if (fabs(l.a) < EPS) { // special case 2: horizontal line
    ans->x = p.x;      ans->y = -(l.c);   return; }

  pointSlopeToLine(p, 1 / l.a, &perpendicular); // normal line
  // intersect line l with this perpendicular line
  // the intersection point is the closest point
  areIntersect(l, perpendicular, ans); }

// returns the distance from p to the line defined by
// two points A and B (A and B must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point A, point B, point *c) {
  // formula: cp = A + (p-A).(B-A) / |B-A| * (B-A)
  double scale = (double)
    ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
    ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
  c->x = A.x + scale * (B.x - A.x);
  c->y = A.y + scale * (B.y - A.y);
  return dist(p, *c); } // Euclidean distance between p and *c

// returns the distance from p to the line segment ab defined by
// two points A and B (still OK if A == B)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point A, point B, point* c) {
  if ((B.x-A.x) * (p.x-A.x) + (B.y-A.y) * (p.y-A.y) < EPS) {
    c->x = A.x;   c->y = A.y; // closer to A
    return dist(p, A); } // Euclidean distance between p and A
  if ((A.x-B.x) * (p.x-B.x) + (A.y-B.y) * (p.y-B.y) < EPS) {
    c->x = B.x;   c->y = B.y; // closer to B
    return dist(p, B); } // Euclidean distance between p and B
  return distToLine(p, A, B, c); } // run distToLine as above




int main() {
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test< testcases; test++){
        int count;
        scanf("%d",&count);
        double x,y,w,h,angle;
        double totalarea = 0.0;
        vector<point> arr;
        for (int i = 0; i < count; i++){
            scanf("%lf %lf %lf %lf %lf",&x,&y,&w,&h,&angle);
            angle = 360.0-angle;
            point mid = rotate(point(w/2,h/2),angle);
            vec v = toVector(mid,point(x,y));
            point one = translate(point(0,0),v);
            point two = translate(rotate(point(w,0),angle),v);
            point three = translate(rotate(point(w,h),angle),v);
            point four = translate(rotate(point(0,h),angle),v);
            arr.push_back(one);
            arr.push_back(two);
            arr.push_back(three);
            arr.push_back(four);
            totalarea += w*h;
        }
        arr = CH(arr);
        printf("%.1lf %%\n",totalarea*100/area(arr));
    }

    return 0;
}
