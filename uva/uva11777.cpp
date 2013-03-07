#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int testcases;
    scanf("%d", &testcases);
    for (int test = 0; test< testcases; test++){
        int sum = 0;
        int input;
        int classtest[3];
        for (int i = 0; i < 4; i++){
            scanf("%d",&input);
            sum += input;
        }
        scanf("%d %d %d",&classtest[0], &classtest[1], &classtest[2]);
        std::sort(classtest,classtest+3);
        
        sum += (classtest[2] + classtest[1])/2;
        if (sum >= 90)
           printf("Case %d: A\n",test+1);
        else if (sum >= 80)
           printf("Case %d: B\n",test+1);
        else if (sum >= 70)
           printf("Case %d: C\n",test+1);
        else if (sum >= 60)
           printf("Case %d: D\n",test+1);
        else 
           printf("Case %d: F\n",test+1);
    }   
    return 0;
}
