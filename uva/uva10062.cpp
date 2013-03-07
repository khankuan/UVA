#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;


int main(void){
    char input[2000]; 
    int len = 0;
    int first = 1;
    while(true){
               
        int check = scanf("%c",&input[len]);
        if (check != 1)
           break;
        if (input[len] == '\r' || input[len] == '\n'){
           input[len] = '\0';
        } else {
          len++;
          continue;
        }
                
        if (first == 0)
           printf("\n");
        else
          first = 0;
        int freq[300];
        memset(freq,0,sizeof(freq));
        for (int i = 0; i < strlen(input); i++)
            freq[(int)input[i]]++;        
        
        priority_queue<pair<int,int> > PQ;
        
        for (int i = 0; i < 300; i++){
            if (freq[i] != 0)
               PQ.push(make_pair(-freq[i],i));
        }
        
        while(!PQ.empty()){
            pair<int, int> output = PQ.top(); PQ.pop();
            printf("%d %d\n",output.second, -output.first);
        }
        len = 0;
        
    }
    return 0;
}
