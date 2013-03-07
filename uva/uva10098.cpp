#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        char input[10];
        scanf("%s",&input);
        sort(input, input+strlen(input));
        printf("%s\n",input);

        map<string,int> seen;
        while(next_permutation(input, input+strlen(input))){
            string str = input;
            if(seen.find(str) == seen.end()){                
                printf("%s\n", input);
                seen[str] = 1;
            }
        }
        printf("\n");
    }
    
    return 0;
}
