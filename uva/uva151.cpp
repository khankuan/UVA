#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    
    
    while(true){
        bool taken[100];
        int regions;
        scanf("%d",&regions);
        if (regions == 0)
           break;
        if (regions == 13){
           printf("1\n");
           continue;
        }
        
        bool found = false;
        for (int i = 3; i < 100000; i += 1){
            memset(taken,0,sizeof(taken));
            taken[0] = true;
            int tookCount = 1;
            int current = 0;
            while (true){
                  for (int j = 0; j < i; j++){   
                      current++;
                      while (taken[current%regions] == true){
                         current++;
                      }
                  }
                  taken[current%regions] = true;
                  tookCount++;
                  if (taken[12] == false){
                      if(tookCount == regions - 1){
                          printf("%d\n",i);
                          found = true;
                          break;
                      }
                  } else
                    break;
            }
            if (found)
               break;
        }
    }
    
    return 0;
}
