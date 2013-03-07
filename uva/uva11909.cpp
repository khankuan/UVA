#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI acos(-1.0)

int main(void){
    double l,w,h,a;
    while(scanf("%lf %lf %lf %lf",&l,&w,&h,&a) == 4){
        double theshort = tan(a*PI/180)*l;
        if (theshort <= h)
           printf("%.3lf mL\n",w*(h*l-0.5*l*l*tan(a*PI/180)));
        else
           printf("%.3lf mL\n",h*0.5*h/tan(a*PI/180)*w);
    }
    return 0;
}
