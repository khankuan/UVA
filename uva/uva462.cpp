#include <stdio.h>
#include <stdlib.h>

int main(void){
    int size[4] = {0,0,0,0};
    char card[13][2];
    int points = 0;
    
    while(true){
        int check;
        bool exit = false;
        for (int i = 0; i < 13; i++){ 
            char current[2];     
            check = scanf("%2c",&current[0],&current[1]);
            card[i][0] = current[0];
            card[i][1] = current[1];
            if (current[1] == 'S')
               size[0]++;
            else if (current[1] == 'H')
               size[1]++;
            else if (current[1] == 'D')
               size[2]++;
            else 
               size[3]++;
            check = scanf("%c",&current[0]); 
        }
        if (check != 1)
           break;
           
        for (int i = 0; i < 13; i++){
            if (card[i][0] == 'A')
               points += 4;
            if (card[i][0] == 'K'){
               points += 3;
               if (card[i][1] == 'S' && size[0] == 1)
                  points--;
               else if (card[i][1] == 'H' && size[1] == 1)
                  points--;
               else if (card[i][1] == 'D' && size[2] == 1)
                  points--;
               else if (card[i][1] == 'C' && size[3] == 1)
                  points--;
            }
            else if (card[i][0] == 'Q'){
               points += 2;
               if (card[i][1] == 'S' && (size[0] == 1 || size[0] == 2))
                  points--;
               else if (card[i][1] == 'H' && (size[1] == 1 || size[1] == 2))
                  points--;
               else if (card[i][1] == 'D' && (size[2] == 1 || size[2] == 2))
                  points--;
               else if (card[i][1] == 'C' && (size[3] == 1 || size[3] == 2))
                  points--;
            }
            else if (card[i][0] == 'J'){
               points += 1;
               if (card[i][1] == 'S' && (size[0] == 1 || size[0] == 2 || size[0] == 3))
                  points--;
               else if (card[i][1] == 'H' && (size[1] == 1 || size[1] == 2 || size[1] == 3))
                  points--;
               else if (card[i][1] == 'D' && (size[2] == 1 || size[2] == 2 || size[2] == 3))
                  points--;
               else if (card[i][1] == 'C' && (size[3] == 1 || size[3] == 2 || size[3] == 3))
                  points--;
            }        
        }

        bool noTrump = true;
        if (points >= 16){
           bool stopped[4];
           for (int i = 0; i < 4; i++)
               stopped[i] = false;
           for (int i = 0; i < 13; i++){
               if (card[i][0] == 'A'){
                  if (card[i][1] == 'S')
                     stopped[0] = true;
                  else if (card[i][1] == 'H')
                     stopped[1] = true;
                  else if (card[i][1] == 'D')
                     stopped[2] = true;
                  else if (card[i][1] == 'C')
                     stopped[3] = true;
               } else if (card[i][0] == 'K'){
                  if (card[i][1] == 'S' && size[0] > 1)
                     stopped[0] = true;
                  else if (card[i][1] == 'H' && size[1] > 1)
                     stopped[1] = true;
                  else if (card[i][1] == 'D' && size[2] > 1)
                     stopped[2] = true;
                  else if (card[i][1] == 'C' && size[3] > 1)
                     stopped[3] = true;
               } else if (card[i][0] == 'Q'){
                  if (card[i][1] == 'S' && size[0] > 2)
                     stopped[0] = true;
                  else if (card[i][1] == 'H' && size[1] > 2)
                     stopped[1] = true;
                  else if (card[i][1] == 'D' && size[2] > 2)
                     stopped[2] = true;
                  else if (card[i][1] == 'C' && size[3] > 2)
                     stopped[3] = true;
               } 
           }
           for (int i = 0; i < 4; i++){
               if (!stopped[i]){
                  noTrump = false;
                  break;
               }
           }
           if (noTrump)
              printf("BID NO-TRUMP\n");
        } else
          noTrump = false;
        
        if (!noTrump){
             for (int i = 0; i < 4; i++){
                 if (size[i] == 2)
                    points++;
                 if (size[i] < 2)
                    points += 2;
             }
             if (points < 14)
                printf("PASS\n");
             else {
                  
                  int highest = 0;
                  for (int i = 1; i < 4; i++){
                      if (size[i] > size[highest])
                         highest = i;
                  }
                  if (highest == 0)
                     printf("BID S\n");
                  else if (highest == 1)
                     printf("BID H\n");
                  else if (highest == 2)
                     printf("BID D\n");
                  else
                     printf("BID C\n");
             }
        }
              
        
        for (int i = 0; i < 4; i++)
            size[i] = 0;  
        points = 0;
  
    }
    system("PAUSE");
    return 0;
}
