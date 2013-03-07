#include <stdio.h>

int main(void){
    
    int count;
    while(true){
        scanf("%d",&count);
        if (count == 0)
           break;
           
        int input;
        bool found = false;
        for (int i = 0; i < count; i++){
            scanf("%d",&input);
            if (input != 0){               
               if (!found){
                  printf("%d",input);         
                  found = true;
               } else
                 printf(" %d",input);
            }
        }
        if (!found)
           printf("0\n");
        else
           printf("\n");
    }   
    
    return 0;
}
