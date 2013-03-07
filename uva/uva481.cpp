#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
    int next;
    int i, lis;
    int *A = new int[1000000];
    vector<int> arr, best;
    while(scanf("%d",&next) == 1){
        arr.push_back(next);
    }
    
    if (arr.size() == 1){
       printf("%d\n-\n",arr[0]);cin >> next;
       return 0;
    }
    
    for (A[0] = arr[0], i = lis = 1; i < arr.size(); i++) { // O(n)    
        int *l = upper_bound(A, A+lis, arr[i]); // find insertion point, O(log k)
        if (arr[i] != A[lis-1]){
            lis = max(lis, (int)(l - A) + 1);
            *l = arr[i];
            lis = (int)(l-A)+1;
        }
        if (lis >= best.size()){
           best.clear();
           for (int j = 0; j < lis; j++)
               best.push_back(A[j]);
        }
    }
    
    printf("%d\n-\n",best.size());
    
    for (int i = 0; i < best.size(); i++)
        printf("%d\n",best[i]);
    
    return 0;    
}
