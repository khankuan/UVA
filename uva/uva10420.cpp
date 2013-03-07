#include <cstdio>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;


int main(void){
    map<string,int> country;
    
    int count;
    scanf("%d",&count);
    for (int i = 0; i < count; i++){
        char input[100], dummy[100];
        scanf("%s",&input);       
        string inputstr = input;
        gets(dummy);
        country[inputstr]++;
    }
    
    map<string,int>::iterator it;
           for (it = country.begin(); it != country.end(); it++)
               cout << (*it).first << " " << (*it).second << endl;
    
    system("pause");
    return 0;
}
