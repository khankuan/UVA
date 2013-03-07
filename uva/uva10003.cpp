#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int arr[52];
int memo[52][52];

int cut(int left, int right) {
    if (left + 1 == right)       
       return 0;
    if (memo[left][right] != -1) 
       return memo[left][right];
    
    int ans = 1000000000;
    for (int i = left + 1; i < right; i++)
        ans = min(ans, cut(left, i) + cut(i, right) + (arr[right] - arr[left]));
    
    return memo[left][right] = ans;
}

int main(void){
    int length, n;
    
    while (scanf("%d", &length), length) {
          arr[0] = 0;
          scanf("%d", &n);
          for (int i = 1; i <= n; i++)
              scanf("%d", &arr[i]);
          arr[n + 1] = length;
    
          memset(memo, -1, sizeof memo);
          printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }

    return 0;
}
