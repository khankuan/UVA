#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    char input[300];
    int theseus,mino,k;
    while(true){
        scanf("%s",&input);
        if (input[0] == '#')
           break;
        char input1,input2, dummy;
        scanf("%c",&dummy);
        scanf("%c",&input1);
        scanf("%c",&dummy);
        scanf("%c",&input2);
        scanf("%c",&dummy);
        scanf("%d",&k);
        scanf("%c",&dummy);
        mino = input1;
        theseus = input2;
        
        int adjList[300][300];
        int adjSize[300];
        int litted[300];
        memset(adjSize,0,sizeof(adjSize));
        memset(litted,0,sizeof(litted));
        memset(adjList,0,sizeof(adjList));
        int i = 0;
        while (i < strlen(input)){
              
              int cur = (int) input[i];
              i += 2;
              int j = 0;
              while(input[i] != ';' && input[i] != '.'){
                  adjList[cur][j] = (int)input[i];
                  j++;
                  i++;
              }
              adjSize[cur] = j;
              i++;
        }
    
        int previousMino = -1, step = 0;
        while(true){
                    
            if (step % k == 0 && step != 0){
               printf("%c ",(char) theseus);
               litted[theseus] = 1;
            }
            bool canMove = false;
            for (int i = 0; i < adjSize[mino]; i++){
                if (litted[adjList[mino][i]] == 0 && theseus != adjList[mino][i]){
                   canMove = true;
                   previousMino = mino;
                   mino = adjList[mino][i];
                   break;
                }
            }
            if (!canMove)
               break;
            
            theseus = previousMino;
            step++;
        }
        
        printf("/%c\n",(char) mino);
        
    }
    return 0;
}
