#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int input;
    vector<vector<int> > fx;
    vector<vector<int> > sx;
    fx.assign(100000,vector<int>());
    sx.assign(100000,vector<int>());
    int y[] = {0,1,2,3,4,5,6,7,8,9};
    while(next_permutation(y, y+10)){
         int first = y[0]*10000 + y[1]*1000 + y[2] * 100 + y[3] * 10 + y[4];
         int second = y[5]*10000 + y[6]*1000 + y[7] * 100 + y[8] * 10 + y[9];
         if (first%second == 0){
            fx[first/second].push_back(first);
            sx[first/second].push_back(second);
         }
    }
    
    bool firsttest = true;
    while(true){
        scanf("%d", &input);
        if (input == 0)
           break;
        if (!firsttest)
            printf("\n");
        else
            firsttest = false;
        
        if (fx[input].size() == 0)
           printf("There are no solutions for %d.\n",input);
        else{
             for (int i = 0; i < fx[input].size(); i++){
                 if (fx[input][i] < 10000)
                      printf("0%d / %d = %d\n",fx[input][i],sx[input][i],input);
                 else if (sx[input][i] < 10000)
                      printf("%d / 0%d = %d\n",fx[input][i],sx[input][i],input);
                 else
                      printf("%d / %d = %d\n",fx[input][i],sx[input][i],input);
             }
        }
    
    }
    
    
    return 0;
}
