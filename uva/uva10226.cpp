#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void){
    
    int testcount;
    scanf("%d", &testcount);
    getchar();
    getchar();
    for (int test = 0; test < testcount; test++){
        string input;
        map<string, int> freq;
        int tcount = 0;
                
        while(true){
            getline(cin, input);
            if (input.length() == 0)
               break;
            if (freq.count(input) == 0)
               freq[input] = 1;
            else
               (*freq.find(input)).second++;
            tcount++;
        }
                
        map<string,int>::iterator it;
        for (it = freq.begin(); it != freq.end(); it++){
            cout << (*it).first;
            printf(" %.4lf\n", 100*(*it).second/(tcount + 0.0));
        }
        if (test != testcount - 1)
           printf("\n");
    
    }
    
    system("pause");
    return 0;
}
