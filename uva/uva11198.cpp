#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool primes[18] = {false,false,false,true,false,true,false,true,false,
                false,false,true,false,true,false,false,false,true};

int memo[1 << 26];

int toHash(int arr[8]){
    int total = 0;
    for (int i = 0; i < 8; i++)
        total += (arr[i]-1) << (3*i); 
    return total;
}

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
                  printf("%d ",arr[i]);
              }printf("\n");
              
              for (int i = 0; i < 8; i++){
                  if (!isfemale[arr[i]])
                     continue;
                  for (int j = 0; j < 8; j++){
                     if (!(isfemale[arr[j]])){
                        if (primes[arr[i]+arr[j]]){printf("%d %d\n",arr[i],arr[j]);
                           int state;
                           int temp[4];
                           temp[0] = i-1;
                           temp[1] = i+1;     
                           temp[2] = j-1;
                           temp[3] = j+1;
                           for (int k = 0; k < 4; k++){
                               if (temp[k] > -1 && temp[k] < 8){                                  
                                   if (k < 2)
                                       state = next - ((arr[j]-1)<<(3*j)) - ((arr[temp[k]]-1)<<(3*temp[k])) + ((arr[j]-1)<<(3*temp[k])) + ((arr[temp[k]]-1)<<(3*j));
                                   else
                                       state = next - ((arr[i]-1)<<(3*i)) - ((arr[temp[k]]-1)<<(3*temp[k])) + ((arr[i]-1)<<(3*temp[k])) + ((arr[temp[k]]-1)<<(3*i));
                                   int toflip = state - ((1-((state >> 25) & 1)) << 25);
                                   int y = state;printf("at: %d %d  moving to %d %d\n",i,j,k,temp[k]);
                                  for (int i = 0; i < 8; i++){
                                      int sarr = (y % 8)+1;
                                      y /= 8; 
                                      printf("%d ",sarr);
                                  }
                                  printf("\n");
                                   
                                   if (memo[toflip] != -1){
                                      ans = memo[toflip] + memo[next] + 1;
                                      found = true;
                                      break;
                                   } else {
                                      memo[state] = memo[next] + 1;
                                      Q.push(state);
                                   }
                               }
                           }
                        }
                     }
                      
                     if (found)
                         break;
                  }
                  if (found)
                     break;
              }
              if (found)
                 break;
        }
        printf("Case %d: %d\n",test,ans);
        test++;
    }
    return 0;
}
