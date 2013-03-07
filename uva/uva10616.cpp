#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long pick(int i, int count, long long modSum, int div, int itemsLeft, int arr[], long long memo[][21][11]){       
    if (itemsLeft == 0){
       if (modSum == 0)
           memo[i][modSum][itemsLeft] = 1;
       else
           memo[i][modSum][itemsLeft] = 0;
           if (modSum == 0)
       return memo[i][modSum][itemsLeft];
    }
    if (memo[i][modSum][itemsLeft] != -1)
       return memo[i][modSum][itemsLeft];
    if (i == count)
       return 0;
       
    int remainder;
    if (arr[i] < 0)
        remainder = div + (arr[i]%div);
    else
        remainder = arr[i]%div;
    return memo[i][modSum][itemsLeft] = pick(i+1,count,modSum,div,itemsLeft,arr,memo)+
                                            pick(i+1,count,(modSum+remainder)%div,div,itemsLeft-1,arr,memo);
}


int main(void){
    int count, qcount, test = 0;
    while(true){
        test++;
        scanf("%d %d",&count, &qcount);
        if (count == 0 && qcount == 0)
           break;
        int arr[count];
        for (int i = 0; i < count; i++)
            scanf("%d", &arr[i]);
        
        cout << "SET " << test << ":" << endl;      
        for (int i = 0; i < qcount; i++){
            long long memo[count+1][21][11];
            memset(memo, -1, sizeof(memo));
            int div, itemsLeft;
            scanf("%d %d",&div,&itemsLeft);
            cout << "QUERY " << i+1 << ": " << pick(0,count,0,(long long)div,itemsLeft,arr,memo) << endl;
        }
        
    }

    return 0;
}
