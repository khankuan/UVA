#include <cstdio>
using namespace std;

int main(void){
    int n,k;
    while(scanf("%d %d",&n,&k) == 2){   
        int total = 0;
        while (n != 0){
              total += n-n%k;
              if (n < k){
                 total += n;
                 break;
              }
              n = n/k+n%k;
        }
        printf("%d\n",total);
    }
}
