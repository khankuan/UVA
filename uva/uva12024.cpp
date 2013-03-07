#include <cstdio>
using namespace std;


int main(void){
    int top[13], bottom[13];
    top[1] = 1;
    bottom[1] = 2;
    top[2] = 2;
    bottom[2] = 6;
    for (int i = 3; i < 13; i++){
        top[i] = i * (top[i-1]+top[i-2]);
        bottom[i] = (i+1) * bottom[i-1];
    }
    
    
    int testcases, input;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d",&input);
        printf("%d/%d\n",top[input-1],bottom[input-1]); 
    }    

    return 0;
}
