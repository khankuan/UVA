#include <cstdio>
#include <iostream>
using namespace std;

long long bigMod(long b,long p,long m) {
      if (p == 0)
        return 1;
      else if (p % 2 == 0) {
         long temp = bigMod(b,p/2,m)%m;
         return (temp * temp) % m;
      }
      else
        return ((b % m) * bigMod(b,p-1,m)) % m;
}

int main(void){
    long long B,P,M;
    while(cin >> B >> P >> M){
       cout << bigMod(B,P,M) << endl;
    }

    return 0;
}
