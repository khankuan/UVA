#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool primes[18] = {false,false,false,true,false,true,false,true,false,
                false,false,true,false,true,false,false,false,true};


int toHash(int arr[8]){
    int total = 0;
    for (int i = 0; i < 8; i++)
        total += (arr[i]-1) << (3*i); 
    return total;
}
int memo[1 << 26];
int main(void){
    int test = 1;
    int source[8];
    
    while(scanf("%d",&source[0]) == 1){
        if (source[0] == 0)
           break;
        
        bool isfemale[9];
        memset(isfemale,false,sizeof isfemale);
        if (source[0] < 0){           
           source[0] *= -1;
           isfemale[source[0]] = true;
        }
        for (int i = 1; i < 8; i++){
            scanf("%d",&source[i]);
            if (source[i] < 0){
               source[i] *= -1;
               isfemale[source[i]] = true;
            }
        }
        
        int hsource = toHash(source);
        if (hsource == 16434824){
           printf("Case %d: 0\n",test);
           test++;
           continue;
        }
        
        memset(memo,-1,sizeof(memo));
        memo[(1<<25)+hsource] = 0;
        memo[16434824] = 0;
               
        queue<int> Q;
        Q.push((1 << 25) + hsource);
        Q.push(16434824);
        
        int ans = -1;
        bool found = false;
        while (!Q.empty()){
              int next = Q.front(); Q.pop();
              int arr[9];
              
              int x = next;
              for (int i = 0; i < 8; i++){
                  arr[i] = x % 8+1;
                  x /= 8;
                  //printf("%d ",arr[i]);
              }//printf(" ]\n");
              
              for (int i = 0; i < 8; i++){
                  if (!isfemale[arr[i]])
                     continue;//printf("spec: %d %d\n",memo[next],i);
                  for (int j = 0; j < 8; j++){
                     if (!(isfemale[arr[j]])){
                        if (primes[arr[i]+arr[j]]){ //printf("%d %d\n",arr[i],arr[j]);
                           
                           int temp[4];
                           temp[0] = i;
                           temp[1] = i+1;     
                           temp[2] = j;
                           temp[3] = j+1;
                           for (int k = 0; k < 4; k++){
                               int state = next;
                               if (temp[k] > -1 && temp[k] < 8){                         
                                   if (k < 2 && temp[k] != j){
                                       int block;
                                       int finalblock;
                                       int finalpointer; 
                                       int pointer = ((arr[j]-1)<<(3*j));
                                       if (temp[k] < j){
                                           block = (((next %(1 << (3*j))) >> (3*temp[k]))) << (3*temp[k]); 
                                           finalblock = block << 3;   
                                           finalpointer = pointer >> (3*(j-temp[k]));
                                       } 
                                       else {
                                           block = (((next %(1 << (3*temp[k]))) >> (3*j))) << (3*j);
                                           finalblock = block >> 3;
                                           finalpointer = pointer << (3*(temp[k]-j));
                                       }     
                                       state = state - block - pointer + finalpointer + finalblock;         
                                   } else if (k > 1 && temp[k] != i){
                                       int block;
                                       int finalblock;
                                       int finalpointer; 
                                       int pointer = ((arr[i]-1)<<(3*i));
                                       if (temp[k] < i){
                                           block = (((next %(1 << (3*i))) >> (3*temp[k]))) << (3*temp[k]); 
                                           finalblock = block << 3;   
                                           finalpointer = pointer >> (3*(i-temp[k]));
                                       } 
                                       else {
                                           block = (((next %(1 << (3*temp[k]))) >> (3*i))) << (3*i);
                                           finalblock = block >> 3;
                                           finalpointer = pointer << (3*(temp[k]-i));
                                       }      
                                       state = state -  block - pointer + finalblock + finalpointer;  
                                   } 
                                   int toflip = state^(1<<25);
                                   
                                   
                                   printf("%d\n",toflip);
                                   if (memo[toflip] != -1){
                                      ans = memo[toflip] + memo[next] + 1;
                                      found = true;//printf("breaking..\n");printf("state: %d, toflip: %d\n",state,toflip);
                                      break;
                                   } else if (memo[state] == -1){
                                          
                                      memo[state] = memo[next] + 1;
                                      /*
                                      int y = state;//printf("numbers: %d %d  moving to position %d, toflip: %d\n",arr[i],arr[j],temp[k]+1,toflip);
                                        for (int h = 0; h < 8; h++){
                                            int sarr = (y % 8)+1;
                                            y /= 8; 
                                            printf("%d ",sarr);
                                        }
                                       printf("\n");
                                        printf("memo: %d\n",memo[state]);
                                      */
                                      Q.push(state);
                                   }
                               }
                               if (found)
                                  break;
                           }
                           
                        }
                     }
                      
                     if (found)
                         break;
                  }//printf("i: %d\n",i);
                  if (found)
                     break;//printf("i: %d\n",i);
              }
              if (found)
                 break;
        }
        printf("Case %d: %d\n",test,ans);
        test++;
    }
    return 0;
}
