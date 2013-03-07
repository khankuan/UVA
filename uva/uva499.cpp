#include <stdio.h>
#include <string.h>

int main(void){
    int count[52];
    int max = 0;
    memset(count, 0, sizeof(count));
    char current;

	while(1){            
        int check = scanf("%c",&current);  
        if (check != 1)
           break;
        if ((current >= 'a' && current <= 'z'))
    	   count[current-97+26]++;
        else if ((current >= 'A' && current <= 'Z'))
    	   count[current-65]++;
    	else if (current == '\n'){
             int max = 0;
             for (int i = 0; i < 52; i++)
                 if (count[i] > max)
                    max = count[i];
             for (int i = 0; i < 52; i++){
                 if (count[i] == max){
                    if (i < 26)
                       printf("%c",i+65);
                    else
                       printf("%c",i+97-26);
                 }
                 count[i] = 0;
             }
             printf(" %d\n",max);

        } 
    }

    return 0;
}
