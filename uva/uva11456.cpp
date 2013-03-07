#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int LIS(int i, int count, int memo[], int arr[]) {
    if (i == count - 1) {memo[i] = 1; return 1;}
    if (memo[i] != 0) return memo[i];
    
    int ans = 1;
    for (int j = i + 1; j < count; j++)
        if (arr[i] < arr[j])
           ans = max(ans, LIS(j,count,memo,arr) + 1);
    memo[i] = ans;
    return ans;
}

int LDS(int i, int count, int memo[], int arr[]) {
    if (i == count - 1) {memo[i] = 1; return 1;}
    if (memo[i] != 0) return memo[i];
    
    int ans = 1;
    for (int j = i + 1; j < count; j++)
        if (arr[i] > arr[j])
           ans = max(ans, LDS(j,count,memo,arr) + 1);
    memo[i] = ans;
    return ans;
}

int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d",&count);
        int arr[count];
        for (int i = 0; i < count; i++) 
            scanf("%d",&arr[i]);
            
        int memoLIS[count];
        int memoLDS[count];
        memset(memoLIS,0,sizeof(memoLIS));
        memset(memoLDS,0,sizeof(memoLDS));
        for (int i = 0; i < count; i++){
            if (memoLIS[i] == 0)
               LIS(i,count,memoLIS,arr);
            if (memoLDS[i] == 0)
               LDS(i,count,memoLDS,arr);
        }
        
        int ans = 0;
        for (int i = 0; i < count; i++){
            int incDec = memoLIS[i] + memoLDS[i];
            if (incDec > ans)
               ans = incDec;
        }
              
        if (count > 0)
            printf("%d\n",ans-1);
        else
            printf("0\n");
    }
    
    system("pause");
    return 0;
}
