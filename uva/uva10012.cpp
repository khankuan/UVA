#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

double d(double i, double j){
       return sqrt(4*i*j);
}
  
int n;
double radius[10];
double x[10];
vector<int> took;
double minimum;

void recurse(int taken, double maxcplus){
       if (taken == (1 << n)-1){
          minimum = min(minimum,maxcplus);
          return;
       }

       for (int i = 0; i < n; i++){
           if (!((taken >> i) & 1)){
              x[i] = radius[i];
              for (int j = 0; j < took.size(); j++)
                  x[i] = max(x[i],x[took[j]] + d(radius[took[j]], radius[i]));
              took.push_back(i);
              recurse(taken|(1<<i),max(maxcplus,x[i] + radius[i]));
              took.pop_back();
              
           }
       }
}

int main(void){
    int testcases;
    scanf("%d",&testcases);
    
    for (int test = 0; test < testcases; test++){
        scanf("%d",&n);
        double input;
        minimum = 999999999.0;
        for (int i = 0; i < n; i++){
            scanf("%lf",&input);
            radius[i] = input;
        }
        
        recurse(0,0);
        printf("%.3lf\n",minimum);
    }
    
    return 0;
}
