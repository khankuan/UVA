#include <cstdio>
using namespace std;


int main(void){
    int target, num,test = 0;
    while(scanf("%d %d",&target,&num) == 2){
        if (target == 0 && num == 0)
           break;
        test++;
        if (target - num <= 0)
             printf("Case %d: 0\n",test);
        else if (target> num * 27)
             printf("Case %d: impossible\n",test);
        else
             printf("Case %d: %d\n",test,(target-1)/num);
    
    }


    return 0;
}
