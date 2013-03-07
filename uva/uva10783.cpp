#include <cstdio>
#include <cstdlib>
using namespace std;


int main(void){

	int testcases;
	scanf("%d",&testcases);
	for (int test = 0; test < testcases; test++){
		int one, two;
		scanf("%d %d",&one,&two);
		if (one > two){
           int temp = two;
           two = one;
           one = two;
        }
        if (one % 2 == 0)
           one++;	
        if (two % 2 == 0)
           two--;
        printf("Case %d: %d\n",test+1,(one+two)/2*((two-one)/2+1));
	}
    
	return 0;
}
