#include <cstdio>
#include <set>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main(void){
    
    int count;
    scanf("%d",&count);
    for (int test = 0; test < count; test++){
        int battle, green, blue;
        multiset<int> sBlue, sGreen;
        scanf("%d %d %d", &battle, &green, &blue);
        for (int i = 0; i < green; i++){
            int input;
            scanf("%d",&input);
            sGreen.insert(input);
        }
        for (int i = 0; i < blue; i++){
            int input;
            scanf("%d",&input);
            sBlue.insert(input);
        }
        
        while (sBlue.size() != 0 && sGreen.size() != 0){
            int minB = min(battle, (int)(sBlue.size()));
            minB = min(minB, (int)(sGreen.size()));
            int remains[minB];
            bool greenWins[minB];
            memset(greenWins, 0, sizeof(greenWins));
                        
            for (int i = 0; i < minB; i++){
                multiset<int>::iterator itGreen = sGreen.end(), itBlue = sBlue.end();   
                itGreen--;
                itBlue--;
                remains[i] = abs(*itGreen - *itBlue);
                if (*itGreen > *itBlue)
                   greenWins[i] = true;
                else
                   greenWins[i] = false;
                
                sGreen.erase(itGreen);
                sBlue.erase(itBlue);
            }
            for (int i = 0; i < minB; i++){
                if (remains[i] > 0){
                   if (greenWins[i])
                      sGreen.insert(remains[i]);
                   else
                      sBlue.insert(remains[i]);
                }
            }
            
        }
        
        if (sBlue.size() == 0 && sGreen.size() == 0)
           printf("green and blue died\n");
        else if (sBlue.size() == 0){
           printf("green wins\n");
           multiset<int>::reverse_iterator it;
           for (it = sGreen.rbegin(); it != sGreen.rend(); it++)
               printf("%d\n",*it);
        } else {
           printf("blue wins\n");
           multiset<int>::reverse_iterator it;
           for (it = sBlue.rbegin(); it != sBlue.rend(); it++)
               printf("%d\n",*it);
        } 
        if (test != count-1)
           printf("\n");
    }
    system("pause");
    return 0;
}
