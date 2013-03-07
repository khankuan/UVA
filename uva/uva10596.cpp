#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(void){
    int V,E;
    while(scanf("%d %d",&V,&E) == 2){
           int degree[V];
           memset(degree,0,sizeof(degree));
           for (int i = 0; i < E; i++){
               int from,to;
               scanf("%d %d",&from,&to);
               degree[from]++;
               degree[to]++;
           }
           
           bool valid = true;
           for (int i = 0; i < V; i++){
               if (degree[i] % 2 == 1 || degree[i] == 0){
                  valid = false;
                  break;
               }
           }
           
           if (valid)
               printf("Possible\n");
           else
               printf("Not Possible\n");

    }
  
    return 0;

}
