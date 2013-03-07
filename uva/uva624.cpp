#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pick(int bitmask, int curSum, int target, int count, int tracks[], int visited[], int* best, int* bestMask){
     if (visited[bitmask])
        return;
     visited[bitmask] = true;
     for (int i = 0; i < count; i++){
         if (!(bitmask & (1 << i))){
            int added = curSum + tracks[i];
            if (added <= target){
               if (added > *best){
               
                  *bestMask = (bitmask | (1 << i));
                  *best = added;
               }
               if (added < target)
                  pick((bitmask | (1 << i)), added,target,count,tracks,visited, best,bestMask);
            }
              
         }         
     }
}

int main(void){
    int target;
    while (scanf("%d",&target) == 1){
          int count;
          scanf("%d",&count);
          int tracks[count];
          int visited[1 << count];
          memset(visited,0,sizeof(visited));
          for (int i = 0; i < count; i++)
              scanf("%d",&tracks[i]);
              
          int bestMask = 0;
          int best = 0;
          
          pick(0,0,target,count,tracks,visited,&best,&bestMask);
          
          for (int i = 0; i < count; i++){
              if ((bestMask >> i) & 1)
                 printf("%d ",tracks[i]);
          }
          printf("sum:%d\n",best);
    }
    
    system("pause");
    return 0;
}
