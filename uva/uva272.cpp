#include <stdio.h>

int main(void){
	char current;
	bool isLeft = true;
	while(1){
        int check = scanf("%c",&current);  
        if (check != 1)
           break;                        
		if (current == '"'){
			if (isLeft){
				printf("``");
				isLeft = false;
			} else {
				printf("''");
				isLeft = true;
			}
		} else
			printf("%c",current);
	}
   return 0;
}
