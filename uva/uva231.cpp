#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

#define MAX_N 200000

int main() {
    int i, lnis, n, X[MAX_N], A[MAX_N], caseNo = 1;
    bool first = true;
    
    while (1) {
        for (n = 0; scanf("%d", &X[n]), X[n] != -1; n++);
        if (X[0] == -1) 
           break;
        
        for (A[0] = X[0], i = lnis = 1; i < n; i++){
            int *l = upper_bound(A, A + lnis, X[i], greater<int>());
            lnis = max(lnis, (int)(l - A) + 1);
            *l = X[i];
        }
        
        if (!first) printf("\n");
           first = false;
           
        printf("Test #%d:\n", caseNo++);
        printf("  maximum possible interceptions: %d\n", lnis);
    }
    
    return 0;
}
