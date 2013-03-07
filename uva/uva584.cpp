#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    
    char input[80];
    while(true){
        int total = 0;
        gets(input);
        if (strcmp(input,"Game Over") == 0)
           break;
        int strength[24];
        int score[24];
        for (int i = 0; i < 24; i++)
            strength[i] = 1;
        int i = 0;
        int rows = 0;
        while (true){
              if (input[i << 1] == 'X'){
                 score[i] = 10;
                 rows += 2;
                 if (rows <= 18){
                     strength[i+1]++;
                     strength[i+2]++;
                 }                
              } else if (input[i << 1] == '/'){
                 score[i] = 10 - score[i-1];
                 rows++;
                 if (rows <= 18)
                    strength[i+1]++; 
              } else{
                 rows++;
                 score[i] = (int)input[i << 1] - (int)'0';
                
              }
              i++;
              if (input[(i << 1) - 1] == '\0')
                 break;
        }
        for (int j = 0; j < i; j++)
            total += strength[j] * score[j];
            
        printf("%d\n",total);
    }
    
    system("pause");
    return 0;
}
