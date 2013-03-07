#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    int count;
    bool found[5100];
    while(scanf("%d",&count) == 1){
        memset(found,false, sizeof found);
        int previous;
        scanf("%d",&previous);
        int cur;
        for (int i = 1; i < count; i++){
            scanf("%d",&cur);
            if (cur-previous >count-1 || previous-cur > count-1){
               previous = cur;
               continue;
            }
            if (cur > previous)
                found[cur-previous] = true;
            else
                found[previous-cur] = true;
            previous = cur;
        }
        bool jolly = true;
        for (int i = 1; i < count; i++){
            if (!found[i]){
               jolly = false;
               break;
            }
        }
        if (jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
