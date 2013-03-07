#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    while(true){
        bool taken[28];
        int k;
        scanf("%d",&k);
        if (k == 0)
           break;
        if (k == 1){
           printf("2\n");
           continue;
        }
        bool found = false;
        for (int i = k; i < 10000000; i++){
            if (i%(k<<1) < k)
               i += k;
            memset(taken,0,sizeof(taken));
            taken[i%(k<<1)] = true;
            int tookCount = 1;
            int current = i;
            while (true){
                  for (int j = 0; j < i%((k<<1)-tookCount) + 1; j++){   
                      current++;
                      while (taken[current%(k<<1)] == true){
                         current++;
                      }
                  }
                  
                  printf("%d %d %d\n",i+1, current%(k<<1)+1,tookCount);
                  if (current%(k<<1) < k)
                     break;
                  taken[current%(k<<1)] = true;                  
                  tookCount++;
                  
                  if(tookCount == k){
                      printf("%d\n",i+1);
                      found = true;
                      break;
                  }
            }
            if (found)
               break;
        }
    }
    system("pause");
    return 0;
}

/*
// Solution exceeds time limit..
#include <stdio.h>
int Val[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
    int N;
    while(scanf("%d",&N) && N)
    {
          printf("%d\n",Val[N]);       
    }
    return 0;
}


*/
