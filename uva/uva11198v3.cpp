#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool primes[18] = {false,false,true,true,false,true,false,true,false,
                false,false,true,false,true,false,false,false,true};

char sourcememo[1 << 27];
char destmemo[1 << 27];

int toInt(vector<int> arr){
    int total = arr[0];
    for (int i = 1; i < 8; i++){
        total *= 10;
        total += arr[i];        
    }
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
        int sourceint = 0;
        if (source[0] < 0){           
           source[0] *= -1;
           isfemale[source[0]] = true;
        }
        sourceint += source[0];
        for (int i = 1; i < 8; i++){
            scanf("%d",&source[i]);
            if (source[i] < 0){
               source[i] *= -1;
               isfemale[source[i]] = true;
            }
            sourceint *= 10;
            sourceint += source[i];
        }
        
        if (sourceint == 12345678){
           printf("Case %d: 0\n",test);
           test++;
           continue;
        }
                 
        memset(destmemo,100,sizeof(destmemo));
        destmemo[12345678] = 0;
        queue<int> Qd;
        Qd.push(12345678);
        
        memset(sourcememo,100,sizeof(sourcememo));
        sourcememo[sourceint] = 0;
        queue<int> Qs;
        Qs.push(sourceint);
        
        int sourceMax = 1;     
        int destMax = 1;
        int allMax = 1;
        int ans = -1;
        bool found = false;
        while (!Qs.empty()){
              if (sourceMax <= allMax){  //  note: sourceMax will never be > allMax 
                  int next = Qs.front(); Qs.pop();
                  vector<int> arr;
                  
                  int x = next;
                  for (int i = 0; i < 8; i++){
                      arr.push_back(x % 10);
                      x /= 10;
                      //printf("%d ",arr[i]);
                  }//printf(" ]\n");
                  reverse(arr.begin(),arr.end());              
                  for (int i = 0; i < 8; i++){
                      if (!isfemale[arr[i]])
                         continue;
                      for (int j = 0; j < 8; j++){
                          if (!(isfemale[arr[j]])){
                              if (primes[arr[i]+arr[j]]){ //printf("%d %d\n",arr[i],arr[j]);
                                    int temp[4];
                                    temp[0] = i;
                                    temp[1] = i+1;     
                                    temp[2] = j;
                                    temp[3] = j+1;
                                    for (int k = 0; k < 4; k++){    
                                         if (temp[k] > -1 && temp[k] < 8){
                                              vector<int> temparr = arr;
                                              //printf("\nnext: %d weighted %d %d\n",next,sourcememo[next],destmemo[next]);
                                              if (k < 2 && temp[k] != j){ // moving j to i +- 1
                                                  //printf("moving j to i: %d %d\n",arr[j],arr[temp[k]]);
                                                  int insert = temparr[j];
                                                  temparr.erase(temparr.begin()+j,temparr.begin()+j+1);
                                                  if (temp[k] < j)
                                                      temparr.insert(temparr.begin()+temp[k],insert);
                                                  else
                                                      temparr.insert(temparr.begin()+temp[k]-1,insert);
                                              } else if (temp[k] != i){   // moving i +- 1 to j
                                                  //printf("moving i to j: %d %d\n",arr[i],arr[temp[k]]);
                                                  int insert = temparr[i];
                                                  temparr.erase(temparr.begin()+i,temparr.begin()+i+1);
                                                  if (temp[k] < i)
                                                      temparr.insert(temparr.begin()+temp[k],insert);
                                                  else
                                                      temparr.insert(temparr.begin()+temp[k]-1,insert);
                                              }
                                              /*
                                              for (int k = 0; k < 8; k++){
                                                  printf("%d ",temparr[k]);
                                              }printf(" +\n");
                                              */
                                              
                                              int newnode = toInt(temparr);
                                              //printf("after: %d\n",newnode);
                                              if (sourcememo[newnode] == 100)
                                                  sourcememo[newnode] = sourcememo[next]+1;
                                              else
                                                  continue;           //  did this state before already
                                                  
                                              if (destmemo[newnode] != 100){              
                                                  ans = sourcememo[newnode] + destmemo[newnode];
                                                  //printf("found: %d %d %d %d\n",next, newnode, sourcememo[newnode],destmemo[newnode]);
                                                  found = true;
                                                  break;
                                              } else {
                                                  sourceMax = max((int)sourceMax,(int)sourcememo[newnode]);
                                                  Qs.push(newnode);
                                              }
                                         }
                                         if (found)
                                             break;
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
              if (found)
                 break;
              
              
              if (destMax <= allMax && destMax < 3){  //  note: destMax will never be > allMax 
                  int next = Qd.front(); Qd.pop();
                  vector<int> arr;
                  
                  int x = next;
                  for (int i = 0; i < 8; i++){
                      arr.push_back(x % 10);
                      x /= 10;
                      //printf("%d ",arr[i]);
                  }//printf(" ]\n");
                  reverse(arr.begin(),arr.end());              
                  for (int i = 0; i < 7; i++){
                      if (!(primes[arr[i]+arr[i+1]]) || (isfemale[arr[i]] && isfemale[arr[i+1]]) || (!isfemale[arr[i]] && !isfemale[arr[i+1]]))
                         continue;//printf("%d %d\n",arr[i],arr[j]);
                      for (int j = 0; j < 2; j++){
                            for (int k = 0; k < 8; k++){
                                 if (k != i + j){
                                      vector<int> temparr = arr;
                                      //printf("\nnext: %d weighted %d %d\n",next,sourcememo[next],destmemo[next]);

                                      //printf("moving j to i: %d %d\n",arr[i+j],arr[k]);
                                      int insert = temparr[i+j];
                                      temparr.erase(temparr.begin()+i+j,temparr.begin()+i+j+1);
                                      if (k < i+j)
                                          temparr.insert(temparr.begin()+k,insert);
                                      else
                                          temparr.insert(temparr.begin()+k-1,insert);
                                      
                                      /*
                                      for (int k = 0; k < 8; k++){
                                          printf("%d ",temparr[k]);
                                      }printf(" +\n");
                                      */
                                      
                                      int newnode = toInt(temparr);
                                      //printf("after: %d\n",newnode);
                                      if (destmemo[newnode] == 100)
                                          destmemo[newnode] = destmemo[next]+1;
                                      else
                                          continue;           //  did this state before already
                                          
                                      if (sourcememo[newnode] != 100){              
                                          ans = destmemo[newnode] + sourcememo[newnode];
                                          //printf("found: %d %d %d %d\n",next, newnode, sourcememo[newnode],destmemo[newnode]);
                                          found = true;
                                          break;
                                      } else {
                                          destMax = max((int)destMax,(int)destmemo[newnode]);
                                          Qd.push(newnode);
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
                  if (found)
                      break;
              }
              if (found)
                 break;
              
              allMax = max(destMax,sourceMax);
        }
        printf("Case %d: %d\n",test,ans);
        //printf("%d ",ansI);
        //while(p[ansI] != -1){
         //   printf("%d ",p[ansI]);ansI = p[ansI];}printf("\n");
        test++;
    }
    return 0;
}
