#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void){
    
    int lifts, target;
    while(scanf("%d %d",&lifts, &target) == 2){
        vector<vector<pair<int,int> > > adjList;

        adjList.assign(10000,vector<pair<int,int> >());
        
        int liftsWeight[lifts];
        for (int i = 0; i < lifts; i++){
            int input;
            scanf("%d",&input);
            liftsWeight[i] = input;
        }
        getchar();
        
        bool seen[100];
        memset(seen,0,sizeof(seen));
        char input[500];
        for (int i = 0; i < lifts; i++){
            gets(input);
            int length = strlen(input);
            int sum = 0;
            int previous = -1;
            for (int j = 0; j < length; j++){
                if (input[j] == ' ' || j == length -1){
                   if (previous == -1){
                      previous = sum;
                      seen[previous] = true;
                      sum = 0;
                   }
                   else{
                        if (j == length -1){
                           sum *= 10;
                           sum += input[j] - '0';
                        }
                        int newP = previous+i*100;
                        int newS = sum+i*100;
                        if (previous == 0)
                           newP = 0;
                        if (sum == 0)   
                           newS = 0;
                        adjList[newP].push_back(make_pair(newS,liftsWeight[i] * (sum - previous)));
                        adjList[newS].push_back(make_pair(newP,liftsWeight[i] * (sum - previous)));
                        previous = sum;
                        seen[sum] = true;
                        sum = 0;
                        
                   }
                } else{
                  sum *= 10;
                  sum += input[j] - '0';
                }  
            }  
            
        }
       
        for (int i = 1; i < 100; i++){
            if (!seen[i])
               continue;
            for (int j = 0; j < lifts; j++){
                for (int k = j+1; k < lifts; k++){
                    adjList[i+j*100].push_back(make_pair(i+k*100,60));
                    adjList[i+k*100].push_back(make_pair(i+j*100,60));
                } 
            }
        }

        int SSSP[10000];
        for (int i = 0; i < 10000 ;i++)
            SSSP[i] = (1 << 31) - 1;
        
        priority_queue<pair<int,int> > PQ;
        PQ.push(make_pair(0,0));
        SSSP[0] = 0;
        while (!PQ.empty()){
              
              pair<int,int> edge = PQ.top(); PQ.pop();
              int v = edge.second;
              int weight = -edge.first;

              if (weight > SSSP[v])
                 continue;
              
              bool less = false;
              for (int i = 0; i < lifts; i++)                
                  if (weight > SSSP[target+i*100]){
                     less = true;        
                     break;
                  }
              if (less)
                 break;
                 

              for (int i = 0; i < adjList[v].size(); i++){
                 pair<int,int> next = adjList[v][i];
                 //printf("%d      %d    SSSP: %d    v:%d   size:%d     u: %d\n",-weight,weight+next.second,SSSP[next.first],next.first,adjList[next.first].size(),v);system("pause");
                    
                 if (weight + next.second < SSSP[next.first]){
                 
                    SSSP[next.first] = weight + next.second;
                    PQ.push(make_pair(-(next.second)-weight,next.first)); 
                 }  

               }
              
        }  
        
        int minSSSP = SSSP[target];
        for (int i = 1; i < 100; i++)
            minSSSP = min(minSSSP,SSSP[target +i*100]);
        if (minSSSP == (1 << 31) -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",minSSSP);

        
    }
    
    return 0;
}
