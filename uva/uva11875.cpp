#include <cstdio>
using namespace std;


int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0 ; test < testcases; test++){
        int count;
        scanf("%d",&count);
        int input;
        for (int i = 0; i < count; i++){
            scanf("%d",&input);
            if (i == count >> 1)
               printf("Case %d: %d\n",test+1,input);
        }
        
    }
    
    
    return 0;
}
