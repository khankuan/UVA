#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

int main(void){
    int a,b;
    
    int sievesize = 5000001;
    bitset<5000005> isPrime;
    isPrime.set();
    vector<int> deprime;
    deprime.assign(sievesize,0);

	for (long long i = 2; i <= sievesize; i++){
		if (isPrime[i]){
            deprime[i] = i;
			for (long long j = i+i; j <= sievesize; j += i){
				   isPrime.reset(j);	
				   deprime[j] += i;
            }
		}
	}

	int total = 0;
	vector<int> sum;
	sum.push_back(0);
	sum.push_back(0);
    for (int i = 2; i < sievesize; i++){
        if (isPrime[deprime[i]])
           total++;
        sum.push_back(total);
    }
	    
    while(scanf("%d %d",&a,&b) == 2)
        printf("%d\n",sum[b] - sum[a-1]);        
    

    return 0;
}
