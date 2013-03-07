#include <cstdio>
#include <cmath>
using namespace std;


int main(void){
    int testcases;
    scanf("%d",&testcases);

    for (int test = 0; test <testcases; test++){
        double input;
        scanf("%lf",&input);
        int length = (int)sqrt(input*2- (int) sqrt(input*2));
        printf("%d\n",length);
    }
 
    return 0;
}
