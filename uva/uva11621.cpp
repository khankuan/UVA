#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main(void){
    int input;
    vector<int> next;
    for (int i = 0; i < 31; i++){
        for (int j = 0; j < 21; j++){
            int c = 1 << i;
            bool overflow = false;
            for (int k = 0; k < j; k++){
                if (c> 715827882){
                       overflow = true;
                       break;
                }
                c *= 3;
            }
            if (!overflow)
               next.push_back(c);
        }
    }
    std::sort(next.begin(), next.end());
    
    while(true){
        scanf("%d",&input);
        if (input == 0)
           break;
        cout << *(upper_bound(next.begin(),next.end(),input-1)) << endl;
    }
    return 0;
}
