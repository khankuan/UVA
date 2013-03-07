#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int,bool> memoPrime;

bool isPrime(int x){
     if (x < 2)
        return false;
     if (memoPrime.find(x) != memoPrime.end())
        return memoPrime[x];
     bool yes = true;
     for (int i = 2; i*i-1 <= x; i++){
         if (x % i == 0){
            yes = false;
            break;
         }
     }
     memoPrime[x] = yes;
     return yes;
}


int main(void){

    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test< testcases; test++){
        int count;
        scanf("%d",&count);
        int arr[count];
        for (int i = 0; i < count; i++)
            scanf("%d",&arr[i]);
            
        vector<int> sum;
        int total = 0;
        for (int i = 0; i < count; i++){
            total += arr[i];
            sum.push_back(total);
        }
        
        bool found = false;
        for (int length = 2; length < count; length++){
            for (int at = length-1; at < count; at++){
                int cursum = sum[at];
                if (at-length >= 0)
                   cursum -= sum[at-length];

                if (isPrime(cursum)){
                   found = true;
                   printf("Shortest primed subsequence is length %d:",length);
                   for (int i = 0; i < length; i++)
                       printf(" %d",arr[at-length+1+i]);
                   printf("\n");
                   break;
                }
            }
            if (found)
               break;
        }
        if (!found)
           printf("This sequence is anti-primed.\n");
        
    }

    return 0;
}
