#include <stdio.h>
#include <string.h>

void pick(int bitmask, int count, int sumCo, int toWinVotes, int party[], int wins[],bool visited[]){ 
     if (visited[bitmask])
        return;
     visited[bitmask] = true;
     for (int i = 0; i < count; i++){
         if (!(bitmask & (1 << i))){                
             if (sumCo + party[i] > toWinVotes)
                wins[i]++;
             else
                pick((bitmask | (1 << i)),count,sumCo + party[i],toWinVotes,party,wins,visited);
          }
     }
}

int main(void){
    int testcases;
    
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d", &count);
        int pass[1 << count];
        bool visited[1 << count];
        memset(pass,0,sizeof(pass));
        memset(visited,0,sizeof(visited));
        int party[count];
        int wins[count];
        int sumVotes = 0;
        for (int p = 0; p < count; p++){
            scanf("%d", &party[p]);
            sumVotes += party[p];
        }
    
        memset(wins,0,sizeof(wins));   

        pick(0,count,0,sumVotes >> 1,party,wins, visited);
       
        
        for (int i = 0; i < count; i++)
            printf("party %d has power index %d\n",i+1,wins[i]);
            
        printf("\n");
    }
    
    return 0;
}
