#include <stdio.h>
#include <stdlib.h>

int main(void){
    int count;
    scanf("%d\n",&count);
    for (int i = 0; i < count; i++){
        int s,d;
        scanf("%d %d", &s, &d);
        if ((s+d)%2 || d > s)
           printf("impossible\n");
          else 
           printf("%d %d\n",(s+d) >> 1,(s-d) >> 1);
           
    }
    system("pause");
    return 0;
}
