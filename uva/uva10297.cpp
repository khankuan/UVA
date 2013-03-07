#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI acos(-1.0)

int main(void){
    
    double D, V;
    while(true){
        scanf("%lf %lf",&D,&V);
        if (D == 0 && V == 0)
           break;
        printf("%.3lf\n",pow(D*D*D-6*V/PI,(double)1/3));
    }

    return 0;
}
