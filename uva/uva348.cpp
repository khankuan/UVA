#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[1 << 12];
int next[1 << 12];
        
int dp(int bitmask, int count, int arr[]){
    if (bitmask == (1 << count)-2)
       return 0;
    if (memo[bitmask] != -1)
       return memo[bitmask];
    
    int ans = (1<<31-1), nex, left = 0;
    for (int i = 1; i < count; i++){
        if ((bitmask & (1 << i)) == 0){
           int right = count;
           for (int j = i+1; j < count; j++){
               if ((bitmask & (1 << j)) == 0){
                  right = j;
                  break;
               }
           }
           int newV = dp((bitmask | (1 << i)), count, arr) + arr[left]*arr[i]*arr[right];
           if (newV < ans){
              ans = newV;
              nex = i;
           }
           left = i;
        }
    }
    memo[bitmask] = ans;
    next[bitmask] = nex;
    return ans;
}

int main(void){

    int count, test = 0;
    while(true){
        test++;
        scanf("%d",&count);
        if (count == 0)
           break;
        int arr[count+1];
        
        int input;
        scanf("%d",&arr[0]);
        for (int i = 1; i < count; i++){
            scanf("%d",&arr[i]);
            scanf("%d",&arr[i+1]);
        }
        scanf("%d",&arr[count]);
        
        memset(memo,-1,sizeof(memo));
        memset(next,-1,sizeof(next));
        
        dp(0,count,arr);
        int leftBrack[count+1], rightBrack[count+1];       
        memset(leftBrack,0,sizeof(leftBrack));
        memset(rightBrack,0,sizeof(rightBrack));
        int bitmask = 0;
        while (true){
              if (next[bitmask] < 0 || next[bitmask] > count-1)
                 break;
              int left = 0, right = count-1;
              int balance = 0;
              for (int i = next[bitmask]-1; i > 0; i--){
                  balance += leftBrack[i] - rightBrack[i];
                  if (balance == 0){
                     left = i;
                     break;
                  }
              }
              leftBrack[left]++;
              balance = 0;
              for (int i = next[bitmask]; i < count; i++){
                  balance += leftBrack[i] - rightBrack[i];
                  if (balance == 0){
                     right = i;
                     break;
                  }
              }
              rightBrack[right]++;
              bitmask = (bitmask | (1 << next[bitmask]));
              if (bitmask == (1 << count)-2)
                 break;
        }
        
        printf("Case %d: ",test);
        for (int i = 0; i < count; i++){
            for (int j = 0; j < leftBrack[i]; j++)
                printf("(");
            printf("A%d",i+1);
            for (int j = 0; j < rightBrack[i]; j++)
                printf(")");
            if (i < count-1)
               printf(" x ");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
