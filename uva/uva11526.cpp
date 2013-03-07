#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long H(int n){
    long long res = 0;
    int st = sqrt(n);
    for( int i = 1; i <= st; i++ )
         res += n/i;
    res = 2*res - st*st;
    return res;
} 

int main(void){
    int testcases;
    scanf("%d",&testcases);
    int input;
    for (int test = 0; test < testcases; test++){
        scanf("%d",&input);
        cout << H(input) << endl;
    }
    return 0;
}
