#include <cstdio>
#include <iostream>
using namespace std;


int main(void){
    int n,a;
    while(scanf("%d %d",&n,&a) == 2){
       long long sum = 0;
       
       for (int i = 1; i < n+1 ;i++){
           long long total = i;
           for (int j = 0; j < i; j++)
               total *= a;
           sum += total;
       }
       
       cout << sum << endl;
    }
    
    return 0;
}
