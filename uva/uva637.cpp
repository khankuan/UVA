#include <stdio.h>
#include <stdlib.h>

int main(void){
    int input;
    while (true){
        scanf("%d",&input);
        if (input == 0)
           break;
        
        printf("Printing order for %d pages:\n",input);
        if (input % 4 == 0){
           printf("Sheet 1, front: %d, 1\n", input);
           printf("Sheet 1, back : 2, %d\n", input-1); 
           if (input > 4){  
               printf("Sheet 2, front: %d, 3\n", input-2);
               printf("Sheet 2, back : 4, %d\n", input-3);   
           }
        } else if (input % 4 == 1){
           printf("Sheet 1, front: Blank, 1\n");
           if (input > 1){
                printf("Sheet 1, back : 2, Blank\n");   
                printf("Sheet 2, front: Blank, 3\n");
                printf("Sheet 2, back : 4, %d\n", input);
           }
        } else if (input % 4 == 2){
           printf("Sheet 1, front: Blank, 1\n");
           printf("Sheet 1, back : 2, Blank\n"); 
           if (input > 2){ 
               printf("Sheet 2, front: %d, 3\n", input);
               printf("Sheet 2, back : 4, %d\n", input-1);
           }  
        } else {
           printf("Sheet 1, front: Blank, 1\n");
           printf("Sheet 1, back : 2, %d\n", input);
           if (input > 3){  
               printf("Sheet 2, front: %d, 3\n", input-1);
               printf("Sheet 2, back : 4, %d\n", input-2);
           } 
        }
        int padding = ((input+3) >> 2);
        for (int i = 2; i < padding; i++){
           printf("Sheet %d, front: %d, %d\n", i+1, (padding<<2) -( i << 1), (i << 1)+1);
           printf("Sheet %d, back : %d, %d\n", i+1, ((i+1) << 1), (padding<<2) - (i << 1)-1);        
        }
    
    }

    system("pause");
    return 0;
}
