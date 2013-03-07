#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    long hashed_amount[256];
    char line[10001];
    int numlines;
    int count;
    int types;
    scanf("%d",&count);
    char input;
    int amount;
    for (int i = 0; i < count; i++){
        memset(hashed_amount, 0, sizeof(hashed_amount));  
        scanf("%d",&types);       
        scanf("%c",&input);
        for (int j = 0; j < types; j++){
            scanf("%c",&input);
            int value;
                if ((int)input < 0)
                   value = 256 + (int) input;
                else
                    value = (int) input;
            scanf("%d",&amount);
            hashed_amount[value] = amount;
            getchar();
        }        
       
        scanf("%d",&numlines);
        getchar();
        long dollars = 0;
        long cents = 0;
        for (int j = 0; j < numlines; j++){
            gets(line);
            for (int k = 0; k < strlen(line); k++){
                int value;
                if ((int)line[k] < 0)
                   value = 256 + (int)line[k];
                else
                    value = (int)line[k];
                cents += hashed_amount[value];
                if (cents > 100){
                   dollars += cents/100;
                   cents = cents%100;
                } 
            }     
        }
        

        printf("%ld.%02ld$\n",dollars,cents);
    }
    system("pause");
    return 0;
}
