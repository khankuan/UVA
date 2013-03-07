#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    long long ways[44];
    memset(ways,0,sizeof(ways));
    ways[0] = 1;
    for (int i = 0; i < 41; i++){
        ways[i+1] += ways[i];
        ways[i+2] += (ways[i] << 2);
        ways[i+3] += (ways[i] << 1);
    }   
    
    int testcases, input;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d",&input);
        printf("%llu\n",ways[input]);
    }
    
    return 0;
}
