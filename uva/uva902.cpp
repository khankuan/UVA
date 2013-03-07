#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(void){
    int count;
    char dummy;
    while(true){
        if (scanf("%d",&count) != 1)
           break;
        scanf("%c",&dummy);
        string str;
        getline(cin,str);
        map<string,int> freq;
        for (int i = 0; i < str.length()-count; i++){
            string pw = str.substr(i,count);
            if (freq.find(pw) == freq.end())
                freq[pw] = 1;
            else
                freq[pw] = freq[pw] +1;
        }
        
        map<string,int>::iterator it;
        int max = 0;
        string maxstr;
        for ( it=freq.begin() ; it != freq.end(); it++ ){
            if ((*it).second >= max){
               max = (*it).second;
               maxstr = (*it).first;
            }
        }
        cout << maxstr << endl;   
    }

}
