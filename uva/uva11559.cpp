#include <cstdio>
using namespace std;


int main(void){
    int participants,budget,hotels,weeks;
    while (scanf("%d %d %d %d",&participants, &budget, &hotels, &weeks) == 4){
        int min = 1000000000;
        for (int i = 0; i < hotels; i++){
              int cost;
              scanf("%d",&cost);
              for (int j = 0; j < weeks; j++){
                  int input;
                  scanf("%d",&input);
                  int curCost = participants * cost;
                  if (input > participants && curCost <= budget){
                     if (curCost < min)
                        min = curCost;
                  }
    
              }  

        }
        if (min == 1000000000)
           printf("stay home\n");
        else
            printf("%d\n",min);
    }
    return 0;

}
