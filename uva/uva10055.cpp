#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    long long one,two;
    
    while(cin >> one){
        cin >> two;
        if (two > one)
           cout << two-one << endl;
        else
           cout << one-two << endl;
    }
    return 0;
}
