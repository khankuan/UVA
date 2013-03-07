#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
    int P,C;
    while(true){
        scanf("%d %d", &P ,&C);
        if (P == 0 && C == 0)
           break;
        
        int arr[P];
        for (int i = 0; i < P; i++)
            arr[i] = i;
        
        
        pair<int,int> people[C];
        int rs[C];
        for (int i = 0; i <  C; i++)
            scanf("%d %d %d",&people[i].first,&people[i].second,&rs[i]);
        
        int count = 0;
        while(true){
            bool valid = true;
            for (int i = 0; i < C; i++){
                if (rs[i] < 0){
                   int distance = abs(arr[people[i].first] - arr[people[i].second]);
                   if (distance < -rs[i]){
                      valid = false;
                      break;
                   } 
                }    
                
                if (rs[i] > 0){
                   int distance = abs(arr[people[i].first] - arr[people[i].second]);
                   if (distance > rs[i]){
                      valid = false;
                      break;
                   } 
                }    
            }
            if (valid)
               count++;
            
            if (!next_permutation(arr, arr+P))
               break;
        }
        
        printf("%d\n",count);
        
    
    }


    return 0;
}
