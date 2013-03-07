#include <cstdio>
#include <cmath>
using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

struct point_i { int x, y; // whenever possible, work with point_i
  point_i(int _x, int _y) { x = _x, y = _y; }
};
struct point { double x, y;
  point(double _x, double _y) { x = _x, y = _y; }
};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca; }

double perimeter(point a, point b, point c) {
  return dist(a, b) + dist(b, c) + dist(c, a); }

double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); }

double area(point a, point b, point c) {
  return area(dist(a, b), dist(b, c), dist(c, a)); }

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }

double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a)); }

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

bool canFormTriangle(double a, double b, double c) {
  return (a + b > c) && (a + c > b) && (b + c > a); }

// not tested yet
// circumcenter of circle through three points
int circle(double a, double b, double c, double *r) {
  *r = a*b*c/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
  return 1;
}

int inCircle2(point p, point q, point r, point s) {
  return 0; // not yet implemented
}

int main() {
    double one, two, three;
    while(scanf("%lf %lf %lf",&one,&two,&three) == 3){
        double r;
        double areaTri = area(one,two,three);
        double areaSmallCir = rInCircle(one,two,three);
        areaSmallCir *= areaSmallCir * PI;
        circle(one,two,three,&r);
        printf("%.4lf %.4lf %.4lf\n",r*r*PI-areaTri,areaTri-areaSmallCir,areaSmallCir);
    }
  return 0;
}
