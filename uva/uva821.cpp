#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main(void){
    int test = 1;
    bool exiting = false;
    int adjM[100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            adjM[i][j] = 100000000;

    while (true){
          int from, to;
          scanf("%d %d",&from, &to);
          if (from == 0 && to == 0){
             if (!exiting){
                exiting = true;
                
                for (int k = 0; k < 100; k++)
                    for (int i = 0; i < 100; i++)
                        for (int j = 0; j < 100; j++)
                            adjM[i][j] = min(adjM[i][j], adjM[i][k] + adjM[k][j]);
                            
                int avg = 0, count = 0;
                for (int i = 0; i < 100; i++){
                    for (int j = 0; j < 100; j++){
                        if (adjM[i][j] != 100000000 && i != j){
                           count++;
                           avg += adjM[i][j];
                        } 
                    }
                }
                printf("Case %d: average length between pages = %.3lf clicks\n",test,avg/1.0/count);
                test++;
                for (int i = 0; i < 100; i++)
                    for (int j = 0; j < 100; j++)
                        adjM[i][j] = 100000000;
             } else 
               break;
          } else {
            adjM[from-1][to-1] = 1;
            exiting = false;
          }
          
    
    }

    return 0;
}
