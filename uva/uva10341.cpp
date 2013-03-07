#include <cstdio>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;

double f(double x){
       return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;       
}

int main(void){
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) == 6){
        if (f(0) * f(1)> 0){
           printf("No solution\n");
           continue;
        }
        double low = 0.0;
        double high = 1.0;
        double mid;
        while( low + 1e-9 < high ){
            mid = (high+low)/2;
            if (f(mid) * f(low) > 0)
                low = mid;
            else
                high = mid;          
        }
        printf("%.4lf\n",mid);
    }

    return 0;
}
