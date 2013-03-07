#include<cstdio>
#include<cmath>
using namespace std;

#define PI acos(-1.0)

int main(void){
    int test = 1;
    double l,w,r;
    double length;
    while(scanf("%lf : %lf",&l,&w) == 2){
        r = w/l;
        length = 200.0/(atan(r)*sqrt(1+r*r) + 1.0);
        printf("Case %d: %.10f %.10f\n",test,length,length*r);
        test++;
    }
    return 0;
} 
