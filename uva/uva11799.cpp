#include <cstdio>
using namespace std;


int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d",&count);
        int min = -1;
        for (int j = 0; j < count; j++){
            int input;
            scanf("%d",&input);
            if (input > min)
               min = input;
        }
        printf("Case %d: %d\n",test+1,min);
    }

    return 0;
}
